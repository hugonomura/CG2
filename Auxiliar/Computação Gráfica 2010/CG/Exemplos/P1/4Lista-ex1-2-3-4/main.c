/*
 * main.c
 *
 *  Created on: 05/05/2010
 *      Author: p
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>


struct matriz {
	float a11, a12,a13,a14;
	float a21, a22,a23,a24;
	float a31, a32,a33,a34;
	float a41, a42,a43,a44;
};

typedef struct ponto3D {
	float x,y,z,w;
}Ponto;

struct ponto3D*  Multiplica_Matriz_Vetor(struct matriz* M, Ponto* P){
	Ponto *PMult;
	PMult=(struct ponto3D*) malloc (sizeof(struct ponto3D));
	PMult->x=(M->a11*P->x)+(M->a12*P->y)+(M->a13*P->z)+(M->a14*P->w);
	PMult->y=(M->a21*P->x)+(M->a22*P->y)+(M->a23*P->z)+(M->a24*P->w);
	PMult->z=(M->a31*P->x)+(M->a32*P->y)+(M->a33*P->z)+(M->a34*P->w);
	PMult->w=1;

	return PMult;
}

// Translação
void translacao(Ponto*  P, float dx,float dy,float dz){
	struct matriz M;
	Ponto *PontoTran;
	M.a11=1;M.a12=0;M.a13=0;M.a14=dx;
	M.a21=0;M.a22=1;M.a23=0;M.a24=dy;
	M.a31=0;M.a32=0;M.a33=1;M.a34=dz;
	M.a41=0;M.a42=0;M.a43=0;M.a44=1;
	PontoTran=Multiplica_Matriz_Vetor(&M, P);
	printf("O ponto translado é: (%f",PontoTran->x);
	printf(",%f",PontoTran->y);
	printf(",%f",PontoTran->z);
	printf(",%f",PontoTran->w);
	printf(")\n");

}

void translacao2(Ponto* P, struct matriz* M){
	Ponto *PontoTran2;
	PontoTran2=Multiplica_Matriz_Vetor(M,P);
	printf("O ponto translado é: (%f",PontoTran2->x);
	printf(",%f",PontoTran2->y);
	printf(",%f",PontoTran2->z);
	printf(",%f",PontoTran2->w);
	printf(")\n");
}

//Escalonamento
void escalona(Ponto* P, struct matriz* M) {
	Ponto *PontoEsc;
	PontoEsc=Multiplica_Matriz_Vetor(M, P);
	printf("O ponto escalonado é: (%f",PontoEsc->x);
	printf(",%f",PontoEsc->y);
	printf(",%f",PontoEsc->z);
	printf(",%f",PontoEsc->w);
	printf(")\n");
	fflush(stdout);

}

int main(){

	Ponto P1,P2,P3,P4,P5;
	float dx,dy,dz,sx,sy,ang;
	struct matriz M,N;

	//Pontos:
	P1.x=3; P1.y=3; P1.z=3; P1.w=1;
	P2.x=6; P2.y=3;
	P3.x=6; P3.y=6;
	P4.x=4.5; P4.y=8;
	P5.x=3; P5.y=6;

	//Matriz translaçao: foi utilizada na funcao translaçao2, dx=dy=dz=3
	M.a11=1;M.a12=0;M.a13=0;M.a14=3;
	M.a21=0;M.a22=1;M.a23=0;M.a24=3;
	M.a31=0;M.a32=0;M.a33=1;M.a34=3;
	M.a41=0;M.a42=0;M.a43=0;M.a44=3;

	//Matriz escalonamento: foi utilizada na funcao escalonamento, sx=2,sy=3,sz=4
	M.a11=2;M.a12=0;M.a13=0;M.a14=0;
	M.a21=0;M.a22=3;M.a23=0;M.a24=0;
	M.a31=0;M.a32=0;M.a33=4;M.a34=0;
	M.a41=0;M.a42=0;M.a43=0;M.a44=1;

	translacao(&P1,3,3,3);
	translacao2(&P1,&M);
	escalona(&P1,&M);

}
