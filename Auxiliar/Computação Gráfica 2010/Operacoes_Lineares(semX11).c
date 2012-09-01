#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1415

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
struct ponto3D * translada(struct matriz4x4 * mTrans, struct ponto3D * p){
	struct ponto3D * resultado;
	resultado = (struct ponto3D*) malloc (sizeof(struct ponto3D));

	//Multiplica a matriz pelo ponto recebidos como parametro colocando o resultado na estrutura 'resultado'
	resultado->x = p->x * mTrans->a11 + p->y * mTrans->a12 + p->z * mTrans->a13 + p->W * mTrans->a14;
	resultado->y = p->x * mTrans->a21 + p->y * mTrans->a22 + p->z * mTrans->a23 + p->W * mTrans->a24;
	resultado->z = p->x * mTrans->a31 + p->y * mTrans->a32 + p->z * mTrans->a33 + p->W * mTrans->a34;
	resultado->W = p->x * mTrans->a41 + p->y * mTrans->a42 + p->z * mTrans->a43 + p->W * mTrans->a44;

	return resultado;
}

//Funcao de escalonamento de um ponto
struct ponto3D * escalona(struct matriz4x4 * mEsc, struct ponto3D * p){
	struct ponto3D * resultado;
	resultado = (struct ponto3D*) malloc (sizeof(struct ponto3D));

	//Multiplica a matriz pelo ponto recebidos como parametro colocando o resultado na estrutura 'resultado'
	resultado->x = p->x * mEsc->a11 + p->y * mEsc->a12 + p->z * mEsc->a13 + p->W * mEsc->a14;
	resultado->y = p->x * mEsc->a21 + p->y * mEsc->a22 + p->z * mEsc->a23 + p->W * mEsc->a24;
	resultado->z = p->x * mEsc->a31 + p->y * mEsc->a32 + p->z * mEsc->a33 + p->W * mEsc->a34;
	resultado->W = p->x * mEsc->a41 + p->y * mEsc->a42 + p->z * mEsc->a43 + p->W * mEsc->a44;

	return resultado;
}

//Funcao de rotacao de um ponto
struct ponto3D * rotaciona(struct matriz4x4 * mRot, struct ponto3D * p){
	struct ponto3D * resultado;
	resultado = (struct ponto3D*) malloc (sizeof(struct ponto3D));

	//Multiplica a matriz pelo ponto recebidos como parametro colocando o resultado na estrutura 'resultado'
	resultado->x = p->x * mRot->a11 + p->y * mRot->a12 + p->z * mRot->a13 + p->W * mRot->a14;
	resultado->y = p->x * mRot->a21 + p->y * mRot->a22 + p->z * mRot->a23 + p->W * mRot->a24;
	resultado->z = p->x * mRot->a31 + p->y * mRot->a32 + p->z * mRot->a33 + p->W * mRot->a34;
	resultado->W = p->x * mRot->a41 + p->y * mRot->a42 + p->z * mRot->a43 + p->W * mRot->a44;

	return resultado;
}

int main(){
		//Declaracao do ponto a ser recebido como entrada e do ponto que recebera o resultado
		struct ponto3D pontoInicial;
		struct ponto3D * resultado;

		//Declaracao das matrizes que farao as operacoes
		struct matriz4x4 mTranslada;
		struct matriz4x4 mEscalona;
		struct matriz4x4 mRotaciona;

		//Valores a serem somados ao ponto na translacao
		float dx, dy, dz;

		//Valores a serem multiplicados ao ponto no escalonamento
		float sx = 6, sy = 4, sz = 2;
		
		printf("Digite as coordenadas x, y e z do ponto tridimensional que deseja manipular:\n");
		scanf("%f",&pontoInicial.x);
		scanf("%f",&pontoInicial.y);
		scanf("%f",&pontoInicial.z);

		pontoInicial.W = 1;

		//Inicializa os valores que serao aplicados na translacao
		dx = 2*pontoInicial.x;
		dy = 4*pontoInicial.y;
		dz = 6*pontoInicial.z;

		//Inicializacao da matriz de translacao
		mTranslada.a11 = 1; mTranslada.a12 = 0; mTranslada.a13 = 0; mTranslada.a14 = dx;
		mTranslada.a21 = 0; mTranslada.a22 = 1; mTranslada.a23 = 0; mTranslada.a24 = dy;
		mTranslada.a31 = 0; mTranslada.a32 = 0; mTranslada.a33 = 1; mTranslada.a34 = dz;
		mTranslada.a41 = 0; mTranslada.a42 = 0; mTranslada.a43 = 0; mTranslada.a44 = 1;

		//Chamada da funcao que translada o ponto
		resultado = translada(&mTranslada, &pontoInicial);

		printf("Ponto transladado:\t(%f, %f, %f)\n",resultado->x, resultado->y, resultado->z);

		//Inicializacao da matriz de Escalonamento
		mEscalona.a11 = sx; mEscalona.a12 = 0; mEscalona.a13 = 0; mEscalona.a14 = 0;
		mEscalona.a21 = 0; mEscalona.a22 = sy; mEscalona.a23 = 0; mEscalona.a24 = 0;
		mEscalona.a31 = 0; mEscalona.a32 = 0; mEscalona.a33 = sz; mEscalona.a34 = 0;
		mEscalona.a41 = 0; mEscalona.a42 = 0; mEscalona.a43 = 0; mEscalona.a44 = 1;

		//Chamada da funcao que escalona o ponto
		resultado = escalona(&mEscalona, &pontoInicial);

		printf("Ponto escalonado:\t(%f, %f, %f)\n",resultado->x, resultado->y, resultado->z);

		//Variaveis para calculo do seno e cosseno do angulo de rotacao
		float se, co;
		se = sin(35.5*PI/180);
		co = cos(35.5*PI/180);

		//Inicializacao da matriz de Rotacao em relacao ao eixo z
		mRotaciona.a11 = co; mRotaciona.a12 = -se; mRotaciona.a13 = 0; mRotaciona.a14 = 0;
		mRotaciona.a21 = se; mRotaciona.a22 = co; mRotaciona.a23 = 0; mRotaciona.a24 = 0;
		mRotaciona.a31 = 0; mRotaciona.a32 = 0; mRotaciona.a33 = 1; mRotaciona.a34 = 0;
		mRotaciona.a41 = 0; mRotaciona.a42 = 0; mRotaciona.a43 = 0; mRotaciona.a44 = 1;

		//Chamada da funcao que rotaciona o ponto
		resultado = rotaciona(&mRotaciona, &pontoInicial);

		printf("Ponto rotacionado:\t(%f, %f, %f)\n",resultado->x, resultado->y, resultado->z);
}
