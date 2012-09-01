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

void reflexao(Ponto *p, float m[][4]){  
    int opc,i,j;   
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
	  
	printf("Espelha z? (1 - Sim 0 - Nao)\n");
	scanf("%d", &opc);
    if(opc){            
        m[2][2] = -1;
    }else
           m[2][2] = 1;
	m[3][3] = 1;	   
	printf("Matriz Reflexao: ");
     	 for(i=0;i<4;i++){
                      printf("\n");
 	  	 for(j=0;j<4;j++){                      
                                                printf(" %.1f ", m[i][j]);         }
                                                } 

}

void rotaciona(Ponto *p, float m[][4]){
    float se, cos, rx, ry, rz;
    int opc,i,j;
    printf("\n\nEm torno de qual eixo deseja rotacionar?");
    printf("\n1 - x");
    printf("\n2 - y");
    printf("\n3 - z\n");
    scanf("%d",&opc);
    if(opc==1){
    printf("Rotacionamento x =  ");
	scanf("%f", &rx);	
		
	m[1][2] = -sin(rx*PI/180);
	//m[2][2] = cos(rx*PI/180);
	m[2][2] = 3; //temp soh para teste
	m[2][1] = sin(rx*PI/180);
	//m[1][1] = cos(rx*PI/180);	
	m[1][1] = 4; //temp para teste
	m[0][0] =  1;
	m[3][3] = 1;
	
    }
    if(opc==2){
	printf("Rotacionamento y = ");
	scanf("%f", &ry);	
		
	m[2][0] = -sin(ry*PI/180);
//	m[0][0] = cos(ry*PI/180);
	m[0][2] = sin(ry*PI/180);
 //	m[2][2] = cos(ry*PI/180);	
    m[1][1] = 1;
    m[3][3] = 1;
}
if(opc==3){
	printf("Rotacionamento z = ");
	scanf("%f", &rz);
		
	m[0][1] = -sin(rz*PI/180);
//	m[0][0] = cos(rz*PI/180);
	m[1][0] = sin(rz*PI/180);
//	m[1][1] = cos(rz*PI/180);     
    m[2][2] = 1;
    m[3][3] = 1;

}printf("Matriz Rotacao: ");
     	 for(i=0;i<4;i++){
                      printf("\n");
 	  	 for(j=0;j<4;j++){                      
                                                printf(" %.1f ", m[i][j]);         }
                                                } 

}

void translada(Ponto *p,float m[][4] ){
     int i,j;
     printf("Deslocamento x = ");
	 scanf("%f", &m[0][3]);
	 
	 printf("Deslocamento y = ");
     scanf("%f", &m[1][3]);
		
	 printf("Deslocamento z = ");
	 scanf("%f", &m[2][3]);
	 m[0][0] = 1;
 	 m[1][1] = 1;
 	 m[2][2] = 1;
 	 m[3][3] = 1;
 	 printf("Matriz Translacao: ");
 	 for(i=0;i<4;i++){
                      printf("\n");
 	  	 for(j=0;j<4;j++){                      
                                                printf(" %.1f ", m[i][j]);         }
                                                } 

}

void inicia_matriz(float m[][4]){
     int i,j;
     for(i = 0; i<4; i++){
           for(j = 0; j<4; j++){        
                   m[i][j] = 0;        
     }}
}

void escalona(Ponto *p, float m[][4]){
     int x,y,z,i,j;     
    printf("Escalonamento x =  ");
	scanf("%d", &x);
	m[0][0] = x;
	printf("Escalonamento y = ");
	scanf("%d", &y);
    m[1][1] = y;
	printf("Escalonamento z = ");
	scanf("%d", &z);
	m[2][2] = z;
	m[3][3] = 1;
	printf("Matriz escala: ");
 	 for(i=0;i<4;i++){
                      printf("\n");
 	  	 for(j=0;j<4;j++){                      
                                                printf(" %.1f ", m[i][j]);         }
                                                } 

}

void multiplica(float m[][4], float m1[][4], float m2[][4]){
     int i,j,k;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			m[i][j] = 0;
			for(k = 0; k < 4; k++) {
				m[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void multiplica2(float m[][1], float m1[][4], float m2[][1]){
     int i,j,k;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 1; j++) {
			m[i][j] = 0;
			for(k = 0; k < 4; k++) {
				m[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}    



int main(void){

	Ponto *p, *pi, *p2;
	float m[4][4],m1[4][4],m2[4][4], mp[4][1],mpa[4][1];
	int n,i,j;
	int opc,aux = 0;
	inicia_matriz(m);
	inicia_matriz(m1);
	inicia_matriz(m2);
	
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
	p = pi;
	
	do{
    inicia_matriz(m2);
	printf("Operacao que deseja aplicar: ");	
    printf("\n1 - Translacao\n");
	printf("2 - Rotacao\n");
	printf("3 - Escalonamento\n");
    printf("4 - Reflexao\n");
    printf("5 - Terminar\n");
    scanf("%d", &opc);
    switch(opc){                
                case 1:
                      translada(p,m2);
                      break;
                case 2:
        	          rotaciona(p,m2);
        	          break;
                case 3:
                      escalona(p,m2);
                      break;
                case 4:
                      reflexao(p,m2);
                      break;
                case 5: 
                     break;
    }
    	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
    m1[i][j] = m[i][j];
}}
if(aux>0&&opc!=5)
multiplica(m,m1,m2);
else {if(opc!=5){
    for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
              m[i][j] = m2[i][j];
}}
     }}

printf("\n\nMatriz resultante: ");
 	 for(i=0;i<4;i++){
                      printf("\n");
 	  	 for(j=0;j<4;j++){                      
                                                printf(" %.1f ", m[i][j]);         }
                                                }
                                                aux=1; 
 }while(opc!=5);
 
for(i = 0 ; i < n; i++){
          mpa[0][0] =  p->x;
          mpa[1][0] =  p->y;
          mpa[2][0] =  p->z;
          mpa[3][0] =  1;
          multiplica2(mp,m,mpa);
          printf("\nPonto = (%.1f, %.1f, %.1f)\n", mp[0][0], mp[1][0],mp[2][0]);   
          p = p->next;
    }   
    printf("\n");
    system("pause");
	return 0;
}


