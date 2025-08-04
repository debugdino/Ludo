#include "game.h"

void DrawCentre();
void DrawHome();

void Draw() {
    BeginDrawing();
    ClearBackground(WHITE);
        DrawCentre();
        DrawHome();
    EndDrawing();
}

void DrawHome() {
    Rectangle MainRectangle {350.0f, 350.0f, 600, 600};
    DrawRectangleLinesEx(MainRectangle , 3, BLACK);

    Rectangle red {100.0f, 100.0f, 200.0f, 200.0f};
    DrawRectangleRec(red, RED);

    Rectangle blue {100.0f, 100.0f, 200.0f, 200.0f};
    DrawRectangleRec(blue, BLUE);

    Rectangle yellow {100.0f, 100.0f, 200.0f, 200.0f};
    DrawRectangleRec(yellow, YELLOW);
    
    Rectangle green {100.0f, 100.0f, 200.0f, 200.0f};
    DrawRectangleRec(green, GREEN);
}

void DrawCentre () {

}
