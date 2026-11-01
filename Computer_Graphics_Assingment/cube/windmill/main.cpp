#include <GL/glut.h>

float angle = 0.0f;

void drawBlade()
{
    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.15f, 0.8f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.15f, 0.8f);

    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    drawBlade();

    glPushMatrix();
    glRotatef(120.0f, 0.0f, 0.0f, 1.0f);
    drawBlade();
    glPopMatrix();

    glPushMatrix();
    glRotatef(240.0f, 0.0f, 0.0f, 1.0f);
    drawBlade();
    glPopMatrix();

    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.12, 20, 20);


    glFlush();
}

void animation(void)
{
    angle = angle + 0.40f;

    if (angle >= 360.0f)
    {
        angle = 0.0f;
    }

    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutCreateWindow("3 Blade Windmill Animation");

    init();

    glutDisplayFunc(display);

    glutIdleFunc(animation);

    glutMainLoop();

    return 0;
}
