#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "raygui.h"
#include "scenes/main.h"
#include "scenes/mainmenu.h"

int main(void) {

	char scene[] = "mainmenu";

	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Proto Pong");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
			renderScene();
		EndDrawing();
	}
}

int renderScene() {
	if (scene == "mainmenu") {
		runMainMenuScene();	
	} else if (scene == "main") {
		runMainScene();
	}
}
