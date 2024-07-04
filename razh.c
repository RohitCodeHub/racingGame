#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

// Global window dimensions with razh_ prefix
int razh_WindowHeight = 600;
int razh_WindowWidth = 800;
float razh_CarPosX = 0.0f; // Initial horizontal position of the car
float razh_CarPosY = -0.5f; // Initial vertical position of the car

// Function to print text on the screen with color and font
void razh_PrintText(int x, int y, float r, float g, float b, void* font, char *string) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len = (int)strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

// Function to initialize and print welcome message
void razh_PrintWelcomeMessage() {
    razh_PrintText(10, razh_WindowHeight - 20, 1.0, 1.0, 1.0, GLUT_BITMAP_HELVETICA_18, "Welcome! Use arrow keys to move the car.");
}

// Function to display a car (represented as a simple rectangle)
void razh_DisplayCar() {
    glColor3f(0.0, 0.0, 1.0); // Set car color to blue
    glBegin(GL_QUADS);
        glVertex2f(razh_CarPosX - 0.1f, razh_CarPosY - 0.05f); // Bottom-left corner
        glVertex2f(razh_CarPosX + 0.1f, razh_CarPosY - 0.05f); // Bottom-right corner
        glVertex2f(razh_CarPosX + 0.1f, razh_CarPosY + 0.05f); // Top-right corner
        glVertex2f(razh_CarPosX - 0.1f, razh_CarPosY + 0.05f); // Top-left corner
    glEnd();
}

// Main rendering function
void razh_RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Display welcome message
    razh_PrintWelcomeMessage();

    // Display car
    razh_DisplayCar();

    glutSwapBuffers();
}

// Function to handle keyboard input for car movement
void razh_HandleKeypress(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            razh_CarPosX -= 0.05f; // Move left
            break;
        case GLUT_KEY_RIGHT:
            razh_CarPosX += 0.05f; // Move right
            break;
        case GLUT_KEY_UP:
            razh_CarPosY += 0.05f; // Move up
            break;
        case GLUT_KEY_DOWN:
            razh_CarPosY -= 0.05f; // Move down
            break;
    }
    glutPostRedisplay(); // Redraw the scene with the updated car position
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(razh_WindowWidth, razh_WindowHeight);
    glutCreateWindow("Simple OpenGL Car Demo - Razh");

    // Register callbacks
    glutDisplayFunc(razh_RenderScene);
    glutSpecialFunc(razh_HandleKeypress); // Register function to handle special keys (like arrow keys)

    // Set background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Enter GLUT event processing cycle
    glutMainLoop();

    return 0;
}

