#include "game.h"

void DrawBoard();
void DrawHomeArea(Vector2 center, float size, Color color);
void DrawPath();
void DrawCenterArea();

// Board dimensions
const float BOARD_SIZE = 600.0f;
const float CELL_SIZE = BOARD_SIZE / 15.0f;  // 15x15 grid
const Vector2 BOARD_CENTER = {WinW/2.0f, WinH/2.0f};

void Draw() {
    DrawBoard();
}

void DrawBoard() {
    BeginDrawing();
        ClearBackground(WHITE);
        
        // Draw board background
        Rectangle boardRect = {
            BOARD_CENTER.x - BOARD_SIZE/2,
            BOARD_CENTER.y - BOARD_SIZE/2,
            BOARD_SIZE,
            BOARD_SIZE
        };
        DrawRectangleRec(boardRect, LIGHTGRAY);
        DrawRectangleLinesEx(boardRect, 3, BLACK);
        
        // Draw the four home areas (triangular sections)
        DrawHomeArea({BOARD_CENTER.x - BOARD_SIZE/4, BOARD_CENTER.y - BOARD_SIZE/4}, BOARD_SIZE/4, RED);     // Top-left (Red)
        DrawHomeArea({BOARD_CENTER.x + BOARD_SIZE/4, BOARD_CENTER.y - BOARD_SIZE/4}, BOARD_SIZE/4, BLUE);    // Top-right (Blue)
        DrawHomeArea({BOARD_CENTER.x - BOARD_SIZE/4, BOARD_CENTER.y + BOARD_SIZE/4}, BOARD_SIZE/4, GREEN);   // Bottom-left (Green)
        DrawHomeArea({BOARD_CENTER.x + BOARD_SIZE/4, BOARD_CENTER.y + BOARD_SIZE/4}, BOARD_SIZE/4, YELLOW);  // Bottom-right (Yellow)
        
        // Draw the cross-shaped path
        DrawPath();
        
        // Draw center home area
        DrawCenterArea();
        
    EndDrawing();
}

void DrawHomeArea(Vector2 center, float size, Color color) {
    // Draw the square home area
    Rectangle homeRect = {center.x - size/2, center.y - size/2, size, size};
    DrawRectangleRec(homeRect, color);
    DrawRectangleLinesEx(homeRect, 2, BLACK);
    
    // Draw the triangle in the center pointing toward the board center
    Vector2 triangleCenter = center;
    float triangleSize = size * 0.3f;
    
    Vector2 p1, p2, p3;
    
    // Determine triangle orientation based on position relative to board center
    if (center.x < BOARD_CENTER.x && center.y < BOARD_CENTER.y) {
        // Top-left (Red) - triangle points to bottom-right
        p1 = {triangleCenter.x - triangleSize/2, triangleCenter.y - triangleSize/2};
        p2 = {triangleCenter.x + triangleSize/2, triangleCenter.y + triangleSize/2};
        p3 = {triangleCenter.x - triangleSize/2, triangleCenter.y + triangleSize/2};
    } else if (center.x > BOARD_CENTER.x && center.y < BOARD_CENTER.y) {
        // Top-right (Blue) - triangle points to bottom-left
        p1 = {triangleCenter.x + triangleSize/2, triangleCenter.y - triangleSize/2};
        p2 = {triangleCenter.x - triangleSize/2, triangleCenter.y + triangleSize/2};
        p3 = {triangleCenter.x + triangleSize/2, triangleCenter.y + triangleSize/2};
    } else if (center.x < BOARD_CENTER.x && center.y > BOARD_CENTER.y) {
        // Bottom-left (Green) - triangle points to top-right
        p1 = {triangleCenter.x - triangleSize/2, triangleCenter.y + triangleSize/2};
        p2 = {triangleCenter.x + triangleSize/2, triangleCenter.y - triangleSize/2};
        p3 = {triangleCenter.x - triangleSize/2, triangleCenter.y - triangleSize/2};
    } else {
        // Bottom-right (Yellow) - triangle points to top-left
        p1 = {triangleCenter.x + triangleSize/2, triangleCenter.y + triangleSize/2};
        p2 = {triangleCenter.x - triangleSize/2, triangleCenter.y - triangleSize/2};
        p3 = {triangleCenter.x + triangleSize/2, triangleCenter.y - triangleSize/2};
    }
    
    DrawTriangle(p1, p2, p3, WHITE);
    DrawTriangleLines(p1, p2, p3, BLACK);
}

