#include <GL/glut.h>
#include "house.h"

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    glLoadIdentity();


    glTranslatef(
        0.0f,
        -1.0f,
        -14.0f
    );


    drawHouse();

    glutSwapBuffers();
}


void init()
{

    glClearColor(
        0.02f,
        0.04f,
        0.10f,
        1.0f
    );


    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPosition[] =
    {
        5.0f,
        8.0f,
        8.0f,
        1.0f
    };

    GLfloat lightAmbient[] =
    {
        0.3f,
        0.3f,
        0.3f,
        1.0f
    };

    GLfloat lightDiffuse[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(
        GL_LIGHT0,
        GL_POSITION,
        lightPosition
    );

    glLightfv(
        GL_LIGHT0,
        GL_AMBIENT,
        lightAmbient
    );

    glLightfv(
        GL_LIGHT0,
        GL_DIFFUSE,
        lightDiffuse
    );


    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(
        GL_FRONT_AND_BACK,
        GL_AMBIENT_AND_DIFFUSE
    );


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

    loadTextures();
}


void reshape(
    int width,
    int height
)
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



int main(
    int argc,
    char** argv
)
{
    glutInit(
        &argc,
        argv
    );

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(
        800,
        700
    );

    glutCreateWindow(
        "My Dream House - OpenGL"
    );

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);


    glutMainLoop();

    return 0;
}
