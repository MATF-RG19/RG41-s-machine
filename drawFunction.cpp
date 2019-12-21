/*Biblioteka za slike i nacin iscrtavanja tekstura preuzet je od asistenta Rastka Djordjevica*/

#include <iostream>
#include <string>
#include <GL/glut.h>
#include "drawFunction.hpp"
#include "imageLib/image.h"

using namespace std;

#define HEADER "images/header.bmp"
#define FOOTER "images/footer.bmp"
#define BUTTONS "images/buttons.bmp"

GLuint names[3];
static void drawTextures();
static void initTextures();

static bool sStarted = false;

void lightInit(){
    GLfloat light_ambient[] = { 0,0,0, 1 };
    GLfloat light_diffuse[] = { 1,1,1, 1 };
    GLfloat light_specular[] = { 0,0,0, 1 };
    GLfloat model_ambient[] = { 0.4,0.4,0.4, 1 };
    GLfloat light_position[] = { 5,5,5,0 };


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    GLfloat no_material[] = { 0,0,0, 1 };
    GLfloat material_diffuse[] = { 1,1,1, 1 };
    GLfloat no_shininess[] = { 100 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, no_material);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_material);

    glEnable(GL_COLOR_MATERIAL);
}

void drawMan() {
    glScalef(0.8, 0.8, 1);
    glTranslatef(3.5,0,3.5);

    glColor3f(1,1,0);
    GLUquadricObj *downChair, *upChair, *diskDownChair1, *diskDownChair2, *diskUpChair1, *diskUpChair2;

    /*Donji deo stolice*/
    glPushMatrix();
      downChair = gluNewQuadric();
      diskDownChair1 = gluNewQuadric();
      diskDownChair2 = gluNewQuadric();

      glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
      gluDisk(diskDownChair1,0, 1.0f, 32, 32 );
      glTranslatef(0,0,0.2);
      gluDisk(diskDownChair2,0, 1.0f, 32, 32 );
      glTranslatef(0,0,-0.2);
      gluCylinder(downChair, 1.0f, 1.0f, 0.2f, 32, 32);
    glPopMatrix();

    /*Gornji deo stolice*/
    glPushMatrix();
      upChair = gluNewQuadric();
      diskUpChair1 = gluNewQuadric();
      glTranslatef(0,3,0);
      glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
      gluDisk(diskUpChair1, 0,0.5f,32,32);
      gluCylinder(upChair, 0.5f, 0.7f, 0.2f, 32, 32);
    glPopMatrix();

    /*Noga od stolice*/
    glPushMatrix();
      glTranslatef(0,1.5,0);
      glScalef(1,5,1);
      glutSolidCube(0.6);
    glPopMatrix();

    glColor3f(0,1,0);

    /*Telo coveka*/
    glPushMatrix();
      glTranslatef(0,4.4,0);
      glScalef(2,3,1);
      glutSolidCube(0.8);
    glPopMatrix();

    /*Glava coveka*/
    glPushMatrix();
      glTranslatef(0,5.95,0);
      glutSolidSphere(0.35, 32,32);
    glPopMatrix();


    /*Desna noga*/
    glPushMatrix();
      glTranslatef(0.6,3.4,-0.4);
      glScalef(1,1,4);
      glutSolidCube(0.4);
    glPopMatrix();
    
    /*Leva noga*/
    glPushMatrix();
      glTranslatef(-0.6,3.4,-0.4);
      glScalef(1,1,4);
      glutSolidCube(0.4);
    glPopMatrix();

    /*Desno potkolenica*/
    glPushMatrix();
      glTranslatef(0.6,2.5,-1.4);
      glRotatef(-270,1,0,0);
      glScalef(1,1,5.5);
      glutSolidCube(0.4);
    glPopMatrix();

    /*Leva potkolenica*/
    glPushMatrix();
      glTranslatef(-0.6,2.5,-1.4);
      glRotatef(-270,1,0,0);
      glScalef(1,1,5.5);
      glutSolidCube(0.4);
    glPopMatrix();

    /*Desna ruka*/
    glColor3f(0,0.9,0);
	  glPushMatrix();
      glTranslatef(1,4.8,0);
      glRotatef(-270,1,0,0);
      glScalef(1,1,4);
      glutSolidCube(0.4);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(1,3.9,0);
      glutSolidSphere(0.2,32,32);
    glPopMatrix();

    /*Leva ruka*/
    glPushMatrix();
      glTranslatef(-1,4.8,0);
      glRotatef(-270,1,0,0);
      glScalef(1,1,4);
      glutSolidCube(0.4);
		glPopMatrix();
		glPushMatrix();
      glTranslatef(-1,3.9,0);
      glutSolidSphere(0.2,32,32);
    glPopMatrix();

    glTranslatef(-3.5,0,-3.5);
    glScalef(1/0.8, 1/0.8, 1);

}

