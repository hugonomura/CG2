//Exercicio 5 da Lista 5
//Proje��o Paralela

#include<stdio.h>


//Estrutura para representacao da matriz de transformacao linear sobre um ponto no espaço tridimensional homogêneo
struct matriz4x4 {
	float a11, a12, a13, a14;
	float a21, a22, a23, a24;
	float a31, a32, a33, a34;
	float a41, a42, a43, a44;
};

//Estrutura para representacao de um ponto no espaço tridimensional homogêneo
typedef struct ponto3D {
	float x, y, z, W;
}Ponto;

typedef struct vetorEs {
	float a, b, c, d;
}Vetor;

//Metodo que implementa o calculo de cada ponto do objeto no plano
void imagem( Ponto* iP, Ponto* P, Ponto* W, Vetor* normal){
	float lambda=0;

	//Calculo do lambda
	lambda = (- normal->a*(P->x - W->x) -normal->b*(P->y - W->y) -normal->c*(P->z - W->z)) / ( normal->a*normal->a + normal->b*normal->b + normal->c*normal->c );

	//(x, y, z) = (c1, c2, c3) + L (x1 - c1, y1 - c2, z1 - c3)
	iP->x = P->x + (lambda * normal->a);
	iP->y = P->y + (lambda * normal->b);
	iP->z = P->z + (lambda * normal->c);

	printf("Os valores de x, y e z da imagem sao: (%f, %f, %f)\n\n",iP->x,iP->y,iP->z);
}

int main(){
	Vetor normal;
	float lambda;
	Ponto W;
	Ponto P1, P2, P3, P4, P5, P6, P7, P8;
	Ponto iP1, iP2, iP3, iP4, iP5, iP6, iP7, iP8;
	P1.x = -10; P1.y =  20; P1.z =  30; P1.W = 1;
	P2.x =  10; P2.y =  20; P2.z =  30; P2.W = 1;
	P3.x =  10; P3.y = -20; P3.z =  30; P3.W = 1;
	P4.x = -10; P4.y = -20; P4.z =  30; P4.W = 1;
	P5.x = -10; P5.y =  20; P5.z = -30; P5.W = 1;
	P6.x =  10; P6.y =  20; P6.z = -30; P6.W = 1;
	P7.x =  10; P7.y = -20; P7.z = -30; P7.W = 1;
	P8.x = -10; P8.y = -20; P8.z = -30; P8.W = 1;

	printf("Digite os valores das coordenadas do centro do plano: ");
	scanf("%f %f %f", &W.x, &W.y, &W.z);
	W.W = 1;

	printf("Digite as coordenadas do vetor normal ao plano: ");
	scanf("%f %f %f", &normal.a, &normal.b, &normal.c);
	
	//a*x + b*y + c*z + d = 0 => achando o valor de d:
	normal.d = - (normal.a*W.x) - (normal.b*W.y) - (normal.c*W.z);

	//(x, y, z) = (c1, c2, c3) + L (x1 - c1, y1 - c2, z1 - c3)
	imagem(&iP1, &P1, &W, &normal );
	imagem(&iP2, &P2, &W, &normal );
	imagem(&iP3, &P3, &W, &normal );
	imagem(&iP4, &P4, &W, &normal );
	imagem(&iP5, &P5, &W, &normal );
	imagem(&iP6, &P6, &W, &normal );
	imagem(&iP7, &P7, &W, &normal );
	imagem(&iP8, &P8, &W, &normal );

	printf("Cheguei ao final!!\n");	
	getchar();
	getchar();
}
