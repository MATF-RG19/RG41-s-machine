#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <unistd.h>
#include "slotFunction.hpp"
#include "image.h"

using namespace std;

//"vockice mi zivot upropastile"
enum Fruits{ananas, dolar, e, grozdje, kockica, limun, lubenica, spin, tresnjice};
//dohvatamo rezultat jednog pokretanja
Fruits f1;
Fruits f2;
Fruits f3;
Fruits f4;
Fruits f5;
Fruits f6;

#define ANANAS "images/ananas.bmp" //x5
#define DOLAR "images/dolar.bmp" //x250 
#define E "images/e.bmp" //x500
#define GROZDJE "images/grozdje.bmp" //x10
#define KOCKICA "images/kockica.bmp" //x100 
#define LIMUN "images/limun.bmp" //x15
#define LUBENICA "images/lubenica.bmp" //x20
#define SPIN "images/spin.bmp" //x50
#define TRESNJICE "images/tresnjice.bmp" // x25

#define WATCHRESULT 1000000 
static int money;
static int bet;
static void writeResultForSlotShot();

static int calculateScore();
static int globalScore = 1;

void initTextures();
GLuint images[9];


void postSlots(vector<int> &numImages){

    initTextures();
    if(numImages.size() >= 1){
        /*prvi red prva kolona*/
        f1 = Fruits(numImages[0]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[0]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(2.32, 5, 1);

        glTexCoord2f(1, 0);
        glVertex3d(2.67,5,1);

        glTexCoord2f(1, 1);
        glVertex3d(2.67,5.3,1);

        glTexCoord2f(0, 1);
        glVertex3d(2.32,5.3,1);
        glEnd();
    }
    if(numImages.size() >= 2){    
        /*drugi red prva kolona*/
        f2 = Fruits(numImages[1]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[1]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(2.32, 4.65, 1);

        glTexCoord2f(1, 0);
        glVertex3d(2.67,4.65,1);

        glTexCoord2f(1, 1);
        glVertex3d(2.67,4.95,1);

        glTexCoord2f(0, 1);
        glVertex3d(2.32,4.95,1);
        glEnd();
    }
    if(numImages.size() >= 3){
        /*prvi red druga kolona*/
        f3 = Fruits(numImages[2]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[2]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(2.85, 5, 1);

        glTexCoord2f(1, 0);
        glVertex3d(3.15,5,1);

        glTexCoord2f(1, 1);
        glVertex3d(3.15,5.3,1);

        glTexCoord2f(0, 1);
        glVertex3d(2.85,5.3,1);
        glEnd();
        
    }
    if (numImages.size() >= 4){
        /*drugi red druga kolona*/
        f4 = Fruits(numImages[3]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[3]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(2.85, 4.65, 1);

        glTexCoord2f(1, 0);
        glVertex3d(3.15,4.65,1);

        glTexCoord2f(1, 1);
        glVertex3d(3.15,4.95,1);

        glTexCoord2f(0, 1);
        glVertex3d(2.85,4.95,1);
        glEnd();
    }

    if(numImages.size() >= 5){
        /*prvi red treca kolona*/
        f5 = Fruits(numImages[4]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[4]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(3.35, 5, 1);

        glTexCoord2f(1, 0);
        glVertex3d(3.7,5,1);

        glTexCoord2f(1, 1);
        glVertex3d(3.7,5.3,1);

        glTexCoord2f(0, 1);
        glVertex3d(3.35,5.3,1);
        glEnd();
    }

    bool t= false;
    if(numImages.size() == 6){
        /*drugi red treca kolona*/
        f6 = Fruits(numImages[5]);
        glBindTexture(GL_TEXTURE_2D, images[numImages[5]]);
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3d(3.35, 4.65, 1);

        glTexCoord2f(1, 0);
        glVertex3d(3.7,4.65,1);

        glTexCoord2f(1, 1);
        glVertex3d(3.7,4.95,1);

        glTexCoord2f(0, 1);
        glVertex3d(3.35,4.95,1);
        glEnd();

        globalScore = calculateScore();
        writeResultForSlotShot();
    }

    if (numImages.size() == 7){
        /*BITAN DEO!
        Svih 6 slicica kao i rezultat, postavljeno je vec u sestom koraku, ali se ceka
        naknadni glutPostRedisplay kako bi se sve iscrtalo, zato moramo da imamo sedmi korak
        koji pamti sve rezultate.
        Nakon toga uspavljujemo program, i ocitavamo rezultat.
        */
        usleep(WATCHRESULT);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}


int calculateScore(){

    int score = 1;
    /*Za svaku kombinaciju povecavamo dobitni skor*/
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::ananas) || (f2 == f4 && f4 == f6 && Fruits::ananas))
        score *= 5;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::dolar) || (f2 == f4 && f4 == f6 && Fruits::dolar))
        score *= 250;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::e) || (f2 == f4 && f4 == f6 && Fruits::e))
        score *= 500;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::grozdje) || (f2 == f4 && f4 == f6 && Fruits::grozdje))
        score *= 10;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::kockica) || (f2 == f4 && f4 == f6 && Fruits::kockica))
        score *= 100;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::limun) || (f2 == f4 && f4 == f6 && Fruits::limun))
        score *= 15;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::lubenica) || (f2 == f4 && f4 == f6 && Fruits::lubenica))
        score *= 20;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::spin) || (f2 == f4 && f4 == f6 && Fruits::spin))
        score *= 50;
    if ((f1 == f3 && f3 == f5 && f5 == Fruits::tresnjice) || (f2 == f4 && f4 == f6 && Fruits::tresnjice))
        score *= 25;

    return score;
}


