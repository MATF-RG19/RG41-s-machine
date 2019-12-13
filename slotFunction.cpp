#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "slotFunction.hpp"
#include "image.h"

using namespace std;

#define ANANAS "images/ananas.bmp" 
#define DOLAR "images/dolar.bmp" 
#define E "images/e.bmp" 
#define GROZDJE "images/grozdje.bmp"
#define KOCKICA "images/kockica.bmp" 
#define LIMUN "images/limun.bmp" 
#define LUBENICA "images/lubenica.bmp"
#define SPIN "images/spin.bmp"
#define TRESNJICE "images/tresnjice.bmp"

void initTextures();
GLuint images[9];


void postSlots(vector<int> &numImages){

    initTextures();
    if(numImages.size() >= 1){
        /*f1*/
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
        /*f2*/
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
        /*s1*/
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

    /*s2*/
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
        /*t1*/
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

    if(numImages.size() >= 6){
        /*t2*/
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
    }
        
    glBindTexture(GL_TEXTURE_2D, 0);

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


void writeMoney(int money) {
	
    string s = "Money = " + to_string(money);
	
    glColor3f(0.96,0.96,0.96);
    glRasterPos3f(3,4.75,3);
    
    for( char c : s ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }

}


void writeResultForSlotShot(int money) {
	
    string s = "Res: " + to_string(money);
	
    glColor3f(0.96,0.96,0.96);
    glRasterPos3f(2.75,4.75,3);

    for( char c : s ) {
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }
    
}

