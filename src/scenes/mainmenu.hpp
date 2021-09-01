int x = 0;
int y = 560;

int count = 0;

bool canGo = true; 

int xvel = 1;
int yvel = -2;

int selecty = 330;

int positions[] = {300, 330, 360};

int positionspos = 0;

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

    selecty = positions[positionspos];

    if (!canGo) {
        count++;
    }

    if (count >= 10) {
        canGo = true;
    }

    if (positionspos >= 0 and positionspos < 2) {
        if (IsKeyPressed(KEY_DOWN)) {
            if(canGo) {
                positionspos++;
                count = 0;
                canGo = false;
            }
        }
    }

    if (positionspos > 0 and positionspos <= 2) {
        if (IsKeyPressed(KEY_UP)) {
            if(canGo) {
                positionspos--;
                count = 0;
                canGo = false;
            } else {
                if (count >= 10) {
                    canGo = true;
                }
            }
        }
    }

    selecty = positions[positionspos];

	DrawText("Press RETURN to play!", x, y, 20, LIGHTGRAY);

    DrawRectangle(325, selecty, 20, 20, LIGHTGRAY);

    DrawText("Easy", 400 - MeasureText("Easy", 20) / 2, 300, 20, LIGHTGRAY);
    DrawText("Medium", 400 - MeasureText("Medium", 20) / 2, 330, 20, LIGHTGRAY); 
    DrawText("Hard", 400 - MeasureText("Hard", 20) / 2, 360, 20, LIGHTGRAY);

	if (IsKeyPressed(KEY_ENTER)) {
        if (positionspos == 0) {
            publicvariables::speed = 2;
        } else if (positionspos == 1) {
            publicvariables::speed = 4;
        } else if (positionspos == 2) {
            publicvariables::speed = 6;
        }

        publicvariables::scene = 1;
	}

    updateMainMenu();
}
