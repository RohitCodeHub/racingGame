#include <stdio.h>
#include "mainmenu.h"
#include "init.h"
#include "game.h"

int main(int argc, char *argv[]) {
    // Display a welcome message to the user
    printf("\n\n\t\t**** WELCOME TO OUR GROUP PROJECT ****\n\n");
    printf("\t\t\t   Please wait while the game loads...\n\n");

    // Initialize the game window
    gbps_InitWindow(argc, argv);

    // Optional: Uncomment to enable fullscreen mode
    // glutFullScreen();

    // Enter the main menu to start the game
    gbps_EnterMainMenu();

    // Start the GLUT main loop
    glutMainLoop();

    return 0;
}