void DrawPath() {
    float pathWidth = CELL_SIZE * 3;  // 3 cells wide
    
    // Horizontal paths (left and right arms)
    Rectangle leftPath = {
        BOARD_CENTER.x - BOARD_SIZE/2,
        BOARD_CENTER.y - pathWidth/2,
        BOARD_SIZE/2 - pathWidth/2,
        pathWidth
    };
    Rectangle rightPath = {
        BOARD_CENTER.x + pathWidth/2,
        BOARD_CENTER.y - pathWidth/2,
        BOARD_SIZE/2 - pathWidth/2,
        pathWidth
    };
    
    // Vertical paths (top and bottom arms)
    Rectangle topPath = {
        BOARD_CENTER.x - pathWidth/2,
        BOARD_CENTER.y - BOARD_SIZE/2,
        pathWidth,
        BOARD_SIZE/2 - pathWidth/2
    };
    Rectangle bottomPath = {
        BOARD_CENTER.x - pathWidth/2,
        BOARD_CENTER.y + pathWidth/2,
        pathWidth,
        BOARD_SIZE/2 - pathWidth/2
    };
    
    // Draw paths
    DrawRectangleRec(leftPath, WHITE);
    DrawRectangleRec(rightPath, WHITE);
    DrawRectangleRec(topPath, WHITE);
    DrawRectangleRec(bottomPath, WHITE);
    
    // Draw path borders
    DrawRectangleLinesEx(leftPath, 2, BLACK);
    DrawRectangleLinesEx(rightPath, 2, BLACK);
    DrawRectangleLinesEx(topPath, 2, BLACK);
    DrawRectangleLinesEx(bottomPath, 2, BLACK);
    
    // Draw individual cells in the path
    for (int i = 0; i < 15; i++) {
        // Top row
        if (i < 6 || i > 8) {
            Rectangle cell = {
                BOARD_CENTER.x - BOARD_SIZE/2 + i * CELL_SIZE,
                BOARD_CENTER.y - pathWidth/2,
                CELL_SIZE,
                CELL_SIZE
            };
            DrawRectangleLinesEx(cell, 1, GRAY);
        }
        
        // Bottom row
        if (i < 6 || i > 8) {
            Rectangle cell = {
                BOARD_CENTER.x - BOARD_SIZE/2 + i * CELL_SIZE,
                BOARD_CENTER.y + pathWidth/2 - CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE
            };
            DrawRectangleLinesEx(cell, 1, GRAY);
        }
        
        // Left column
        if (i < 6 || i > 8) {
            Rectangle cell = {
                BOARD_CENTER.x - pathWidth/2,
                BOARD_CENTER.y - BOARD_SIZE/2 + i * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE
            };
            DrawRectangleLinesEx(cell, 1, GRAY);
        }
        
        // Right column
        if (i < 6 || i > 8) {
            Rectangle cell = {
                BOARD_CENTER.x + pathWidth/2 - CELL_SIZE,
                BOARD_CENTER.y - BOARD_SIZE/2 + i * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE
            };
            DrawRectangleLinesEx(cell, 1, GRAY);
        }
    }
    
    // Draw safe zones (colored cells)
    // Red safe zone
    Rectangle redSafe = {
        BOARD_CENTER.x - BOARD_SIZE/2 + CELL_SIZE,
        BOARD_CENTER.y - CELL_SIZE/2,
        CELL_SIZE,
        CELL_SIZE
    };
    DrawRectangleRec(redSafe, RED);
    DrawRectangleLinesEx(redSafe, 1, BLACK);
    
    // Blue safe zone
    Rectangle blueSafe = {
        BOARD_CENTER.x - CELL_SIZE/2,
        BOARD_CENTER.y - BOARD_SIZE/2 + CELL_SIZE,
        CELL_SIZE,
        CELL_SIZE
    };
    DrawRectangleRec(blueSafe, BLUE);
    DrawRectangleLinesEx(blueSafe, 1, BLACK);
    
    // Green safe zone
    Rectangle greenSafe = {
        BOARD_CENTER.x + BOARD_SIZE/2 - 2 * CELL_SIZE,
        BOARD_CENTER.y - CELL_SIZE/2,
        CELL_SIZE,
        CELL_SIZE
    };
    DrawRectangleRec(greenSafe, GREEN);
    DrawRectangleLinesEx(greenSafe, 1, BLACK);
    
    // Yellow safe zone
    Rectangle yellowSafe = {
        BOARD_CENTER.x - CELL_SIZE/2,
        BOARD_CENTER.y + BOARD_SIZE/2 - 2 * CELL_SIZE,
        CELL_SIZE,
        CELL_SIZE
    };
    DrawRectangleRec(yellowSafe, YELLOW);
    DrawRectangleLinesEx(yellowSafe, 1, BLACK);
}

void DrawCenterArea() {
    float centerSize = CELL_SIZE * 3;
    Rectangle centerRect = {
        BOARD_CENTER.x - centerSize/2,
        BOARD_CENTER.y - centerSize/2,
        centerSize,
        centerSize
    };
    
    // Draw center area
    DrawRectangleRec(centerRect, GOLD);
    DrawRectangleLinesEx(centerRect, 3, BLACK);
    
    // Draw center triangle (pointing up)
    Vector2 p1 = {BOARD_CENTER.x, BOARD_CENTER.y - centerSize/4};
    Vector2 p2 = {BOARD_CENTER.x - centerSize/4, BOARD_CENTER.y + centerSize/4};
    Vector2 p3 = {BOARD_CENTER.x + centerSize/4, BOARD_CENTER.y + centerSize/4};
    
    DrawTriangle(p1, p2, p3, WHITE);
    DrawTriangleLines(p1, p2, p3, BLACK);
}
