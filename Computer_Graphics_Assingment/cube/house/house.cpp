#include "house.h"

#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



GLuint wallTexture = 0;
GLuint roofTexture = 0;
GLuint grassTexture = 0;



float rotationAngle = 0.0f;



GLuint loadTexture(const char* filename)
{
    int width;
    int height;
    int channels;

    stbi_set_flip_vertically_on_load(1);

    unsigned char* image = stbi_load(
        filename,
        &width,
        &height,
        &channels,
        3
    );

    if (image == NULL)
    {
        printf("Failed to load texture: %s\n", filename);
        printf("Reason: %s\n", stbi_failure_reason());

        return 0;
    }

    printf("Texture loaded: %s\n", filename);
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);

    GLuint textureID;

    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_LINEAR
    );


    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_REPEAT
    );


    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGB,
        width,
        height,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        image
    );

    stbi_image_free(image);

    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}


void loadTextures()
{
    wallTexture = loadTexture(
        "E:/CG/house/wall_texture.jpg"
    );

    roofTexture = loadTexture(
        "E:/CG/house/roof_texture.jpg"
    );

    grassTexture = loadTexture(
        "E:/CG/house/grass_texture.jpg"
    );
}


void drawTexturedCube(
    float x,
    float y,
    float z,
    float width,
    float height,
    float depth,
    GLuint texture
)
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);

    glColor3f(1.0f, 1.0f, 1.0f);

    float x1 = x;
    float x2 = x + width;

    float y1 = y;
    float y2 = y + height;

    float z1 = z;
    float z2 = z + depth;

    glBegin(GL_QUADS);

    // Front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z2);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z2);


    // Back
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x2, y1, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, y1, z1);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x1, y2, z1);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x2, y2, z1);


    // Left
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, y1, z2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x1, y2, z2);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z1);


    // Right
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x2, y1, z2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z1);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z1);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x2, y2, z2);


    // Top
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y2, z2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y2, z2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z1);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z1);


    // Bottom
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z1);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y1, z2);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y1, z2);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);
}



void drawRoof()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, roofTexture);

    glColor3f(1.0f, 1.0f, 1.0f);



    float x1 = -3.3f;
    float x2 = 3.3f;

    float z1 = -2.3f;
    float z2 = 2.3f;

    float wallTop = 2.5f;

    float roofTop = 4.0f;

    glBegin(GL_TRIANGLES);

    // Front roof triangle
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, wallTop, z2);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, wallTop, z2);

    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, roofTop, z2);


    // Back roof triangle
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x2, wallTop, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, wallTop, z1);

    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, roofTop, z1);

    glEnd();


    // Left roof slope
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, wallTop, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, wallTop, z2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, roofTop, z2);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, roofTop, z1);

    glEnd();


    // Right roof slope
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, roofTop, z1);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, roofTop, z2);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, wallTop, z2);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x2, wallTop, z1);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);
}



void drawDoor()
{
    glColor3f(0.35f, 0.15f, 0.05f);

    glBegin(GL_QUADS);

    glVertex3f(-0.75f, 0.0f, 2.01f);
    glVertex3f(0.75f, 0.0f, 2.01f);
    glVertex3f(0.75f, 2.0f, 2.01f);
    glVertex3f(-0.75f, 2.0f, 2.01f);

    glEnd();

    // Door knob
    glColor3f(1.0f, 0.75f, 0.1f);

    glPushMatrix();

    glTranslatef(0.45f, 1.0f, 2.08f);

    glutSolidSphere(
        0.10,
        20,
        20
    );

    glPopMatrix();
}



