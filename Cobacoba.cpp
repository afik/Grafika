#include<GL/glut.h>
#include<cmath>
#include<cctype>
 
GLint screen_height=600;
GLint screen_width=600;
int brush_size=10;
 
// Fungsi untuk menghapus buffer menghasilkan layar kosong
void free_dots(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
 
// Fungsi untuk menggambarkan titik pada layar di posisi (x,y)
void point(GLint x, GLint y){
    glBegin(GL_POINTS);
        glColor3f(0,0,0);
        glVertex2d(x,y);
    glEnd();
    glFlush();
}
 
// Fungsi yang menghandle transformasi ukuran windows
void reshape(GLsizei w, GLsizei h){
    screen_width=w;
    screen_height=h;
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
    glViewport(0,0,w,h);
}
 
// Fungsi yang menghandle mouse input
void my_mouse(int button, int state, int x, int y){
 
    if((button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN)){
        point(x,screen_height-y);
    }
    else if((button==GLUT_RIGHT_BUTTON)&&(state==GLUT_DOWN)){
		// Clear buffer yang menampilkan gambar saat ini
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }
}
 
// Fungsi yang menghandle keyboard input
void keyboard(unsigned char key, int x, int y){
    if(tolower(key)=='r'){ 
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,0.0);
        }
    else if(tolower(key)=='g'){
        glColor3f(0,1.0,0);
        }
    else if(tolower(key)=='b'){
        glColor3f(0,0,1.0);
    }
    else if(tolower(key)=='y'){ 
        glColor3f(1.0,1,0);
    }
    else if(tolower(key)=='m'){
        glColor3f(1,0,1);
    }
    else if(tolower(key)=='c'){
        glColor3f(0,1,1);
    }
    else{
        glColor3f(1,1,1);
    }
 
}
 
// Fungsi yang menghandle menggerakkan kursor
void moving_cursor(int x, int y){
    GLint mx=x, my=screen_height - y;
    glRecti(mx, my, mx+brush_size, my+brush_size);
    glFlush();
}

void init(){
	// Setting background color window 
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glColor3f(0.0f,0.0f,0.0f);
	// Setting ukuran titik yang didraw
    glPointSize(1);
 
	// Setting view kamera dengan proyeksi ortogonal
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,screen_width,0,screen_height);
}
 
int main(int argc,char **argv){
	// Setting screen program (ukuran, posisi, mode display)
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(60,60);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Color Freehand Drawing");
     
	// Fungsi untuk men-handle input luar
    glutDisplayFunc(free_dots);
    glutMouseFunc(my_mouse);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(moving_cursor);
     
	// Fungsi yang membuat windows dapat diresize
    glutReshapeFunc(reshape);
     
	// Membuat loop utama menunggu event handler
    init();
    glutMainLoop();
}