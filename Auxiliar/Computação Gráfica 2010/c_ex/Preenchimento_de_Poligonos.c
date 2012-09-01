/*   Autor: Gustavo Henrique dos Santos Marcello RA: 317276
	 Programa: 	Geracao e manipulacao grafica de retas
*/

#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <math.h>
#define MAX 128
#define PI 3.1415926536

typedef struct ponto2D {
	float x, y, W;
}Ponto;

typedef struct maAtriz {
	int mat[2*MAX][2*MAX];
}Matriz;

Matriz* reta(Window *win,GC *gc,Display *display, float x1,float x2, float y1, float y2,Matriz* m){
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
m->mat[i+128][j] = 1;
i = x2;
j = MAX - y2;
XDrawPoint(display, *win, *gc, i+128, j); 
m->mat[i+128][j] = 1;
if(y1!=y2){
	if(x1!=x2){
		x = x1++;
		y = a*x + b; 
		if (y<y2){
			while (y< y2 ){
				   i = x;
				   j = MAX - y;
				   XDrawPoint(display, *win, *gc, i+128, j); 
		    			m->mat[i+128][j] = 1;
				   y = a*(++x) + b;
			}
		}
		else{
			while (y> y2 ){
				   i = x;
				   j = MAX - y;
				   XDrawPoint(display, *win, *gc, i+128, j); 
					m->mat[i+128][j] = 1;
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
			m->mat[i+128][j] = 1;
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
		m->mat[i+128][j] = 1;
		i++;
	}		
}
return m;
}


void pintaMais(Window *win,GC *gc,Display *display, Matriz* m){
	int dentro = 0;
	int i,j,cont=0,k,pr=0,ul=0;
	
	for(i=0;i< 2*MAX; i++){
		for(j=0;j<2*MAX;j++){
			if(m->mat[i][j]==1){
				cont++;
				if(cont == 1)
					pr = j;
				ul = j;
			}

/*			if(cont%2 == 0)
				dentro = 0;
			else
				dentro = 1;
			if(cont>3) dentro = 0;			
			if(dentro)
				XDrawPoint(display, *win, *gc, i, j); */
		}
if(cont>0){
			for(k=pr;k<=ul;k++)
				XDrawPoint(display, *win, *gc, i, k);}
		dentro = 0;
		cont = 0;
	}
}


int main(void){

	Window win;
	Display *display;
	int width = 256, height = 256, x = 0, y = 0, i,j;
	GC gc;
	unsigned long valuemask = 0;
	XGCValues values;
	XColor cor;

	Matriz m;
	Matriz* mR;
	Ponto p1,p2,p3,p4;

	//Inicializa a matriz
	for(i=0;i<2*MAX;i++){
		for(j=0;j<2*MAX;j++){
			m.mat[i][j] = 0;
		}
	}


	printf("x1 = ");
	scanf("%f" , &p1.x);
	printf("y1 = ");
	scanf("%f" , &p1.y);
	i=p1.x; j=p1.y;	
	m.mat[i+128][j+128] = 1;

	printf("x2 = ");
	scanf("%f" , &p2.x);
	printf("y2 = ");
	scanf("%f" , &p2.y);
	i=p2.x; j=p2.y;	
	m.mat[i+128][j+128] = 1;

	printf("x3 = ");
	scanf("%f" , &p3.x);
	printf("y3 = ");
	scanf("%f" , &p3.y);
	i=p3.x; j=p3.y;	
	m.mat[i+128][j+128] = 1;

	printf("x4 = ");
	scanf("%f" , &p4.x);
	printf("y4 = ");
	scanf("%f" , &p4.y);
	i=p4.x; j=p4.y;	
	m.mat[i+128][j+128] = 1;

	display = XOpenDisplay(NULL);

	win = XCreateSimpleWindow(display, RootWindow(display, DefaultScreen(display)), x, y, width, height, 4, 	BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen(display)));
	XMapWindow(display, win);
	gc = XCreateGC(display, win, valuemask, &values);
	XSync(display, False);

	XSetForeground(display, gc, WhitePixel(display, DefaultScreen(display)));
	XSetBackground(display, gc, BlackPixel(display, DefaultScreen(display)));

	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"black", &cor, &cor);

	XSetForeground(display, gc, cor.pixel);

//desenhando os eixos
       for(i = 0; i < 256;i++){
		XDrawPoint(display, win, gc, i, 128); 
	}  
 	for(i = 0; i < 256;i++){
		XDrawPoint(display, win, gc, 128, i); 
	}  	

//desenhando a reta	
	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"blue", &cor, &cor);

	XSetForeground(display, gc, cor.pixel);

        mR = reta(&win, &gc, display,p1.x, p2.x, p1.y, p2.y,&m);
        mR = reta(&win, &gc, display,p3.x, p2.x, p3.y, p2.y,mR);
        mR = reta(&win, &gc, display,p3.x, p4.x, p3.y, p4.y,mR);
        mR = reta(&win, &gc, display,p4.x, p1.x, p4.y, p1.y,mR);

	pintaMais(&win, &gc, display, mR);

	XFlush(display);

	sleep(30);

	XFreeGC(display, gc);
	XCloseDisplay(display);

	return 0;
}
