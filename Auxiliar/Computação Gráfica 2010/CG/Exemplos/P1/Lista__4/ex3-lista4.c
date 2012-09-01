/*   Autor: Gustavo Henrique dos Santos Marcello RA: 317276
	 Programa: 	Geracao e manipulacao grafica de retas
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 128
#define PI 3.1415926536


typedef struct  ponto{
	float x,y,z;
    struct ponto *next;	
}Ponto;

/*
typedef struct matriz{
    Ponto a11,a12,a13,a14;
    Ponto a21,a22,a23,a24;
    Ponto a31,a32,a33,a34;
    Ponto a41,a42,a43,a44;
}Matriz
*/

void escalona(Ponto *p, int m[][4]){
     p->x *= m[0][0];
     p->y *= m[1][1];
     p->z *= m[2][2];
}


void inicia_matriz(int m[][4]){
     int i,j;
     for(i = 0; i<4; i++){
           for(j = 0; j<4; j++){        
                   m[i][j] = 0;        
     }}
}


int main(void){

	Ponto *p, *pi, *p2;
	int m[4][4];
	int dx,dy,dz,n,i;
	
	inicia_matriz(m);
	
    printf("Numero de pontos: ");
    scanf("%d", &n);
    p = malloc(sizeof(Ponto));
    pi = p;
    printf("X = ");
    scanf("%f", &p->x);
    printf("Y = ");    
    scanf("%f", &p->y);
    printf("Z = ");
    scanf("%f", &p->z);    
    for(i=0; i<n-1; i++){    
        p2 = malloc(sizeof(Ponto));       
	    printf("X = ");
	    scanf("%f", &p2->x);
	    printf("Y = ");
	    scanf("%f", &p2->y);
	    printf("Z = ");
	    scanf("%f", &p2->z);
        printf("\n");	
	    p->next = p2;
	    p = p2;
    }
    p->next = NULL;    
	printf("Escalonamento x =  ");
	scanf("%d", &m[0][0]);
	
	printf("Escalonamento y = ");
	scanf("%d", &m[1][1]);
		
	printf("Escalonamento z = ");
	scanf("%d", &m[2][2]);
	m[3][3] = 1;
	p = pi;
	 printf("\nPonto1 = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
	for(i = 0 ; i < n; i++){          	
          escalona(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }   
    printf("\n");
    system("pause");
	return 0;
}
