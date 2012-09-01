#include<stdio.h>

//Estrutura para representacao da matriz de transformacao linear sobre um ponto no espaço tridimensional homogêneo
struct matriz4x4 {
	float a11, a12, a13, a14;
	float a21, a22, a23, a24;
	float a31, a32, a33, a34;
	float a41, a42, a43, a44;
};

//Estrutura para representacao de um ponto no espaço tridimensional homogêneo
struct ponto3D {
	float x, y, z, W;
};

//Prototipo da funcao de translacao de um ponto
struct ponto3D * translada(struct matriz4x4 *, struct ponto3D *);

//Prototipo da funcao de escalonamento de um ponto
struct ponto3D * escalona(struct matriz4x4 *, struct ponto3D *);

//Prototipo da funcao de rotacao de um ponto
struct ponto3D * rotaciona(struct matriz4x4 *, struct ponto3D *);

//Funcao de translacao de um ponto
struct ponto3D * translada(struct matriz4x4 *, struct ponto3D *){
}

//Funcao de escalonamento de um ponto
struct ponto3D * escalona(struct matriz4x4 *, struct ponto3D *){
}

//Funcao de rotacao de um ponto
struct ponto3D * rotaciona(struct matriz4x4 *, struct ponto3D *){
}

int main(){
	fe






}
