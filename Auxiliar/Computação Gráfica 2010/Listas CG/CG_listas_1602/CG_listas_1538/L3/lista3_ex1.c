#include<stdio.h>
#include<math.h>
/* Dados os pontos:

P1 = (3,3)
P2 = (6,3)
P3 = (6,6)
P4 = (4.5,8)
P5 = (3,6)
*/


struct matriz {
	float a11, a12;
	float a21, a22;
};

typedef struct ponto2D {
	float x, y;
}Ponto;

// Translação
void translacao(Ponto*  P, float dx){
	float Px, Py;
	Px=P->x+dx;
	Py=P->y+dx;
	printf("O ponto transladado é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
	fflush(stdout);
	fflush(stdin);
}

//Escalonamento
void escalona(Ponto* P, float sx, float sy) {
	float Px,Py;
	Px=(P->x)*sx;
	Py=(P->y)*sy;
	printf("O ponto escalonado é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
}

//Rotação
void rotacao(Ponto* P, float ang){
	float Px,Py;
	Px=(P->x*cos(ang))-(P->y*sin(ang));
	Py=(P->x*sin(ang))+(P->y*cos(ang));
	printf("O ponto rotacionado é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
}

//Espelhamento- eixo x
void espelhaX(Ponto *P){
	float Px,Py;
	Px=P->x;
	Py=-(P->y);
	printf("O ponto espelhado em relação ao eixo x é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
}

//Espelhamento- eixo y
void espelhaY(Ponto *P){
	float Px,Py;
	Px=-(P->x);
	Py=P->y;
	printf("O ponto espelhado em relação ao eixo y é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
}

//Espelhamento- eixo xy
void espelhaXY(Ponto *P){
	float Px,Py;
	Px=-(P->x);
	Py=-(P->y);
	printf("O ponto espelhado em relação ao eixo y é:(%f", Px);
	printf(",%f",Py);
	printf(")\n");
}


int main(){
	//float x,y;
	Ponto P1,P2,P3,P4,P5;
	float dx,sx,sy,ang;

	//Pontos:
	P1.x=3; P1.y=3;
	P2.x=6; P2.y=3;
	P3.x=6; P3.y=6;
	P4.x=4.5; P4.y=8;
	P5.x=3; P5.y=6;
	printf("Informe quanto deseja transladar:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &dx);
	translacao( &P1, dx);
	printf("Informe quanto deseja escalonar em relação a x:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &sx);
	printf("Informe quanto deseja escalonar em relação a y:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &sy);
	escalona(&P1, sx,sy);
	printf("Informe o ângulo para rotacionar:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &ang);
	rotacao(&P1, ang);
	espelhaX(&P1);
	espelhaY(&P1);
	espelhaXY(&P1);


}
