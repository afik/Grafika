#ifndef _BUFFER_H
#define _BUFFER_H
#include <unistd.h>
#include <fcntl.h>		/* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>		/* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Buffer{
	public:
		Buffer();
		~Buffer();
		
		void closeBuffer();
		void setLocation(int x, int y);
		
		long int getScreenSize();
		fb_var_screeninfo getVinfo();
		fb_fix_screeninfo gerFinfo();
		int getFbfd();
		char* getFbp();
		int getLocation();
	private:
		long int screensize;
		struct fb_var_screeninfo vinfo;
		struct fb_fix_screeninfo finfo;
		int fbfd;						/* frame buffer file descriptor */
		char* fbp;						/* pointer to framebuffer */
		int location;					/* iterate to location */
};

#endif
