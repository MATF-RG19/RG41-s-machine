#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include "drawFunction.hpp"
#include "slotFunction.hpp"
#include "irrKlangLib/include/irrKlang.h"

using namespace std;

using namespace irrklang;
#pragma comment (lib, "irrKlangLib/lib");
ISoundEngine* engine;


vector<int> numImages;

static bool timerActive = false;
static double goCamX = 0;
static double goCamY = 0;
static double goCamZ = 0;

static bool programStarted = false;
static bool slotWorks = false;
static int stepForSlot = 0;
static int randomImage;
static void whileSlotWorks(int);

static int money;
static int bet;

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

    glClearColor(0.05, 0.05, 0.05, 0);
    glEnable(GL_DEPTH_TEST);

    srand(time(NULL));

    /*
    cout << "Unesite iznos vaseg novca" << endl;
    cin >> money;
    cout << "Unesite zeljeni BET. Moguce vrednosti [1, 5, 10, 50, 100]" << endl;
    cin >> bet;
    */

    engine = createIrrKlangDevice(); //kreiranje zvuka
    engine->play2D("irrKlangLib/media/music.mp3", true); //pustanje zvuka
    
    money = 1000;
    bet = 10;
    setMoney(money);
    setBet(bet);

    glutMainLoop();

    return 0;
}

void on_display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(12.0-goCamX,8.0-goCamY,9.0-goCamZ+1,0+goCamY,2+goCamY,0, 0,1,0);

    lightInit();
    drawMan();
    drawSlotMachine(slotWorks);

    if(!programStarted) pressS();
    if(programStarted) writeMoney();

    if(slotWorks) postSlots(numImages);

    glutSwapBuffers();
}

void on_keyboard(unsigned char c , int x , int y) {

    switch (c){
        case 27:
            engine->drop(); //oslobadjanje zvuka
            exit(0);
        case 's':
        	/*Pokrecemo program, kamera se premesta u glavu igraca*/
            if (!timerActive) {
                glutTimerFunc(10, on_timer, 0);
                timerActive = true;
            }
            break;
        case 32:
        	/*Na space pokrecemo slot masinu ali tek nakon sto je program pokrenut*/
            if(getMoney() < bet){
                engine->drop();
                exit(0);
            }

            if (programStarted && !slotWorks){
                slotWorks = true;
                stepForSlot = 0;
                glutTimerFunc(50, whileSlotWorks, 0);
            }

            break;
       case 'r':
       		/*Podizemo novac, i jedino sto nam preostaje jeste da izadjemo iz igrice*/
       		setMoney(0);
       		slotWorks = false;
       		glutPostRedisplay();
       		break;       
    }
}

void whileSlotWorks(int value){
    if(value !=0)
        return;
        
    randomImage = rand() % 9;
    numImages.push_back(randomImage);

    glutPostRedisplay();

    stepForSlot++;
    if (stepForSlot <= 7)
        glutTimerFunc(70, whileSlotWorks, 0);
    else{
        slotWorks = false;
        numImages.clear();
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

static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 1500);
}
