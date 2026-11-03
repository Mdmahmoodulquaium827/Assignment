#include "planet.h"
#include <GL/glut.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint planetTexture = 0;

float rotationAngle = 0.0f;

GLUquadric* planetQuadric = NULL;


void loadPlanetTexture()
{
    int width;
    int height;
    int channels;

    stbi_set_flip_vertically_on_load(1);

    unsigned char* image = stbi_load(
        "E:/CG/own_planet/planet_texture_clean.jpg",
        &width,
        &height,
        &channels,
        3
    );

    if (image == NULL)
    {
        printf("Failed to load planet texture!\n");
        printf("Reason: %s\n", stbi_failure_reason());
        return;
    }

    printf("Planet texture loaded successfully!\n");
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);


    glGenTextures(1, &planetTexture);


    glBindTexture(GL_TEXTURE_2D, planetTexture);

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



    planetQuadric = gluNewQuadric();

    gluQuadricTexture(planetQuadric, GL_TRUE);
}



void drawPlanet()
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, planetTexture);

    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();

    glRotatef(
        rotationAngle,
        0.0f,
        1.0f,
        0.0f
    );

    gluSphere(
        planetQuadric,
        1.5,
        80,
        80
    );

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisable(GL_TEXTURE_2D);
}


// Update Rotation

void updatePlanet()
{
    rotationAngle += 0.3f;

    if (rotationAngle >= 360.0f)
    {
        rotationAngle = 0.0f;
    }

    glutPostRedisplay();
}



// Cleanup

void cleanupPlanet()
{
    if (planetTexture != 0)
    {
        glDeleteTextures(
            1,
            &planetTexture
        );

        planetTexture = 0;
    }

    if (planetQuadric != NULL)
    {
        gluDeleteQuadric(planetQuadric);

        planetQuadric = NULL;
    }
}
