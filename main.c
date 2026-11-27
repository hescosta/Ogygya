#include "raylib.h"
#include <stdio.h>
#include "mapa.h"
#include <time.h>
#define CC  (Color){52, 56, 66, 255 }      // Cinza para Caverna
#define MT  (Color){ 122, 86, 62, 255 }      // Marrom de Trilha
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1440;
    const int screenHeight = 720;
	typedef struct {
	int	posx; 
	int	posy;
	int energia;
} Player;
	Player player;
	player.energia = 25;
	player.posx = 1;
	player.posy =5;
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
	for (int i=0; i<larg; i++){
		for (int j=0; j<alt; j++){
			if(matrix[j][i]=='#'){
				DrawRectangle(i*90, j*90, 90, 90, CC);
			}else if(matrix[j][i]=='C'){DrawRectangle(i*90, j*90, 90, 90, YELLOW);
			}else if(matrix[j][i]=='R'){DrawRectangle(i*90, j*90, 90, 90, GREEN);
			}else if(matrix[j][i]=='A'){DrawRectangle(i*90, j*90, 90, 90, RED);
			}else if(matrix[j][i]=='E'){DrawRectangle(i*90, j*90, 90, 90, PURPLE);
			}else if(matrix[j][i]=='S'){DrawRectangle(i*90, j*90, 90, 90, BLUE);
			}else{
				DrawRectangle(i*90, j*90, 90, 90, MT);}
				
		
		}
	}
if( matrix[player.posy][player.posx] == 'R'){player.energia = player.energia +5; matrix[player.posy][player.posx] = '.';}
		if(IsKeyPressed(KEY_W) && matrix[player.posy-1][player.posx] != '#'){ player.posy = player.posy -1 ; player.energia = player.energia-1;}
		if(IsKeyPressed(KEY_S) && matrix[player.posy+1][player.posx] != '#'){ player.posy = player.posy +1 ; player.energia = player.energia-1;}
		if(IsKeyPressed(KEY_A) && matrix[player.posy][player.posx-1] != '#'){ player.posx = player.posx -1 ; player.energia = player.energia-1;} 
		if(IsKeyPressed(KEY_D) && matrix[player.posy][player.posx+1] != '#'){ player.posx = player.posx +1 ; player.energia = player.energia-1;}  
		DrawRectangle(player.posx*90, player.posy*90, 90, 90, PINK);
		if(player.energia == 0){CloseWindow(); return 0;}
        EndDrawing();
	
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
