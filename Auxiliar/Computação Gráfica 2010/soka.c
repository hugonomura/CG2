#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <math.h>

#define PI 3.14159265

float * translada(float*, int, int);

float * refleteHorX(float*);

float * refleteVertY(float*);

float * refleteOrigem(float*);

float * translada(float *, int, int);

float * escalona(float*, float, float);

float * rotaciona(float*, double);

//reflete horizontalmente no eixo do X
float * refleteHorX(float* v){  
	v[0] = v[0]*-1;
	return v;
}

//reflete verticalmente no eixo do Y
float * refleteVertY(float* v){  
	v[1] = v[1]*-1;
	return v;
}

//reflete em relaçao a origem 
float * refleteOrigem(float* v){  
	v[0] = v[0]*-1;
	v[1] = v[1]*-1;
	return v;
}

//transladar a coordenada X em Tx unidades e a coordenada Y em Ty unidades
float * translada(float * v, int Tx, int Ty){
	v[0] = v[0] + Tx;
	v[1] = v[1] + Ty;
	return v;
}

//multiplica a coordenada X em Ex unidades e a coordenada Y em Ey unidades
float * escalona(float* v, float Ex, float Ey){
	v[0] = v[0] * Ex;
	v[1] = v[1] * Ey;
	return v;
}

// rotacionar o ponto com dado angulo 
float * rotaciona(float* v, double angulo){
	float *vane;
	vane = v;
	vane[0] = v[0] * ( cos (angulo*PI/180)) + v[1] * - ( sin (angulo*PI/180));
	vane[1] = v[0] * ( sin (angulo*PI/180)) + v[1] * ( cos (angulo*PI/180));
	return vane;
}

int main (){
	float coord[3];
	float * a;
	float * pCoord;
	int i;
		
   Window win;
   Display *display;
   int width = 256, height = 256, x =0, y=0;
   GC gc;
   unsigned long valuemask=0;
   XGCValues values;
   XColor cor;

	printf("Digite o ponto a: \n");
	scanf("%f %f",&coord[0], &coord[1]);
	coord[2] = 1;

//	printf("Digite o ponto b: \n");
//	scanf("%d %d",&b1, &b2);

   display = XOpenDisplay(NULL);

   win = XCreateSimpleWindow (display, RootWindow(display, DefaultScreen(display)), x,y, width, height, 4, BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen (display)));

   XMapWindow (display, win);

   gc = XCreateGC (display, win, valuemask, &values);
   XSync(display, False);

   XSetForeground(display, gc, WhitePixel (display, DefaultScreen(display)));

   XSetBackground(display, gc, BlackPixel (display, DefaultScreen(display)));

   XAllocNamedColor(display, XDefaultColormap (display, DefaultScreen(display)), "blue", &cor, &cor);

   XSetForeground(display, gc, cor.pixel);

	for (i=0;i<256;i++){
		XDrawPoint (display, win, gc, i, 128);
		XDrawPoint (display, win, gc, 128, i);	
	}

	a = translada(coord,128,128);
	XDrawPoint (display, win, gc, a[0], a[1]);

	pCoord = rotaciona(coord, 45);			// rotacionar em 45 graus

   XAllocNamedColor(display, XDefaultColormap (display, DefaultScreen(display)), "red", &cor, &cor);
   XSetForeground(display, gc, cor.pixel);

	a = translada(pCoord,128,128);
	XDrawPoint (display, win, gc, a[0], a[1]);

	pCoord = refleteHorX(pCoord);   			//reflete horizontalmente no eixo do X

   XAllocNamedColor(display, XDefaultColormap (display, DefaultScreen(display)), "green", &cor, &cor);
   XSetForeground(display, gc, cor.pixel);

	a = translada(pCoord,128,128); 
	XDrawPoint (display, win, gc, a[0], a[1]);
	
	XFlush(display);

   sleep(30);

   XFreeGC(display, gc);
   XCloseDisplay(display);

   return 0;
}
