#include "buffer.h"

Buffer::Buffer()
{
	fbfd = open("/dev/fb0",O_RDWR);
	if (!fbfd) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}
	if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	/* figure out the size of the screen in bytes */
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	/* map the device to memory */
	fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	location = 0;
}

Buffer::~Buffer()
{
	
}

void Buffer::closeBuffer() 
{
	munmap(fbp, screensize);
	close(fbfd);
}

void Buffer::setLocation(int x, int y)
{
	location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
}
		
long int Buffer::getScreenSize()
{
	return screensize;
}

fb_var_screeninfo Buffer::getVinfo()
{
	return vinfo;
}

fb_fix_screeninfo Buffer::gerFinfo()
{
	return finfo;
}

int Buffer::getFbfd()
{
	return fbfd;
}

char* Buffer::getFbp()
{
	return fbp;
}

int Buffer::getLocation()
{
	return location;
}
