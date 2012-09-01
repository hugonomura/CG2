// LISTA 05 // EXERCICIO 01

#include<stdio.h>

//Estrutura para representacao de um ponto no espaço tridimensional homogêneo
typedef struct ponto3D {
	float x, y, z, W;
}Ponto;


void planta(Ponto* iP, Ponto* P){
	iP->x = P->x;
	iP->y = 0;
	iP->z = P->z;
}

lateral(Ponto* iP, Ponto* P){//preciso do y e do z
	iP->x = 0;
	iP->y = P->y;
	iP->z = P->z;
}

frontal(Ponto* iP, Ponto* P){
	iP->x = P->x;
	iP->y = P->y;
	iP->z = 0;
}

int main(){
	Ponto P1, P2, P3, P4;                                            
	Ponto iP1, iP2, iP3, iP4;	       //                              |
	P1.x = 2; P1.y = 2; P1.z = 2; P1.W = 1; //                         |
	P2.x = 2; P2.y = 2; P2.z = -2; P2.W = 1; //                        |
	P3.x = -2; P3.y = -2; P3.z = -2; P3.W = 1;                      
	P4.x = -2; P4.y = -2; P4.z = 2; P4.W = 1;                        

	//Ponto 1
	planta(&iP1, &P1);
	printf("P1 depois da funcao planta eh: (%f, %f, %f)\n",iP1.x,iP1.y,iP1.z);
	lateral(&iP1, &P1);
	printf("P1 depois da funcao lateral eh: (%f, %f, %f)\n",iP1.x,iP1.y,iP1.z);
	frontal(&iP1, &P1);
	printf("P1 depois da funcao frontal eh: (%f, %f, %f)\n\n",iP1.x,iP1.y,iP1.z);

	planta(&iP2, &P2);
	printf("P2 depois da funcao planta eh: (%f, %f, %f)\n",iP2.x,iP2.y,iP2.z);
	lateral(&iP2, &P2);
	printf("P2 depois da funcao lateral eh: (%f, %f, %f)\n",iP2.x,iP2.y,iP2.z);
	frontal(&iP2, &P2);
	printf("P2 depois da funcao frontal eh: (%f, %f, %f)\n\n",iP2.x,iP2.y,iP2.z);

	planta(&iP3, &P3);
	printf("P3 depois da funcao planta eh: (%f, %f, %f)\n",iP3.x,iP3.y,iP3.z);
	lateral(&iP3, &P3);
	printf("P3 depois da funcao lateral eh: (%f, %f, %f)\n",iP3.x,iP3.y,iP3.z);
	frontal(&iP3, &P3);
	printf("P3 depois da funcao frontal eh: (%f, %f, %f)\n\n",iP3.x,iP3.y,iP3.z);


	planta(&iP4, &P4);
	printf("P4 depois da funcao planta eh: (%f, %f, %f)\n",iP4.x,iP4.y,iP4.z);
	lateral(&iP4, &P4);
	printf("P4 depois da funcao lateral eh: (%f, %f, %f)\n",iP4.x,iP4.y,iP4.z);
	frontal(&iP4, &P4);
	printf("P4 depois da funcao frontal eh: (%f, %f, %f)\n\n",iP4.x,iP4.y,iP4.z);
}


