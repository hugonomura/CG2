/*   Autor: Gustavo Henrique dos Santos Marcello RA: 317276
	 Programa: 	Geracao e manipulacao grafica de retas
*/

#include <stdio.h>
#include <stdlib.h>
#include <cmath.h>
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

void transladaZ(Ponto *p, int m[][4]){
     p->x *= (m[0][0]+m[0][1]);
     p->y *= (m[1][0]+m[1][1]);
}


void transladaX(Ponto *p, int m[][4]){
     p->x *= (m[0][0]+m[0][1]);
     p->y *= (m[1][0]+m[1][1]);
}


void transladaY(Ponto *p, int m[][4]){
     p->y *= (m[0][0]+m[0][2]);
     p->z *= (m[0][2]+m[2][2]);
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
	int n,i;
	float se, cos, rx, ry, rz;
	
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
    printf("\n");
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
	printf("Rotacionamento x =  ");
	scanf("%d", &rx);	
		
	m[1][2] = -sin(rx*PI/180);
	m[2][2] = cos(rx*PI/180);
	m[2][1] = sin(rx*PI/180);
	m[1][1] = cos(rx*PI/180);	
    
    for(i = 0 ; i < n; i++){          	
          rotacionaX(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }    
    	
	printf("Rotacionamento y = ");
	scanf("%d", &m[1][1]);	
		
	m[2][0] = -sin(ry*PI/180);
	m[0][0] = cos(ry*PI/180);
	m[0][2] = sin(ry*PI/180);
	m[2][2] = cos(ry*PI/180);	
	
    for(i = 0 ; i < n; i++){          	
          rotacionaY(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }    
		
	printf("Rotacionamento z = ");
	scanf("%d", &m[2][2]);
		
	m[0][1] = -sin(rz*PI/180);
	m[0][0] = cos(rz*PI/180);
	m[1][0] = sin(rz*PI/180);
	m[1][1] = cos(rz*PI/180);
	
    for(i = 0 ; i < n; i++){          	
          rotacionaZ(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }    
    
	p = pi;
	 
	for(i = 0 ; i < n; i++){          	
          translada(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }   
    printf("\n");
    system("pause");
	return 0;
}
