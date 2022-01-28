/**
 * @file main.cpp
 * @brief geometry
 * @author a.akulin
 * @date October 7, 2019
 */

#include <iostream>
#include <GL/glut.h>
#include "Parser.h"
#include "Object.h"

namespace {
int WinWidth = 1024;
int WinHeight = 768;
bool Fullscreen = false;
Object *object = nullptr;
}

void Display(int argc, char** argv);
void DisplayFunc();
void ReshapeFunc(int width, int height);
void KeyboardFunc(unsigned char key, int x, int y);

void Display(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    glutInitWindowSize(WinWidth, WinHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Geometry");
    glutDisplayFunc(DisplayFunc);
    glutReshapeFunc(ReshapeFunc);
    glutKeyboardFunc(KeyboardFunc);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DisplayFunc() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    object->draw();

    glutSwapBuffers();
}

void ReshapeFunc(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glOrtho(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0, 0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void KeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
    }
}

int main(int argc, char** argv) {
    Parser parser(argc, argv);
    object = new Object(parser.getFigures());
    Display(argc, argv);

    glutMainLoop();

    return 0;
}
