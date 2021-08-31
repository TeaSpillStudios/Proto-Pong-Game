void drawGameOverScene() {
    ClearBackground(BLACK);

    DrawText("Game over! Press RETURN to play again.", 400 - MeasureText("Game over! Press RETURN to play again.", 20) / 2, 50, 20, LIGHTGRAY);
}

void updateGameOverScene() {
    drawGameOverScene();

    if (IsKeyPressed(KEY_ENTER)) {
        publicvariables::scene = 1; 
    }
}

void runGameOverScene() {
    updateGameOverScene();
}
