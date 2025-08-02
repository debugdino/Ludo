#include "game.h"

int main() {
    InitWindow(WinW, WinH, "Ludo Master");
    SetTargetFPS(90);

    LoadGame();
    InitGame();
    while(!WindowShouldClose()) {
        Update();
        Draw();
    }

    UnloadGame();
    CloseWindow();
    return 0;
}