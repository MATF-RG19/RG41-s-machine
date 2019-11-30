#include <GL/glut.h>
#include "drawFunction.h"

void drawMan() {
    glScalef(0.8, 0.8, 1);
    glTranslatef(3,0,2.5);

    glColor3f(1,1,0);
    GLUquadricObj *downChair1, *upChair2,* diskDownChair, *diskUpChair;

    /*Down chair*/
    glPushMatrix();
    downChair1 = gluNewQuadric();
    diskDownChair = gluNewQuadric();
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    gluDisk(diskDownChair,0, 1.0f, 32, 32 );
    gluCylinder(downChair1, 1.0f, 1.0f, 0.2f, 32, 32);
    glPopMatrix();

    /*Up chair*/
    glPushMatrix();
    upChair2 = gluNewQuadric();
    diskUpChair = gluNewQuadric();
    glTranslatef(0,3,0);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    gluDisk(diskUpChair, 0,0.5f,32,32);
    gluCylinder(upChair2, 0.5f, 0.7f, 0.2f, 32, 32);
    glPopMatrix();

    /*Leg of chair*/
    glPushMatrix();
    glTranslatef(0,1.5,0);
    glScalef(1,5,1);
    glutSolidCube(0.6);
    glPopMatrix();

    glColor3f(0,1,0);

    /*Body of men*/
    glPushMatrix();
    glTranslatef(0,4.4,0);
    glScalef(2,3,1);
    glutSolidCube(0.8);
    glPopMatrix();

    /*Head of men*/
    glPushMatrix();
    glTranslatef(0,5.95,0);
    glutSolidSphere(0.35, 32,32);
    glPopMatrix();


    /*Right leg*/
    glPushMatrix();
    glTranslatef(0.6,3.4,-0.4);
    glScalef(1,1,4);
    glutSolidCube(0.4);
    glPopMatrix();
    /*Left leg*/
    glPushMatrix();
    glTranslatef(-0.6,3.4,-0.4);
    glScalef(1,1,4);
    glutSolidCube(0.4);
    glPopMatrix();

    /*Right foot*/
    glPushMatrix();
    glTranslatef(0.6,2.5,-1.4);
    glRotatef(-270,1,0,0);
    glScalef(1,1,5.5);
    glutSolidCube(0.4);
    glPopMatrix();

    /*Left foot*/
    glPushMatrix();
    glTranslatef(-0.6,2.5,-1.4);
    glRotatef(-270,1,0,0);
    glScalef(1,1,5.5);
    glutSolidCube(0.4);
    glPopMatrix();

    /*Right hand*/
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

    /*Left hand*/
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

    glTranslatef(-3,0,-2.5);
    glScalef(1/0.8, 1/0.8, 1);

}

void drawSlotMachine() {

    glScalef(1,1.1,1);
    glTranslatef(3,0,0);
    glRotatef(-90, 0,1,0);

    glPushMatrix();

    /*Back of sm*/
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(-0.5,3,0);
    glScalef(1,6,3);
    glutSolidCube(1);
    glPopMatrix();

    /*Middle of sm*/
    glColor3f(1,0.9,0.9);
    glPushMatrix();
    glTranslatef(0, 3,0);
    glScalef(1,20,10);
    glutSolidCube(0.3);
    glPopMatrix();

    /*My view*/
    /*horizontal line*/
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
    /*vertical line Up*/
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

    /*Tasters*/
    glPushMatrix();
    glTranslatef(0.3,3.0,0);
    glRotatef(-15,0,0,1 );
    glPushMatrix();
    glColor3f(0,0,0);

    glTranslatef(0,0.10, 1);
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
    glTranslatef(0,-0.25, +1.);

    glColor3f(1,0,0);
    glScalef(1,1,6);
    glutSolidCube(0.5);
    glPopMatrix();

    glRotatef(15, 0,0,1);
    glTranslatef(-0.3,-3.0,0);
    glPopMatrix();

    /*Handle*/
    glColor3f(0,1,0);

    glPushMatrix();
    glTranslatef(-0.5,3,-1.7);
    glTranslatef(0,1.5,0);
    glRotatef(180, 0,0,1);
    glRotatef(270, 1,0,0);

    glutSolidSphere(0.2,32,32);

    GLUquadricObj* rucka = gluNewQuadric();
    glTranslatef(0,0,0.1);
    gluCylinder(rucka, 0.1f,0.1f,1.5,32,32);
    glTranslatef(0,0,-0.1);

    glRotatef(-270,1,0,0);
    glRotatef(-180, 0,0,1);
    glTranslatef(0,-1.5,0);

    GLUquadricObj* postoljeRucke = gluNewQuadric();
    GLUquadricObj* diskZaRucku = gluNewQuadric();
    gluDisk(diskZaRucku, 0,0.32, 32,32);
    gluCylinder(postoljeRucke, 0.2,0.25,0.15, 32,32);
    glPopMatrix();

    /*header for 777*/
    glBegin(GL_POLYGON);
    glColor3f(0.75,0.75,0.75);
    glVertex3d(0.16,5.2,1.4);
    glVertex3d(0.16,5.2,-1.4);
    glVertex3d(0.16,5.85,-1.4);
    glVertex3d(0.16,5.85,1.4);
    glEnd();

    /*footer black*/
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3d(0.16,0.15,1.4);
    glVertex3d(0.16,0.15,-1.4);
    glVertex3d(0.16,2.40,-1.4);
    glVertex3d(0.16,2.40,1.4);
    glEnd();

    /*footer red */
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3d(0.16,0.25,1.25);
    glVertex3d(0.16,0.25,-1.25);
    glVertex3d(0.16,2.25,-1.25);
    glVertex3d(0.16,2.25,1.25);
    glEnd();

    glPopMatrix();

    glRotatef(90, 0,1,0);
    glTranslatef(-2,0,0);
    glScalef(1,1/1.1,1);

}