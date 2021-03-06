// LISTA 05 // EXERCICIO 01

#include<stdio.h>

//Estrutura para representacao de um ponto no espaço tridimensional homogêneo
typedef struct ponto3D {
	float x, y, z, W;
}Ponto;

typedef struct ponto2D {
	float x, y, W;
}Ponto2D;

void planta(Ponto2D* iP, Ponto* P){
	iP->x = P->x;
	iP->y = P->z;
}

lateral(Ponto2D* iP, Ponto* P){
	iP->x = P->z;
	iP->y = P->y;
}

frontal(Ponto2D* iP, Ponto* P){
	iP->x = P->x;
	iP->y = P->y;
}

int main(){
	Ponto P1, P2, P3, P4;
	Ponto2D iP1, iP2, iP3, iP4;	
	P1.x = 2; P1.y = 2; P1.z = 2; P1.W = 1;
	P2.x = 2; P2.y = 2; P2.z = -2; P2.W = 1;
	P3.x = -2; P3.y = -2; P3.z = -2; P3.W = 1;
	P4.x = -2; P4.y = -2; P4.z = 2; P4.W = 1;

	//Ponto 1
	planta(&iP1, &P1);
	printf("P1 depois da funcao planta eh: (%f, %f)\n",iP1.x,iP1.y);
	lateral(&iP1, &P1);
	printf("P1 depois da funcao lateral eh: (%f, %f)\n",iP1.x,iP1.y);
	frontal(&iP1, &P1);
	printf("P1 depois da funcao frontal eh: (%f, %f)\n\n",iP1.x,iP1.y);

	planta(&iP2, &P2);
	printf("P2 depois da funcao planta eh: (%f, %f)\n",iP2.x,iP2.y);
	lateral(&iP2, &P2);
	printf("P2 depois da funcao lateral eh: (%f, %f)\n",iP2.x,iP2.y);
	frontal(&iP2, &P2);
	printf("P2 depois da funcao frontal eh: (%f, %f)\n\n",iP2.x,iP2.y);

	planta(&iP3, &P3);
	printf("P3 depois da funcao planta eh: (%f, %f)\n",iP3.x,iP3.y);
	lateral(&iP3, &P3);
	printf("P3 depois da funcao lateral eh: (%f, %f)\n",iP3.x,iP3.y);
	frontal(&iP3, &P3);
	printf("P3 depois da funcao frontal eh: (%f, %f)\n\n",iP3.x,iP3.y);


	planta(&iP4, &P4);
	printf("P4 depois da funcao planta eh: (%f, %f)\n",iP4.x,iP4.y);
	lateral(&iP4, &P4);
	printf("P4 depois da funcao lateral eh: (%f, %f)\n",iP4.x,iP4.y);
	frontal(&iP4, &P4);
	printf("P4 depois da funcao frontal eh: (%f, %f)\n\n",iP4.x,iP4.y);
}


