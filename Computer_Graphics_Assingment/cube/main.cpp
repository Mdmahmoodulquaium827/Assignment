#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void drawCube(float size)
{
float s = size / 2.0f;
glBegin(GL_QUADS);
// Front face
glColor3f(0.0f, 1.0f, 1.0f);
glVertex3f(-s, -s, s);
glVertex3f( s, -s, s);
glVertex3f( s, s, s);
glVertex3f(-s, s, s);
// Back face
glColor3f(0.0f, 1.0f, 0.0f);
glVertex3f(-s, -s, -s);
glVertex3f(-s, s, -s);
glVertex3f( s, s, -s);
glVertex3f( s, -s, -s);
// Left face
glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-s, -s, -s);
glVertex3f(-s, -s, s);
glVertex3f(-s, s, s);
glVertex3f(-s, s, -s);
// Right face
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f( s, -s, -s);
glVertex3f( s, s, -s);
glVertex3f( s, s, s);
glVertex3f( s, -s, s);
// Top face
glColor3f(1.0f, 0.0f, 0.0f);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex3f(-s, s, -s);
glVertex3f(-s, s, s);
glVertex3f( s, s, s);
glVertex3f( s, s, -s);
// Bottom face
glColor3f(0.0f, 0.0f, 1.0f);
glVertex3f(-s, -s, -s);
glVertex3f( s, -s, -s);
glVertex3f( s, -s, s);
glVertex3f(-s, -s, s);
glEnd();

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);


    glRotatef(30.0f, 1.0f, 1.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);

    drawCube(2.0f);

    glFlush();
}
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

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
    glutCreateWindow("Solid Cube");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