void drawWindow(float x, float y, float z)
{

    glColor3f(0.25f, 0.12f, 0.05f);

    glBegin(GL_QUADS);

    glVertex3f(x - 0.7f, y - 0.7f, z);
    glVertex3f(x + 0.7f, y - 0.7f, z);
    glVertex3f(x + 0.7f, y + 0.7f, z);
    glVertex3f(x - 0.7f, y + 0.7f, z);

    glEnd();

    // Glass
    glColor3f(0.1f, 0.65f, 0.9f);

    glBegin(GL_QUADS);

    glVertex3f(x - 0.55f, y - 0.55f, z + 0.01f);
    glVertex3f(x + 0.55f, y - 0.55f, z + 0.01f);
    glVertex3f(x + 0.55f, y + 0.55f, z + 0.01f);
    glVertex3f(x - 0.55f, y + 0.55f, z + 0.01f);

    glEnd();

    // Vertical divider
    glColor3f(0.25f, 0.12f, 0.05f);

    glBegin(GL_QUADS);

    glVertex3f(x - 0.04f, y - 0.55f, z + 0.02f);
    glVertex3f(x + 0.04f, y - 0.55f, z + 0.02f);
    glVertex3f(x + 0.04f, y + 0.55f, z + 0.02f);
    glVertex3f(x - 0.04f, y + 0.55f, z + 0.02f);

    glEnd();

    // Horizontal divider
    glBegin(GL_QUADS);

    glVertex3f(x - 0.55f, y - 0.04f, z + 0.02f);
    glVertex3f(x + 0.55f, y - 0.04f, z + 0.02f);
    glVertex3f(x + 0.55f, y + 0.04f, z + 0.02f);
    glVertex3f(x - 0.55f, y + 0.04f, z + 0.02f);

    glEnd();
}



void drawChimney()
{
    glColor3f(0.55f, 0.25f, 0.15f);

    drawTexturedCube(
        1.6f,
        2.5f,
        -0.8f,
        0.7f,
        1.7f,
        0.7f,
        wallTexture
    );
}



void drawTree()
{
    // Tree trunk
    glColor3f(0.35f, 0.16f, 0.05f);

    glPushMatrix();

    glTranslatef(5.0f, 0.0f, 1.0f);

    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    GLUquadric* trunk = gluNewQuadric();

    gluCylinder(
        trunk,
        0.3,
        0.3,
        2.5,
        20,
        20
    );

    gluDeleteQuadric(trunk);

    glPopMatrix();


    // Tree leaves
    glColor3f(0.05f, 0.45f, 0.08f);

    glPushMatrix();

    glTranslatef(5.0f, 3.0f, 1.0f);

    glutSolidSphere(
        1.4,
        30,
        30
    );

    glPopMatrix();
}



void drawGround()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, grassTexture);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-10.0f, -0.05f, -10.0f);

    glTexCoord2f(5.0f, 0.0f);
    glVertex3f(10.0f, -0.05f, -10.0f);

    glTexCoord2f(5.0f, 5.0f);
    glVertex3f(10.0f, -0.05f, 10.0f);

    glTexCoord2f(0.0f, 5.0f);
    glVertex3f(-10.0f, -0.05f, 10.0f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);
}



void drawHouse()
{
    glPushMatrix();



    drawGround();




    drawTexturedCube(
        -3.0f,
        0.0f,
        -2.0f,
        6.0f,
        2.5f,
        4.0f,
        wallTexture
    );




    drawRoof();




    drawDoor();




    drawWindow(
        -2.0f,
        1.3f,
        2.02f
    );

    drawWindow(
        2.0f,
        1.3f,
        2.02f
    );




    drawChimney();



    drawTree();


    glPopMatrix();
}



void updateHouse()
{
    rotationAngle += 0.25f;

    if (rotationAngle >= 360.0f)
    {
        rotationAngle = 0.0f;
    }

    glutPostRedisplay();
}



void cleanupHouse()
{
    if (wallTexture != 0)
    {
        glDeleteTextures(
            1,
            &wallTexture
        );

        wallTexture = 0;
    }

    if (roofTexture != 0)
    {
        glDeleteTextures(
            1,
            &roofTexture
        );

        roofTexture = 0;
    }

    if (grassTexture != 0)
    {
        glDeleteTextures(
            1,
            &grassTexture
        );

        grassTexture = 0;
    }
}
