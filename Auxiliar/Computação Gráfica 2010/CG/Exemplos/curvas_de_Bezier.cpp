#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1415

//Estrutura para representacao da matriz de transformacao linear sobre um ponto no espaço tridimensional homogêneo
typedef struct matriz4x4 {
	float a11, a12, a13, a14;
	float a21, a22, a23, a24;
	float a31, a32, a33, a34;
	float a41, a42, a43, a44;
}Matriz;

//Estrutura para representacao de um ponto no espaço tridimensional homogêneo
typedef struct ponto3D {
	float x, y, z, W;
}Ponto;

float J(float t, int k) {
	float j =0;
	return j;
}

void p(Ponto* P, float t, int n, Ponto pControle[]){
	int i;
	P->x = 0; P->y = 0; P->z = 0; P->W = 1;
	for(i=0; i < n; i++){
		P->x += pControle[i].x * J(t,0);
		P->y += pControle[i].y * J(t,0);
		P->z += pControle[i].z * J(t,0);
	}
}

int main(){
	int n,i;
	float t=0;
	printf("Digite o numero de pontos de controle: ");
	scanf("%d",&n);
	
	Ponto P[6];
	Ponto pControle[n];
	for(i = 0; i < n; i++){
		printf("\nDigite as coordenadas do ponto de controle %d: ",i);
		scanf("%f",&pControle[i].x);
		scanf("%f",&pControle[i].y);
		scanf("%f",&pControle[i].z);
		pControle[i].W = 1;
	}

	printf("\n\nOs Pontos de Controle sao:\n");
	for(i = 0; i < n; i++){
		printf("\t(%.2f,%.2f, %.2f, %.2f)\n", pControle[i].x, pControle[i].y, pControle[i].z, pControle[i].W);
	}
	
	i = 0;
	while(t<=1){
		p(&P[i],t, n, pControle);
		t += 0.2;
		i++;
	}
	
	printf("\n");
	return 0;
}
