#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);

    // Position of the light
    GLfloat lightPosition[] = {
        2.0f,  // X
        2.0f,  // Y
        2.0f,  // Z
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Blue sphere
    glColor3f(0.0f, 1.0f, 1.0f);

    glutSolidSphere(1.2, 30, 30);

    glFlush();
}

void init(void)
{
    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Depth testing
    glEnable(GL_DEPTH_TEST);

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Allow glColor3f() to set material color
    glEnable(GL_COLOR_MATERIAL);

    // Set projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solid Sphere");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
