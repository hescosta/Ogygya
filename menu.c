#include "raylib.h"
#include <stdio.h>
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int sair=0;
Vector2 pos_mouse = {0.0f, 0.0f};
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (sair ==0)  // Checa se o valor que determina saida mudou
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
pos_mouse = GetMousePosition();
            ClearBackground(RAYWHITE);

            DrawText("Iniciar jogo", 350, 350, 50, LIGHTGRAY);
            DrawText("Sair do jogo", 350, 200, 50, LIGHTGRAY);
if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {sair =1;};
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
