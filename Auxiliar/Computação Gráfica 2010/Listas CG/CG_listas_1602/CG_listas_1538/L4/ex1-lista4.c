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

void translada(Ponto *p, int dx, int dy, int dz){
     p->x += dx;
     p->y += dy;
     p->z += dz;
}



int main(void){
	Ponto *p, *pi, *p2;
	int dx,dy,dz,n,i;
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
	printf("Deslocamento x = ");
	scanf("%d", &dx);
	
	printf("Deslocamento y = ");
	scanf("%d", &dy);
		
	printf("Deslocamento z = ");
	scanf("%d", &dz);
	
	p = pi;
	 printf("\nPonto1 = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
	for(i = 0 ; i < n; i++){          	
          translada(p, dx,dy,dz);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", p->x, p->y, p->z);   
          p = p->next;
    }   
    printf("\n");
    system("pause");
	return 0;
}