void writeMoney() {

    string s = "Money = " + to_string(money);
	
    glColor3f(0.96,0.96,0.96);
    glRasterPos3f(3,4.75,3);
    
    for( char c : s ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }

    glColor3f(0.96,0.96,0.96);
    glRasterPos3f(3.1, 4.7, 3);
    
    string s1 = "BET = " + to_string(bet);
    for( char c : s1 ) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

}


void writeResultForSlotShot() {
	
    int result;
    string s;
    
    if (globalScore == 1){
        /*Score je nepromenje, znaci nista nismo dobili*/
        money -= bet;
        result = -bet;
        s = "Res: " + to_string(result);
    }
    else{
        /*Dobitak*/
        money += bet*globalScore;
        result = bet*globalScore;
        s = "Res: +" + to_string(result);
    }
	
    glColor3f(0.96,0.96,0.96);
    glRasterPos3f(2.75,4.75,3);

    for( char c : s ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }
}

void setMoney(int m){
    money = m;
}
void setBet(int b){
    bet = b;
}

int getMoney(){
    return money;
}

void initTextures(){
    Image * image;

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);
    
    image = image_init(0, 0);

    glGenTextures(9, images);    

    image_read(image, ANANAS);
    glBindTexture(GL_TEXTURE_2D, images[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    image_read(image, DOLAR);
    glBindTexture(GL_TEXTURE_2D, images[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    image_read(image, E);
    glBindTexture(GL_TEXTURE_2D, images[2]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    
    image_read(image, GROZDJE);
    glBindTexture(GL_TEXTURE_2D, images[3]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    
    image_read(image, KOCKICA);
    glBindTexture(GL_TEXTURE_2D, images[4]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    image_read(image, LIMUN);
    glBindTexture(GL_TEXTURE_2D, images[5]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    

    image_read(image, LUBENICA);
    glBindTexture(GL_TEXTURE_2D, images[6]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    image_read(image, SPIN);
    glBindTexture(GL_TEXTURE_2D, images[7]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    image_read(image, TRESNJICE);
    glBindTexture(GL_TEXTURE_2D, images[8]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);
}