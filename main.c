#include "raylib.h"
#include <stdio.h>
#include "mapa.h"
#include <time.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1080;
    const int screenHeight = 720;
    int larg, alt = 0;
    char matrix[MAPA_MAX][MAPA_MAX] = {0};
    FILE *arq;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    //abrindo arquivo do mapa
    arq = fopen("mapa.txt","r");
    if(arq == NULL){
    	printf("Erro de abertura, encerrando...\n");
	return 0;
    }
    
    //lendo valores do arquivo
    fscanf(arq, "%d ",&alt);
    fscanf(arq, "%d ",&larg);
   
    //tirar dps
    printf("Altura: %d\n",alt);
    printf("Largura: %d\n",larg);

    for(int i=0; i<alt; i++){
   	for (int j=0; j<larg+1; j++){
		matrix[i][j] = getc(arq);
	}
    }

    print_matrix(alt, larg, matrix);



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())  // Checa se o valor que determina saida mudou
    {
	// Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

	
	//testando grade do mapa, imprimindo retangulos 
	for (int i=0; i<alt; i++){
		for (int j=0; j<larg; j++){
			if(matrix[i][j]=='#'){
				DrawRectangle(i*30, j*30, 30, 30, DARKGRAY);
			}else{
				DrawRectangle(i*30, j*30, 30, 30, DARKBROWN);
				
			}
		}
	}

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
