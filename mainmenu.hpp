int x = 0;
int y = 560;

int xvel = 1;
int yvel = -2;

void updateMainMenu() {
    x += xvel;
    y += yvel;

    if (x >= 560) {
        xvel = -1;
    }

    if (y >= 560) {
        yvel = -1;
    }

    if (x <= 0) {
        xvel = 3;
    }

    if (y <= 0) {
        yvel = 1;
    }
}

void runMainMenuScene() {
	ClearBackground(BLACK);

	DrawText("Press RETURN to play!", x, y, 20, LIGHTGRAY);

    //DrawRectangle()

    DrawText("Easy", 400 - MeasureText("Easy", 20) / 2, 300, 20, LIGHTGRAY);
    DrawText("Medium", 400 - MeasureText("Medium", 20) / 2, 330, 20, LIGHTGRAY); 
    DrawText("Hard", 400 - MeasureText("Hard", 20) / 2, 360, 20, LIGHTGRAY);


	if (IsKeyPressed(KEY_ENTER)) {
		//strcpy(publicvariables::scene, "main");
        
        publicvariables::scene = 1;
	}

    updateMainMenu();
}
