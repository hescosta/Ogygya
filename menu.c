#include "raylib.h"
#include <stdio.h>
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int sair=0;
    int pos_mouse_x;
	int pos_mouse_y;
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
pos_mouse_x = GetMouseX();
pos_mouse_y = GetMouseY();
            ClearBackground(RAYWHITE);

            DrawText("Iniciar jogo", 200, 130, 70, BLACK);
            DrawText("Sair do jogo", 190, 230, 70, BLACK);

	    //inicio do primeiro botao
	    DrawPixel(190, 130, RED);

	    //fim do primeiro botao
	    DrawPixel(610, 210, RED);

	    //inicio do segundo botao
	    DrawPixel(620,310, RED);

	    //fim do segundo botao
	    DrawPixel(174,230, RED);

if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (pos_mouse_x > 173) && (pos_mouse_x < 621) && (pos_mouse_y > 229) && (pos_mouse_y < 311)) {sair =1;};
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
