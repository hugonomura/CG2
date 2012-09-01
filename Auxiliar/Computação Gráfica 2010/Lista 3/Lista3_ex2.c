/*
 * main.c
 *
 *  Created on: 04/05/2010
 *      Author: p
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


struct matriz {
	float a11, a12,a13;
	float a21, a22,a23;
	float a31, a32,a33;
};

typedef struct ponto2D {
	float x,y,w;
}Ponto;

struct ponto2D*  Multiplica_Matriz_Vetor(struct matriz* M, Ponto* P){
	Ponto *PMult;
	PMult=(struct ponto2D*) malloc (sizeof(struct ponto2D));
	PMult->x=(M->a11*P->x)+(M->a12*P->y)+(M->a13*P->w);
	PMult->y=(M->a21*P->x)+(M->a22*P->y)+(M->a23*P->w);
	PMult->w=1;

	return PMult;
}

// Translação
void translacao(Ponto*  P, float dx,float dy){
	struct matriz M;
	Ponto *PontoTran;
	M.a11=1;M.a12=0;M.a13=dx;
	M.a21=0;M.a22=1;M.a23=dy;
	M.a31=0;M.a32=0;M.a33=1;
	PontoTran=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto translado é: (%f",PontoTran->x);
	printf(",%f",PontoTran->y);
	printf(",%f",PontoTran->w);
	printf(")\n");

}

//Escalonamento
void escalona(Ponto* P, float sx, float sy) {
	struct matriz M;
	Ponto *PontoEsc;
	M.a11=sx;M.a12=0;M.a13=0;
	M.a21=0;M.a22=sy;M.a23=0;
	M.a31=0;M.a32=0;M.a33=1;
	PontoEsc=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto escalonado é: (%f",PontoEsc->x);
	printf(",%f",PontoEsc->y);
	printf(",%f",PontoEsc->w);
	printf(")\n");
	fflush(stdout);


}

//Rotação
void rotacao(Ponto* P, float ang){
	struct matriz M;
	Ponto *PontoRot;
	M.a11=cos(ang);M.a12=-sin(ang);M.a13=0;
	M.a21=sin(ang);M.a22=cos(ang);M.a23=0;
	M.a31=0;M.a32=0;M.a33=1;
	PontoRot=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto rotacionado é: (%f",PontoRot->x);
	printf(",%f",PontoRot->y);
	printf(",%f",PontoRot->w);
	printf(")\n");
}

//Espelhamento- eixo x
void espelhaX(Ponto *P){
	struct matriz M;
	Ponto *PontoEspX;
	M.a11=1;M.a12=0;M.a13=0;
	M.a21=0;M.a22=-1;M.a23=0;
	M.a31=0;M.a32=0;M.a33=1;
	PontoEspX=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto espelhado em relação ao eixo x é: (%f",PontoEspX->x);
	printf(",%f",PontoEspX->y);
	printf(",%f",PontoEspX->w);
	printf(")\n");
}

//Espelhamento- eixo y
void espelhaY(Ponto *P){
	struct matriz M;
	Ponto *PontoEspY;
	M.a11=-1;M.a12=0;M.a13=0;
	M.a21=0;M.a22=1;M.a23=0;
	M.a31=0;M.a32=0;M.a33=1;
	PontoEspY=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto espelhado em relação ao eixo y é: (%f",PontoEspY->x);
	printf(",%f",PontoEspY->y);
	printf(",%f",PontoEspY->w);
	printf(")\n");
}

//Espelhamento- eixo xy
void espelhaXY(Ponto *P){
	struct matriz M;
	Ponto *PontoEspXY;
	M.a11=-1;M.a12=0;M.a13=0;
	M.a21=0;M.a22=-1;M.a23=0;
	M.a31=0;M.a32=0;M.a33=1;
	PontoEspXY=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto espelhado em relação ao eixo xy é: (%f",PontoEspXY->x);
	printf(",%f",PontoEspXY->y);
	printf(",%f",PontoEspXY->w);
	printf(")\n");
}



int main(){
	Ponto P1,P2,P3,P4,P5;
	float dx,sx,sy,ang;

	//Pontos:
	P1.x=3; P1.y=3; P1.w=1;
	P2.x=6; P2.y=3;
	P3.x=6; P3.y=6;
	P4.x=4.5; P4.y=8;
	P5.x=3; P5.y=6;

	translacao(&P1,3,3);
	escalona(&P1,2,3);
	rotacao(&P1,90);
	espelhaX(&P1);
	espelhaY(&P1);
	espelhaXY(&P1);
}
/*Resposta: Não conseguiria fazer isso sem coordenadas homogêneas, pois a translação seria feita
com soma e não com multiplicação. */
