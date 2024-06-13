#include "common.h"

int gbps_WindowHeight = GBPS_WINDOW_HEIGHT,
    gbps_WindowWidth = GBPS_WINDOW_WIDTH;
long highscore = 0;

// Function to print text on the screen with color and font
void gbps_PrintText(int x, int y, float r, float g, float b, int font, char *string) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

// Function to initialize and print welcome message
void printWelcomeMessage() {
    gbps_PrintText(10, gbps_WindowHeight - 20, 1.0, 1.0, 1.0, GLUT_BITMAP_HELVETICA_18, "Welcome, Rohit Kumar!");
}

// Function to display an image (placeholder function)
void displayImage() {
    // Placeholder: Add code to display an image using OpenGL
    // For example, you can load a texture and render it on a quad
}

// Main rendering function
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Display welcome message
    printWelcomeMessage();

    // Display image (replace this with actual image rendering code)
    displayImage();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(gbps_WindowWidth, gbps_WindowHeight);
    glutCreateWindow("Car Racing Game - Rohit Kumar");

    // Register callbacks
    glutDisplayFunc(renderScene);

    // Enter GLUT event processing cycle
    glutMainLoop();

    return 0;
}

