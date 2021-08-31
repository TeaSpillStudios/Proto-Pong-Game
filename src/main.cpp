#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include <string>
#include <vector>

namespace publicvariables {
    int scene = 0;

    int speed = 5;
}

int playCollisionSound() {
    Sound sound = LoadSound("collide.wav");
    PlaySound(sound);
    return 0;
}

#include "scenes/mainmenu.hpp"
#include "scenes/main.hpp"
#include "scenes/gameover.hpp"
#include "scenes/win.hpp"

int renderScene(void) {

    if (publicvariables::scene == 0) {
		runMainMenuScene();	
	} else if (publicvariables::scene == 1) {
        runMainScene();
    } else if (publicvariables::scene == 2) {
        runGameOverScene();
    } else if (publicvariables::scene == 3) {
        runWinScene();
    }

    return 0;
}

int main(void) {
    
	const int screenWidth = 800;
	const int screenHeight = 600;
    
	InitWindow(screenWidth, screenHeight, "Proto Pong");

    InitAudioDevice();

	SetTargetFPS(60);

    HideCursor();

	while (!WindowShouldClose()) {
		BeginDrawing();
			renderScene();
		EndDrawing();
	}
}
