#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include "drawFunction.h"
#include "slotFunction.h"
using namespace std;


vector<int> numImages; //from slotFunction.h

static int timer_active;
static double goCamX = 0;
static double goCamY = 0;
static double goCamZ = 0;

static bool programStarted = false;
static bool slotWorks = false;
static int stepForSlot = 0;
static int randomImage;
static void whileSlotWorks(int);




static int money = 1000;
static int bet = 200;
static void writeMoney();


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

    srand(time(NULL));
    

    //printf("Unesite vrednost ulozenog novca:\n");
    //scanf("%d", &money);
    //printf("Unesite BET koji zelite:\n");
    //scanf("%d", &bet);

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
    //gluLookAt(12,8,8,0,2,0, 0,1,0);
    gluLookAt(12.0-goCamX,8.0-goCamY,9.0-goCamZ+1,0+goCamY,2+goCamY,0, 0,1,0);
    //gluLookAt(3,5,4,3,5,0,0,1,0);

    drawCoordSystem();
    lightInit();
    drawMan();
    drawSlotMachine(slotWorks);
    writeMoney();

    if(slotWorks) postSlots(numImages);

    glutSwapBuffers();
}

void on_keyboard(unsigned char c , int x , int y) {

    switch (c){
        case 27:
            exit(0);
            break;
        case 's':
            if (!timer_active) {
                glutTimerFunc(10, on_timer, 0);
                timer_active = 1;
            }
            break;
        case 32:
            if (money <= 0)
                exit(EXIT_SUCCESS);

            if (programStarted && !slotWorks){
                slotWorks = true;
                stepForSlot = 0;
                glutTimerFunc(100, whileSlotWorks, 0);
                money -= bet;
            }
    }
}

void on_timer(int value) {
    if(value != 0)
        return;

    goCamX += 0.5;
    goCamZ += 0.33;
    goCamY += 0.165;
    glutPostRedisplay();

    if (goCamX < 9)
      glutTimerFunc(10, on_timer, 0);
    else
        programStarted = true;
}

void whileSlotWorks(int value){
    if(value !=0)
        return;

    randomImage = rand() % 9;
    numImages.push_back(randomImage);

    glutPostRedisplay();

    stepForSlot++;
    if (stepForSlot <= 6)
        glutTimerFunc(200, whileSlotWorks, 0);
    else{
        slotWorks = false;
        numImages.clear();
    }
}

void writeMoney() {
    string s = "Money = " + to_string(money);

    glColor3f(0.96,0.96,0.96);
    glRasterPos3f( 3,4.75,3);

    if(!programStarted) return;

    for( char c : s ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }

}
