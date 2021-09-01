int player1score = 0;
int player2score = 0;

int player1x = 50;
int player2x = 750; 

int player1y = 200;
int player2y = 200;

bool sceneRun = false;

struct Ball {
    int x = 400;
    int y = 300;

    int xvel = publicvariables::speed;
    int yvel = publicvariables::speed;
};

struct Ball ball1;

void drawMainScene() {
    ClearBackground(BLACK);

    char buf[12];    

    char buf2[12];

    snprintf(buf, sizeof(buf), "%d : %d", player1score, player2score);

    snprintf(buf2, sizeof(buf2), "%d FPS)", GetFPS());

    DrawText(buf, 400 - MeasureText(buf, 20) / 2, 50, 20, LIGHTGRAY);

    DrawRectangle(player1x, player1y, 25, 100, LIGHTGRAY);
    DrawRectangle(player2x, player2y, 25, 100, LIGHTGRAY);

    DrawRectangle(ball1.x - 15, ball1.y - 15, 15, 15, LIGHTGRAY);

    DrawFPS(400 - MeasureText(buf2, 20) / 2, 100);
}


void updateMainScene() {
    drawMainScene();

    if (!sceneRun) {
        sceneRun = true;
        ball1.xvel = publicvariables::speed;
        ball1.yvel = publicvariables::speed;
    }

    if (ball1.y <= player2y + 50) {
        if (player2y > 0) {
            player2y -= publicvariables::speed - 1;
        }
    } else {
        if (player2y <= 500) {
            player2y += publicvariables::speed;
        }
    }

    if (player1y >= 0) {
        if (IsKeyDown(KEY_W)) {
            player1y -= publicvariables::speed + 1;
        }
    }

    if (player1y <= 500) {
        if (IsKeyDown(KEY_S)) {
            player1y += publicvariables::speed + 1;
        }
    }

    ball1.x += ball1.xvel;
    ball1.y += ball1.yvel;

    if (ball1.y >= 600) {
        ball1.yvel = publicvariables::speed * -1;
        printf("Bounce bottom");
        playCollisionSound();
    }

    if (ball1.y <= 15) {
        ball1.yvel = publicvariables::speed;
        playCollisionSound();
    }

    if (ball1.x <= 15) {
        ball1.xvel = publicvariables::speed;
        playCollisionSound();
    } 

    if (ball1.x >= 800) {
        ball1.xvel = -publicvariables::speed;
        playCollisionSound();
    }

    if (ball1.x <= 95) { // LEFT
        if (ball1.y >= player1y and ball1.y <= player1y + 100) {
            ball1.xvel = publicvariables::speed;
            playCollisionSound();
        }
    } else if (ball1.x >= 750) { // RIGHT
        if (ball1.y >= player2y and ball1.y <= player2y + 100) {
            ball1.xvel = -publicvariables::speed;
            playCollisionSound();
        }
    }

    if (ball1.x <= 70) {
        player2score++;

        ball1.x = 400;
        ball1.y = 300;
    }

    if (ball1.x >= 775) {
        player1score++;
        ball1.x = 400;
        ball1.y = 300;
    }

    if (player2score >= 5) {
        player1score = 0;
        player2score = 0;
        player1y = 200;
        player2y = 200;
        ball1.x = 400;
        ball1.y = 300;
        publicvariables::scene = 2;
    }

    if (player1score >= 5) {
        player1score = 0;
        player2score = 0;
        player1y = 200;
        player2y = 200;
        ball1.x = 400;
        ball1.y = 300;
        publicvariables::scene = 3;
    }
}

void runMainScene() {
    updateMainScene();
}
