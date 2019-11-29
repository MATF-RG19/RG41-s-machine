#include <iostream>
#include<GL/glut.h>
#include "drawFunction.cpp"
using namespace std;

static float window_width=0, window_height=0;
static int timer_active;
static double goCamX=0;
static double goCamY=0;
static double goCamZ=0;


static void on_display(void);
static void on_keyboard(unsigned char, int, int);
static void on_reshape(int, int);
static void on_timer(int);


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SLOT-MACHINE");

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);


    glClearColor(0.10, 0.10, 0.10, 0);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}



static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 1500);
}

void on_display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /*3,5,3,3,5,0,0,1,0 Pogled u ekran*/
    /*10,8,7,0,0,0, 0,1,0 Ulazni pogled*/
    /*12,8,8,0,2,0, 0,1,0*/
    gluLookAt(12.0-goCamX,8.0-goCamY,9.0-goCamZ,0+goCamY,2+goCamY,0, 0,1,0);
    //gluLookAt(3,5,3,3,5,0,0,1,0);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex3d(0,0, 0);
        glVertex3d(7,0,0);
        glVertex3d(0,0, 0);
        glVertex3d(0,7,0);
        glVertex3d(0,0, 0);
        glVertex3d(0,0,7);
    glEnd();


    drawMan();
    drawSlotMachine();
    glutSwapBuffers();
    
}

void on_keyboard(unsigned char c , int x , int y) {

    switch (c){
        case 27:
            exit(0);
            break;
        case 's':
            if (!timer_active) {
                glutTimerFunc(50, on_timer, 0);
                timer_active = 1;
            }
            break;
    }
}

static void on_timer(int value) {
    if(value != 0)
        return;

    goCamX += 1;
    goCamZ += 0.66;
    goCamY += 0.33;
    cout << goCamX<< " " << goCamY << " " <<  goCamZ << " " <<endl;
    glutPostRedisplay();

    if (goCamX < 9)
      glutTimerFunc(50, on_timer, 0);
}