void drawSlotMachine(bool shotTaster) {

    glScalef(1,1.1,1);
    glTranslatef(3,0,0);
    glRotatef(-90, 0,1,0);

    glPushMatrix(); //POCETNI PUSH

    /*Ledja slot masine*/
    glColor3f(0,0,0);
    glPushMatrix();
      glTranslatef(-0.5,3,0);
      glScalef(1,6,3);
      glutSolidCube(1);
    glPopMatrix();

    /*Srednji deo slot masine*/
    glColor3f(1,0.2,0.2);
    glPushMatrix();
      glTranslatef(0, 3,0);
      glScalef(1,20,10);
      glutSolidCube(0.3);
    glPopMatrix();

    /*Moj pogled*/
    /*gornji deo ekrana*/
    glColor3f(0.75,0.75,0.75);
    glPushMatrix();
      glTranslatef(0.15, 5, 0);
      glScalef(1.2,1,20);
      glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0.15, 4, 0);
      glScalef(1.2,1,20);
      glutSolidCube(0.1);
    glPopMatrix();
    /*Vertikalni razmaci kolona*/
    glPushMatrix();
      glTranslatef(0.15, 4.5, 1);
      glRotatef(90,1,0,0);
      glScalef(1.2,1,10);
      glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0.15, 4.5, 0.3);
      glRotatef(90,1,0,0);
      glScalef(1,1,10);
      glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0.15, 4.5, -0.3);
      glRotatef(90,1,0,0);
      glScalef(1,1,10);
      glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0.15, 4.5, -1);
      glRotatef(90,1,0,0);
      glScalef(1.2,1,10);
      glutSolidCube(0.1);
    glPopMatrix();

    /*Dugmici*/
    glPushMatrix();
      glTranslatef(0.3,3.0,0);
      glRotatef(-15,0,0,1 );
      glPushMatrix();
        glColor3f(0,0,0);
        /*glTranslatef(0,0.10, 1);
        glutSolidCube(0.35);
        glTranslatef(0,-0.10, -1);
        glTranslatef(0,0.15, 0.2);
        glutSolidCube(0.3);
        glTranslatef(0,-0.15, -0.2);
        glTranslatef(0,0.20, -0.45);
        glutSolidCube(0.25);
        glTranslatef(0,-0.20, +0.45);
        glTranslatef(0,0.25, -1.);
        glutSolidCube(0.2);
        glTranslatef(0,-0.25, +1.);*/
        glColor3f(1,0,0);
        glScalef(1,1,6);
        glutSolidCube(0.5);
      glPopMatrix();
    glPopMatrix();

    /*Rucka*/
    glColor3f(0,1,0);
    glPushMatrix();
      glTranslatef(-0.5,3,-1.7);
      glRotatef(90,0,1,0);
      if(shotTaster) {
          glRotatef(180, 1, 0, 0);
      }
      else{
          glRotatef(135, 1, 0, 0);
      }
      glTranslatef(0,0, -1.5);
      glutSolidSphere(0.2,32,32);
      GLUquadricObj* rucka = gluNewQuadric();
      glTranslatef(0,0,0.1);
      gluCylinder(rucka, 0.1f,0.1f,1.5,32,32);
      glTranslatef(0,0,-0.1);
      glTranslatef(0,0, 1.5);
      if(shotTaster) {
          glRotatef(-180, 1, 0, 0);
      }
      else{
          glRotatef(-135, 1, 0, 0);
      }
      glRotatef(-90,0,1,0);
      GLUquadricObj* postoljeRucke = gluNewQuadric();
      GLUquadricObj* diskZaRucku = gluNewQuadric();
      gluDisk(diskZaRucku, 0,0.32, 32,32);
      gluCylinder(postoljeRucke, 0.2,0.25,0.15, 32,32);
    glPopMatrix();

    drawTextures();

    glPopMatrix(); //POCETNI POP

    glRotatef(90, 0,1,0);
    glTranslatef(-3,0,0);
    glScalef(1,1/1.1,1);

    glColor3f(0.96,0.96,0.96);
        
}

void pressS(){
    
    if (sStarted)
      return;

    /*Omogucavamo da se samo u polaznom koraku natpis ukljucuje*/
    sStarted = true;

    string s = "Press S to START program";

    glColor3f(1,0,0);
    glRasterPos3f(-6,-8,3);

    for( char c : s ) {
      glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, c );
    }

}


void drawTextures(){
    
    initTextures();

    /*Crtanje zaglavlja: JACKPOT*/
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);

    glTexCoord2f(0.1, 0);
    glVertex3d(0.16,5.2,1.4);

    glTexCoord2f(1, 0);
    glVertex3d(0.16,5.2,-1.4);

    glTexCoord2f(1, 1);
    glVertex3d(0.16,5.85,-1.4);

    glTexCoord2f(0.1, 1);
    glVertex3d(0.16,5.85,1.4);
    glEnd();

    /*Crtanje podnozja: MEGAJACK*/
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);

    glTexCoord2f(0, 0);
    glVertex3d(0.16,0.15,1.4);

    glTexCoord2f(1, 0);
    glVertex3d(0.16,0.15,-1.4);

    glTexCoord2f(1, 1);
    glVertex3d(0.16,2.40,-1.4);

    glTexCoord2f(0, 1);
    glVertex3d(0.16,2.40,1.4);

    glEnd();

    /*Crtanje tastera*/
    glBindTexture(GL_TEXTURE_2D, names[2]);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);

    glTexCoord2f(0, 0);
    glVertex3d(0.65,3.2,1.5);

    glTexCoord2f(1, 0);
    glVertex3d(0.65,3.2,-1.5);

    glTexCoord2f(1, 1);
    glVertex3d(0.15,3.35,-1.5);

    glTexCoord2f(0, 1);
    glVertex3d(0.15,3.35,1.5);

    glEnd();

    
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

    glGenTextures(3, names);

    image_read(image, HEADER);
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    image_read(image, FOOTER);
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);


    image_read(image, BUTTONS);
    glBindTexture(GL_TEXTURE_2D, names[2]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);
}
