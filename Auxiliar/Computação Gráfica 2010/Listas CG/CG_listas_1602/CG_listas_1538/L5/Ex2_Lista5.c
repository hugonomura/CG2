// LISTA 05 // EXERCICIO 01

#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <math.h>


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
	int a[2],i, opc;
	Window win;
  	Display *display;
  	int width = 256, height = 256, x =0, y=0;
  	GC gc;

	printf("\n\nImprimir ogue?\n\n1 - Planta\n2 - Lateral\n3 - Frontal\n");
	scanf("%d", &opc);

  	unsigned long valuemask=0;
  	XGCValues values;
  	XColor cor;
	Ponto P1, P2, P3, P4;
	Ponto2D iP1, iP2, iP3, iP4;	
	P1.x = 10; P1.y = 10; P1.z = 10; P1.W = 1;
	P2.x = 10; P2.y = 10; P2.z = -10; P2.W = 1;
	P3.x = -10; P3.y = -10; P3.z = -10; P3.W = 1;
	P4.x = -10; P4.y = -10; P4.z = 10; P4.W = 1;

	display = XOpenDisplay(NULL);

   win = XCreateSimpleWindow (display, RootWindow(display, DefaultScreen(display)), x,y, width, height, 4, BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen (display)));

   XMapWindow (display, win);

   gc = XCreateGC (display, win, valuemask, &values);
   XSync(display, False);

   XSetForeground(display, gc, WhitePixel (display, DefaultScreen(display)));

   XSetBackground(display, gc, BlackPixel (display, DefaultScreen(display)));

   XAllocNamedColor(display, XDefaultColormap (display, DefaultScreen(display)), "blue", &cor, &cor);

   XSetForeground(display, gc, cor.pixel);


	//Desenha os eixos x e y
	for (i=0;i<256;i++){
		XDrawPoint (display, win, gc, i, 128);
		XDrawPoint (display, win, gc, 128, i);	
	}

	//Desenha Planta 
	if (opc == 1){
		planta(&iP1, &P1);
		printf("P1 depois da funcao planta eh: (%f, %f)\n",iP1.x,iP1.y);
		planta(&iP2, &P2);
		printf("P2 depois da funcao planta eh: (%f, %f)\n",iP2.x,iP2.y);
		planta(&iP3, &P3);
		printf("P3 depois da funcao planta eh: (%f, %f)\n",iP3.x,iP3.y);
		planta(&iP4, &P4);
		printf("P4 depois da funcao planta eh: (%f, %f)\n",iP4.x,iP4.y);
	}
	else{
		if (opc == 2){
			lateral(&iP1, &P1);
			printf("P1 depois da funcao lateral eh: (%f, %f)\n",iP1.x,iP1.y);
			lateral(&iP2, &P2);
			printf("P2 depois da funcao lateral eh: (%f, %f)\n",iP2.x,iP2.y);
			lateral(&iP3, &P3);
			printf("P3 depois da funcao lateral eh: (%f, %f)\n",iP3.x,iP3.y);
			lateral(&iP4, &P4);
			printf("P4 depois da funcao lateral eh: (%f, %f)\n",iP4.x,iP4.y);
		}else{
			frontal(&iP1, &P1);
			printf("P1 depois da funcao frontal eh: (%f, %f)\n\n",iP1.x,iP1.y);
			frontal(&iP2, &P2);
			printf("P2 depois da funcao frontal eh: (%f, %f)\n\n",iP2.x,iP2.y);
			frontal(&iP3, &P3);
			printf("P3 depois da funcao frontal eh: (%f, %f)\n\n",iP3.x,iP3.y);
			frontal(&iP4, &P4);
			printf("P4 depois da funcao frontal eh: (%f, %f)\n\n",iP4.x,iP4.y);


		}
	}
	a[0] = iP1.x;
	a[0] = a[0] + 128; //translação 
	a[1] = iP1.y;
	a[1] = a[1] + 128; //translação
	XDrawPoint (display, win, gc, a[0], a[1]);

	a[0] = iP2.x;
	a[0] = a[0] + 128; //translação 
	a[1] = iP2.y;
	a[1] = a[1] + 128; //translação
	XDrawPoint (display, win, gc, a[0], a[1]);

	a[0] = iP3.x;
	a[0] = a[0] + 128; //translação 
	a[1] = iP3.y;
	a[1] = a[1] + 128; //translação
	XDrawPoint (display, win, gc, a[0], a[1]);

	a[0] = iP4.x;
	a[0] = a[0] + 128; //translação 
	a[1] = iP4.y;
	a[1] = a[1] + 128; //translação
	XDrawPoint (display, win, gc, a[0], a[1]);

	XFlush(display);

   sleep(30);

   XFreeGC(display, gc);
   XCloseDisplay(display);
}


