#pragma once
#include <raylib.h>
#include<raymath.h>
#include<vector>

#define WinH 800.0F
#define WinW 1000.0F

void InitGame();

void Update();
void Draw();

void LoadGame();
void UnloadGame();