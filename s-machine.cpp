#include <iostream>
#include<GL/glut.h>

static float window_width=0, window_height=0;

static void on_display(void);
static void on_keyboard(unsigned char, int, int);
static void on_reshape(int, int);

static void iscrtajCoveka();
static void iscrtajSlotMasinu();

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
    /*3,6,3,3,5,0,0,1,0 Pogled u ekran*/
    /*10,8,7,0,0,0, 0,1,0 Ulazni pogled*/
    /*12,8,8,0,2,0, 0,1,0*/
    gluLookAt(12,8,8,0,2,0, 0,1,0);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex3d(0,0, 0);
        glVertex3d(7,0,0);
        glVertex3d(0,0, 0);
        glVertex3d(0,7,0);
        glVertex3d(0,0, 0);
        glVertex3d(0,0,7);
    glEnd();


    iscrtajCoveka();
    iscrtajSlotMasinu();
    glutSwapBuffers();
    
}

void on_keyboard(unsigned char c , int x , int y) {

    switch (c){
        case 27:
            exit(0);
            break;
    }
}

void iscrtajCoveka() {

    glTranslatef(3,0,3);

    glColor3f(1,1,0);
    GLUquadricObj *donji_deo_stolice1, *gronji_deo_stolice2,* diskZaStolicuD, *diskZaStolicuG;

    /*Podnozje stolice*/
    glPushMatrix();
        donji_deo_stolice1 = gluNewQuadric();
        diskZaStolicuD = gluNewQuadric();
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
        gluDisk(diskZaStolicuD,0, 1.0f, 32, 32 );
        gluCylinder(donji_deo_stolice1, 1.0f, 1.0f, 0.2f, 32, 32);
    glPopMatrix();

    /*Sedaljka za stolicu*/
    glPushMatrix();
        gronji_deo_stolice2 = gluNewQuadric();
        diskZaStolicuG = gluNewQuadric();
        glTranslatef(0,3,0);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
        gluDisk(diskZaStolicuG, 0,0.5f,32,32);
        gluCylinder(gronji_deo_stolice2, 0.5f, 0.7f, 0.2f, 32, 32);
    glPopMatrix();

    /*Nogara  za stolicu*/
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

    /*Desna potkolenica*/
    glPushMatrix();
        glTranslatef(0.6,2.5,-1.4);
        glRotatef(-270,1,0,0);
        glScalef(1,1,5.5);
        glutSolidCube(0.4);
    glPopMatrix();

    /*Leva  potkolenica*/
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

    glTranslatef(-3,0,-3);

}

void iscrtajSlotMasinu() {

    glScalef(1,1.2,1);
    glTranslatef(3,0,0);
    glRotatef(-90, 0,1,0);

    glPushMatrix();

        /*Ledja*/
        glColor3f(0,0,0);
        glPushMatrix();
            glTranslatef(-0.5,3,0);
            glScalef(1,6,3);
            glutSolidCube(1);
        glPopMatrix();

        /*Srednji deo*/
        glColor3f(1,1,1);
        glPushMatrix();
            glTranslatef(0, 3,0);
            glScalef(1,20,10);
            glutSolidCube(0.3);
        glPopMatrix();


        /*Horizontalni Ekran G*/
        glColor3f(0.75,0.75,0.75);
        glPushMatrix();
            glTranslatef(0.15, 5, 0);
            glScalef(1.2,1,20);
            glutSolidCube(0.1);
        glPopMatrix();
        /*Horizontalni Ekran D*/
        glPushMatrix();
            glTranslatef(0.15, 4, 0);
            glScalef(1.2,1,20);
            glutSolidCube(0.1);
        glPopMatrix();
        /*Vertikalni Ekran L*/
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
        /*Vertikalni Ekran D*/
        glPushMatrix();
            glTranslatef(0.15, 4.5, -1);
            glRotatef(90,1,0,0);
            glScalef(1.2,1,10);
            glutSolidCube(0.1);
        glPopMatrix();

        /*Touch*/
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

        /*Rucka*/
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

        /*za 777 sivi deo*/
        glBegin(GL_POLYGON);
            glColor3f(0.75,0.75,0.75);
            glVertex3d(0.16,5.2,1.4);
            glVertex3d(0.16,5.2,-1.4);
            glVertex3d(0.16,5.85,-1.4);
            glVertex3d(0.16,5.85,1.4);
        glEnd();

        /*za slot masinu crni deo*/
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex3d(0.16,0.15,1.4);
        glVertex3d(0.16,0.15,-1.4);
        glVertex3d(0.16,2.40,-1.4);
        glVertex3d(0.16,2.40,1.4);
        glEnd();

        /*za slot masinu crveni deo*/
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
    glScalef(1,1/1.2,1);

}
