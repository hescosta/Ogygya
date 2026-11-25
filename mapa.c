#include <stdio.h>
#include "mapa.h"

void print_matrix(int alt, int larg, char matrix[MAPA_MAX][MAPA_MAX]){
	for(int i=0; i<alt; i++){
		for(int j=0; j<larg; j++){
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}
}
