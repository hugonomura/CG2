#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 30
#define PI 3.1415

void transPoint(int x, int y, char imagem[MAXIMO][MAXIMO]){
     x = x+(MAXIMO/2);
     y = y+(MAXIMO/2);
     printf("\n\nDepois da transposicao: %d %d\n", x, y);
     imagem[x][y] = 219;
}

void rotacionaPoint(int x, int y, char imagem[MAXIMO][MAXIMO]){
    x = (x * cos(PI/4)) + (y * (- sin(PI/4))) ;
    y = (x * sin(PI/4)) + (y * cos(PI/4));
    printf("\n\nAntes da transposicao: %d %d\n", x, y);
    transPoint(x,y, imagem);
}

int main(void) {

	float x1, y1, x2, y2, a, b, x, y;
	int i,j;

	char imagem[MAXIMO][MAXIMO];

	printf("Digite as coordenadas do ponto A:\n");
	scanf("%f %f", &x1, &y1);
	printf("Digite as coordenadas do ponto B:\n");
	scanf("%f %f", &x2, &y2);

	/*if(x1 == x2) exit(1);
	else {
		a = (y2-y1)/(x2-x1);
		b = y1 - a*x1;
	}*/

	for(j=0; j < MAXIMO; j++){
		for(i=0; i < MAXIMO; i++){
			imagem[i][j] = '.';
		}
	}

	/*i = x1;
	j = MAXIMO - y1;

	imagem[j][i] = 219;

	i = x2;
	j = MAXIMO - y2;

	imagem[j][i] = 219;

	x = x1+1;
	y = a*x + b;*/

	/*while (y < y2 - 1.0){
		i = x;
		j = MAXIMO - y;
		
		imagem[j][i] = 219;

		y = a*(++x) + b;
	}*/

	/*for(j=0; j < MAXIMO; j++){
		for(i=0; i < MAXIMO; i++){
			printf("%c ",imagem[j][i]);
		}
		printf("\n");
	}*/
	
	printf("\n");

    printf("\n");
    
    printf("Hoje eh dia de CQC!\n\n");
	
	transPoint(x1,y1, imagem);
	transPoint(x2,y2, imagem);
	
    rotacionaPoint(x1,y1, imagem);
    rotacionaPoint(x2,y2, imagem);
    
    for(j=0; j < MAXIMO; j++){
		for(i=0; i < MAXIMO; i++){
			printf("%c ",imagem[j][i]);
		}
		printf("\n");
	}
    printf("\n");
    printf("\n");
    getchar();
	getchar();
}
