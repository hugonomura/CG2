//Primeira Prova - Computação Gráfica
//
//autor: Bruno Antunes da Silva		317292

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <math.h>
#define MAX 128
#define PI 3.1415926536


typedef struct ponto3D{
	float x, y, z, W;
}Ponto;

//Estrutura para representacao da matriz de transformacao linear sobre um struct ponto3D no espaço tridimensional homogêneo
struct matriz4x4{
	float a11, a12, a13, a14;
	float a21, a22, a23, a24;
	float a31, a32, a33, a34;
	float a41, a42, a43, a44;
};

typedef struct vetorEs {
	float a, b, c, d;
}Vetor;

//Funcao de rotacao de um struct ponto3D
Ponto* rotaciona(struct matriz4x4 * mRot, Ponto* p){
	Ponto* resultado;
	resultado = (Ponto*) malloc (sizeof(Ponto));

	//Multiplica a matriz pelo struct ponto3D recebidos como parametro colocando o resultado na estrutura 'resultado'
	resultado->x = p->x * mRot->a11 + p->y * mRot->a12 + p->z * mRot->a13 + p->W * mRot->a14;
	resultado->y = p->x * mRot->a21 + p->y * mRot->a22 + p->z * mRot->a23 + p->W * mRot->a24;
	resultado->z = p->x * mRot->a31 + p->y * mRot->a32 + p->z * mRot->a33 + p->W * mRot->a34;
	resultado->W = p->x * mRot->a41 + p->y * mRot->a42 + p->z * mRot->a43 + p->W * mRot->a44;

	return resultado;
}


//Metodo que implementa o calculo de cada ponto do objeto no plano
Ponto* Projeta(float tz, float cpz, Ponto* P){
	Ponto* iP;
	iP = (Ponto*) malloc (sizeof(Ponto));
	float lambda=0;
	Ponto C, W;	
	Vetor normal;

	C.x = 0;
	C.y = 0;
	C.z = cpz;
	C.W = 1;

	W.x = 0;
	W.y = 0;
	W.z = tz;
	W.y = 1;

	normal.a = 0;
	normal.b = 0;
	normal.c = 1;

	//Calculo do lambda
	lambda = ( -(normal.c*P->z - W.z)) / (normal.c*P->z - normal.c*C.z);

	//(x, y, z) = (c1, c2, c3) + L (x1 - c1, y1 - c2, z1 - c3)
	iP->x = C.x + (lambda * (P->x - C.x));
	iP->y = C.y + (lambda * (P->y - C.y));
	iP->z = C.z + (lambda * (P->z - C.z));
	
	return iP;
}

void reta(Window* win,GC* gc,Display* display, float x1, float x2, float y1, float y2) {
	float a,b,x,y, aux;
	int i, j,i2;
	if(x1 > x2){
		aux = x1;
		x1 = x2;
		x2 = aux;	
		aux = y1;
		y1 = y2;
		y2 = aux;
	}
	a = (y2-y1)/(x2-x1);
	b = y1 - a*x1;
	printf("\n\n");
	i=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
	j=MAX - y1;
	XDrawPoint(display, *win, *gc, i+128, j);
	i = x2;
	j = MAX - y2;
	XDrawPoint(display, *win, *gc, i+128, j); 
	if(y1!=y2){
		if(x1!=x2){
			x = x1++;
			y = a*x + b; 
			if (y<y2){
				while (y< y2 ){
					   i = x;
					   j = MAX - y;
					   XDrawPoint(display, *win, *gc, i+128, j); 
					   y = a*(++x) + b;
				}
			}
			else{
				while (y> y2 ){
					   i = x;
					   j = MAX - y;
					   XDrawPoint(display, *win, *gc, i+128, j); 
					   y = a*(++x) + b;
				}	
			}
		}


	//x igual (vertical)
		else{
			if(y1<y2){
				y = y1;	
				i = x1;
			}
			else{
				y = y2;
				i = x1;
			}
			while (y< y2){
				j = MAX - y;
		   		XDrawPoint(display, *win, *gc, i+128, j); 
				y++;		
			}
		}
	}
	else{ //y1=y2 (reta horizontal)
		if(x1<x2){
			y = y1;	
			i = x1;
		}
		else{
			y = y2;
			i = x2;
		}
		j= MAX -y;
		while(i<x2){
		    XDrawPoint(display, *win, *gc, i+128, j); 
			i++;
		}		
	}
}

