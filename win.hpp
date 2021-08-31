void drawWinScene() {
    ClearBackground(BLACK);

    DrawText("You win! Press RETURN to play again.", 400 - MeasureText("You win! Press RETURN to play again.", 20) / 2, 50, 20, LIGHTGRAY);
}

void updateWinScene() {
    drawWinScene();

    if (IsKeyPressed(KEY_ENTER)) {
        publicvariables::scene = 1; 
    }
}

void runWinScene() {
    updateWinScene();
}
