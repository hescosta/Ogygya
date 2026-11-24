#include "raylib.h"
#include <stdio.h>
#include "mapa.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int sair=0;
    int pos_mouse_x;
    int pos_mouse_y;
    int matrix[10][10] = {0};
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    matrix[4][3] = 1;
    matrix[3][1] = 1;
    matrix[7][5] = 1;
    matrix[9][8] = 1;

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
	
	//testando grade do mapa, imprimindo retangulos 
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			if(matrix[i][j]==0){
				DrawRectangleLines(i*30, j*30, 30, 30, RED);
			}else{
				DrawRectangle(i*30, j*30, 30, 30, RED);
				
			}
		}
	}

	//inicio do primeiro botao
	DrawPixel(190, 130, RED);

	//fim do primeiro botao
	DrawPixel(610, 210, RED);
        //inicio do segundo botao
	DrawPixel(174,230, RED);
	//fim do segundo botao
	DrawPixel(620,310, RED);

	
	// Botao de 'Sair do Jogo'
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (pos_mouse_x > 173) && (pos_mouse_x < 621) && (pos_mouse_y > 229) && (pos_mouse_y < 311)) {sair =1;};
	    // Botao de 'Iniciar Jogo'
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (pos_mouse_x > 189) && (pos_mouse_x < 611) && (pos_mouse_y > 131) && (pos_mouse_y < 209)) {sair =1;};
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