int main(){
	//Pontos iniciais
	Ponto P1, P2, P3, P4, P5, P6, P7, P8;

	float se, co, tz, cpz;

	//Pontos rotacionados
	Ponto *rP1, *rP2, *rP3, *rP4, *rP5, *rP6, *rP7, *rP8;

	//Pontos Projetados perspectivamente
	Ponto *iP1, *iP2, *iP3, *iP4, *iP5, *iP6, *iP7, *iP8;

	//Declaração da matriz de rotação
	struct matriz4x4 mRotaciona;

	int RXmin,RXmax,RYmin,RYmax,a,b;

	Window win;
	Display *display;
	int width = 256, height = 256, x = 0, y = 0, i, tx, ty,ref,rot;
	GC gc;
	unsigned long valuemask = 0;
	XGCValues values;
	XColor cor;


	P1.x =  30; P1.y = -10; P1.z =  10; P1.W = 1;
	P2.x =  30; P2.y = -10; P2.z = -10; P2.W = 1;
	P3.x =  30; P3.y =  10; P3.z =  10; P3.W = 1;
	P4.x =  30; P4.y =  10; P4.z = -10; P4.W = 1;
	P5.x = -30; P5.y = -10; P5.z =  10; P5.W = 1;
	P6.x = -30; P6.y = -10; P6.z = -10; P6.W = 1;
	P7.x = -30; P7.y =  10; P7.z =  10; P7.W = 1;
	P8.x = -30; P8.y =  10; P8.z = -10; P8.W = 1;

	//Variaveis para calculo do seno e cosseno do angulo de rotacao
	se = sin(90*PI/180);
	co = cos(90*PI/180);

	//Inicializacao da matriz de Rotacao em relacao ao eixo z

	mRotaciona.a11 = co; mRotaciona.a12 = -se; mRotaciona.a13 = 0; mRotaciona.a14 = 0;
	mRotaciona.a21 = se; mRotaciona.a22 = co; mRotaciona.a23 = 0; mRotaciona.a24 = 0;
	mRotaciona.a31 = 0; mRotaciona.a32 = 0; mRotaciona.a33 = 1; mRotaciona.a34 = 0;
	mRotaciona.a41 = 0; mRotaciona.a42 = 0; mRotaciona.a43 = 0; mRotaciona.a44 = 1;



//**************************************  (a)  **********************************************

	//Estou utilizando a regra da mão direita
	//Chamada da funcao que rotaciona o ponto
	rP1 = rotaciona(&mRotaciona, &P1);
	rP2 = rotaciona(&mRotaciona, &P2);
	rP3 = rotaciona(&mRotaciona, &P3);
	rP4 = rotaciona(&mRotaciona, &P4);
	rP5 = rotaciona(&mRotaciona, &P5);
	rP6 = rotaciona(&mRotaciona, &P6);
	rP7 = rotaciona(&mRotaciona, &P7);
	rP8 = rotaciona(&mRotaciona, &P8);

	
//**************************************  (b)  **********************************************

	//Projeção Perspectiva

	printf("\n\nDigite o valor Tz: \n");
	scanf("%f",&tz);
	printf("\nDigite o valor Cpz: \n");
	scanf("%f",&cpz);

	iP1 = Projeta(tz, cpz, rP1);
	iP2 = Projeta(tz, cpz, rP2);
	iP3 = Projeta(tz, cpz, rP3);
	iP4 = Projeta(tz, cpz, rP4);
	iP5 = Projeta(tz, cpz, rP5);
	iP6 = Projeta(tz, cpz, rP6);
	iP7 = Projeta(tz, cpz, rP7);
	iP8 = Projeta(tz, cpz, rP8);

	
//**************************************  (c)  **********************************************


	//Entrada dos valores do retangulo de visualizacao
	printf("\n\nDigite o valor do RXmin: \n");
	scanf("%f",&RXmin);
	printf("\nDigite o valor RXmax: \n");
	scanf("%f",&RXmax);

	printf("\n\nDigite o valor do RYmin: \n");
	scanf("%f",&RYmin);
	printf("\nDigite o valor RYmax: \n");
	scanf("%f",&RYmax);

	//width = modulo(RXmin) + modulo(RXmax);
	//height = modulo(RYmin) + modulo(RYmax);
	
	win = XCreateSimpleWindow(display, RootWindow(display, DefaultScreen(display)), x, y, width, height, 4, 	BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen(display)));
	XMapWindow(display, win);
	gc = XCreateGC(display, win, valuemask, &values);
	XSync(display, False);

	XSetForeground(display, gc, WhitePixel(display, DefaultScreen(display)));
	XSetBackground(display, gc, BlackPixel(display, DefaultScreen(display)));

	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"black", &cor, &cor);

	XSetForeground(display, gc, cor.pixel);


	//Desenhando os pontos
	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP2->x;
	b = iP2->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	a = iP1->x;
	b = iP1->y;
	XDrawPoint(display, win, gc, a, b);

	//Desenhando as 12 retas
        reta(&win, &gc, display,iP1->x,iP2->x,iP1->y,iP2->y);

        reta(&win, &gc, display,iP2->x,iP4->x,iP2->y,iP4->y);

        reta(&win, &gc, display,iP4->x,iP3->x,iP4->y,iP3->y);

        reta(&win, &gc, display,iP3->x,iP1->x,iP3->y,iP1->y);

        reta(&win, &gc, display,iP1->x,iP5->x,iP1->y,iP5->y);

        reta(&win, &gc, display,iP2->x,iP6->x,iP2->y,iP6->y);

        reta(&win, &gc, display,iP3->x,iP7->x,iP3->y,iP7->y);

        reta(&win, &gc, display,iP4->x,iP8->x,iP4->y,iP8->y);

        reta(&win, &gc, display,iP5->x,iP6->x,iP5->y,iP6->y);

        reta(&win, &gc, display,iP6->x,iP8->x,iP6->y,iP8->y);

        reta(&win, &gc, display,iP8->x,iP7->x,iP8->y,iP7->y);

        reta(&win, &gc, display,iP7->x,iP5->x,iP7->y,iP5->y);


	XFlush(display);

	sleep(30);

	XFreeGC(display, gc);
	XCloseDisplay(display);

	return 0;
}
