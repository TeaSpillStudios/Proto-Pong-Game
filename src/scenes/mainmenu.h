void runMainMenuScene() {
	ClearBackground(BLACK);

	DrawText("Main menu scene!", 10, 10, 20, LIGHTGRAY);

	if (GuiButton(rec, "#05#Load Main Scene!")) {
		strrcpy(scene, "main");
	}
}
