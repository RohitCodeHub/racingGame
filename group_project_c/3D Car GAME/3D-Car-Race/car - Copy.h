#ifndef GBPS_CAR_H
#define GBPS_CAR_H

#include <GL/glut.h>

#define MAX_CAR_ROT 15
#define MAX_CAR_SIDE_POS 3

typedef struct {
    float x, y; // position of car (in 2D)
    int CarTexture; // car texture
    float vel, acc; // velocity and acceleration
    float rot; // rotation of car
    float TyreRot; // rotation of tyre
    // state variables
    int state1, state2, state3;
    int type; // type of car (for computer cars only)
} Gbps_Car;

enum CarTypes {
    CAR_CONSTANT_VEL,
    CAR_CONSTANT_VEL_MOVING
};

Gbps_Car* CreateCar();
void RenderCar(Gbps_Car Car);
void loadTextures();
void display();
void keyboard(int key, int x, int y);
GLuint LoadTexture(const char *filename);

#endif // GBPS_CAR_H
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "car.h"

float car_crash_angle = 0.0;
GLuint carTexture;
GLuint tyreTexture;

Gbps_Car* CreateCar() {
    Gbps_Car* car = (Gbps_Car*)malloc(sizeof(Gbps_Car));
    if (car) {
        car->x = 0.0f;
        car->y = 0.0f;
        car->rot = 0.0f;
        car->TyreRot = 0.0f;
        car->vel = 0.1f;
        car->acc = 0.01f;
    }
    return car;
}

void loadTextures() {
    carTexture = LoadTexture("car_texture.bmp");
    tyreTexture = LoadTexture("tyre_texture.bmp");
}

GLuint LoadTexture(const char *filename) {
    // Placeholder texture loading function
    // Implement texture loading logic here
    return 0; // Placeholder return value
}

void RenderCar(Gbps_Car car) {
    glEnable(GL_TEXTURE_2D);

    printf("Welcome, Rohit Kumar!\n");

    glPushMatrix();
    glRotatef(car_crash_angle, 1.0, 0.0, 0.0);
    glTranslatef(car.x, 0.6, -car.y);
    glRotatef(-car.rot, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, carTexture);
    glBegin(GL_QUADS);
    // Define car vertices and map the texture here
    // ...
    glEnd();

    glBindTexture(GL_TEXTURE_2D, tyreTexture);

    float tyrePositions[4][3] = {
        {-1.205f, -0.277f, 0.733f},
        {-1.206f, -0.277f, -0.731f},
        {1.155f, -0.277f, 0.731f},
        {1.154f, -0.277f, -0.733f}
    };

    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glTranslatef(tyrePositions[i][0], tyrePositions[i][1], tyrePositions[i][2]);
        glRotatef((i < 2 ? -car.rot * 2 + (i == 0 ? 90 : 270) : 90 + (i == 2 ? 0 : 180)), 0.0, 1.0, 0.0);
        glRotatef(car.TyreRot * (i < 2 ? -1 : 1), 1.0, 0.0, 0.0);
        glBegin(GL_QUADS);
        // Define tyre vertices and map the texture here
        // ...
        glEnd();
        glPopMatrix();
    }

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Gbps_Car* car = CreateCar();
    RenderCar(*car);
    free(car);
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    loadTextures();
}

void keyboard(int key, int x, int y) {
    // Handle keyboard inputs to move the car
    Gbps_Car* car = CreateCar();
    switch (key) {
        case GLUT_KEY_LEFT:
            car->x -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:
            car->x += 0.1f;
            break;
        case GLUT_KEY_UP:
            car->y -= 0.1f;
            break;
        case GLUT_KEY_DOWN:
            car->y += 0.1f;
            break;
    }
    RenderCar(*car);
    free(car);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    printf("Welcome to the Car Racing Game, Rohit Kumar!\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car Racing Game - Welcome Rohit Kumar");

    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);

    glutMainLoop();
    return 0;
}

