/*
 * File:   main.cpp
 * Author: brandon
 *
 * Created on January 7, 2011, 2:37 PM
 */

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <ctime>
#include <vector>

#include "Fish.h"
#include "Background.h"
#include "Bubble.h"

#define ESCAPE 27
#define SEC_PER_FRAME 1000/60


using namespace std;

void resize(int width, int height);
void Draw();
void Update(int t);
void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);
void InitGL(int Width, int Height);

bool fullscreen;
int window;

int angle;
vector<PhysObj*> hitObjects;
Background background;

clock_t frameClock;

/*
 *
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    fullscreen = false;
    window = glutCreateWindow("Fishy!");
    glutReshapeFunc(&resize);
    glutTimerFunc(0, &Update, 0);
    glutDisplayFunc(&Draw);
    InitGL(640, 480);
    glutSpecialFunc(&specialKeyDown);
    glutSpecialUpFunc(&specialKeyUp);
    glutKeyboardFunc(&keyDown);
    glutKeyboardUpFunc(&keyUp);

    hitObjects.push_back(new Fish());
    for (int i = 0; i < 10; i++)
        hitObjects.push_back(new Fish(true));
    background = Background();

    glutMainLoop();
    return 0;
}

void InitGL(int Width, int Height) // We call this right after our OpenGL window is created.
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear The Background Color To Black
    glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    // glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset The Projection Matrix

    gluPerspective(45.0f, (GLfloat) Width / (GLfloat) Height, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void resize(int width, int height) {
    if (height == 0) // Prevent A Divide By Zero If The Window Is Too Small
        height = 1;

    glViewport(0, 0, width, height); // Reset The Current Viewport And Perspective Transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity(); // Reset The View
    glPushMatrix();
    glTranslatef(0, 0, -10);
    glRotatef(angle, 1, 1, 1);
    background.Draw();
    for (int i = 0; i < hitObjects.size(); i++)
        hitObjects[i]->Draw();
    glPopMatrix();
    glutSwapBuffers();
}

void Update(int t) {
    for (int i = 0; i < hitObjects.size(); i++) {
        hitObjects[i]->Update(t);
        for (int j = 0; j < hitObjects.size(); j++) {
            if (hitObjects[i]->hitTest(hitObjects[j])) {
                if (hitObjects[i]->largerThan(hitObjects[j])){
                    hitObjects.erase(hitObjects.begin()+j);
                    hitObjects[i]->grow(1.25);
                }
            }
            //MAKE VALID HIT BOXES
        }
    }
    //if ((clock() - t) >= 0) {
    //   frameClock = clock();
    glutPostRedisplay();
    //} else {
    //   frameClock = t;
    //}
    //float wait = (SEC_PER_FRAME - (frameClock - t)*CLOCKS_PER_SEC/1000) > 0 ? SEC_PER_FRAME - (t - frameClock) : 0;
    glutTimerFunc(18, &Update, t);
}

void keyDown(unsigned char key, int x, int y) {
    /* avoid thrashing this procedure */
    usleep(100);

    /* If escape is pressed, kill everything. */
    switch (key) {

        case ESCAPE:
            /* shut down our window */
            glutDestroyWindow(window);
            /* exit the program...normal termination. */
            exit(0);
            break;

        case 'g':
            hitObjects[0]->grow(1.1);
            break;
        case 'a':
            hitObjects[0]->roll();
            break;
    }
}

void specialKeyDown(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            hitObjects[0]->MoveUp();
            break;
        case GLUT_KEY_DOWN:
            hitObjects[0]->MoveDown();
            break;
        case GLUT_KEY_LEFT:
            hitObjects[0]->MoveLeft();
            break;
        case GLUT_KEY_RIGHT:
            hitObjects[0]->MoveRight();
            break;
    }
}

/*
 Key released function
 */
void keyUp(unsigned char key, int x, int y) {

}

void specialKeyUp(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
            hitObjects[0]->stopMoveY();
            break;
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT:
            hitObjects[0]->stopMoveX();
            break;
    }
}






