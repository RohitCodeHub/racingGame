#ifndef COMMON_H
#define COMMON_H

#include <GL/glut.h>
#include <string.h>

#define GBPS_WINDOW_HEIGHT 600
#define GBPS_WINDOW_WIDTH 800

// Global variables
extern int gbps_WindowHeight;
extern int gbps_WindowWidth;
extern long highscore;

// Function prototypes
void gbps_PrintText(int x, int y, float r, float g, float b, int font, char *string);
void printWelcomeMessage();
void displayImage();
void renderScene();

#endif // COMMON_H

