#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);


        glColor3f(0.18, 0.35, 0.34);
        glVertex2f(0.0, 0.6);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5, -0.4);

        glColor3f(1.0, 0.0, 0.27);
        glVertex2f(0.5, -0.4);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Gradient Triangle");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
