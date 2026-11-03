#include <GL/glut.h>
#include "planet.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Move planet away from camera
    glTranslatef(0.0f, 0.0f, -6.0f);

    // Draw planet
    drawPlanet();

    glutSwapBuffers();
}

void init()
{

    glClearColor(
        0.0f,
        0.0f,
        0.02f,
        1.0f
    );


    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(
        45.0,
        1.0,
        0.1,
        100.0
    );


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();


    loadPlanetTexture();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(
        0,
        0,
        width,
        height
    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(
        45.0,
        (float)width / height,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(
        700,
        700
    );

    glutCreateWindow(
        "My Rotating Planet"
    );

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);


    glutIdleFunc(updatePlanet);

    glutMainLoop();

    return 0;
}
