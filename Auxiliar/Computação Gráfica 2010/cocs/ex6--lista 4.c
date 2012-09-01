/*   Autor: Gustavo Henrique dos Santos Marcello RA: 317276
	 Programa: 	Geracao e manipulacao grafica de retas
*/

#include <stdio.h>
#include <stdlib.h>
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

void reflexao(Ponto *p, int m[][4]){
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
	int n,i;
	int opc;
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
	printf("Espelha x? (1 - Sim 0 - Nao)\n");
	scanf("%d", &opc);
    if(opc){            
        m[0][0] = -1;
    }else   
        m[0][0] = 1;
   	printf("Espelha y? (1 - Sim 0 - Nao)\n");
	scanf("%d", &opc);	
    if(opc){            
        m[1][1] = -1;
    }else   
		m[1][1] = 1;
	  
	printf("Espelha x? (1 - Sim 0 - Nao)\n");
	scanf("%d", &opc);
    if(opc){            
        m[2][2] = -1;
    }else
           m[2][2] = 1;
	m[3][3] = 1;	   

	p = pi;
	 
	for(i = 0 ; i < n; i++){          	
          reflexao(p,m);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }   
    printf("\n");
    system("pause");
	return 0;
}


/*Resposta:
           Podem ser definidas 7 operacoes de reflexao nos eixos: 
           1- x
           2- y
           3- z
           4- x,y
           5- x,z
           6- y,z
           7- x,y,z
*/
