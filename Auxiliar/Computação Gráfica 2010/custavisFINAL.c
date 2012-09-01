/*   Autor: Gustavo Henrique dos Santos Marcello RA: 317276
	 Programa: 	Geracao e manipulacao grafica de retas
*/

#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <math.h>
#define MAX 128
#define PI 3.1415926536

void reta(Window *win,GC *gc,Display *display, float x1,float x2, float y1, float y2){
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



int main(void){

	Window win;
	Display *display;
	int width = 256, height = 256, x = 0, y = 0, i, tx, ty,ref,rot;
	GC gc;
	unsigned long valuemask = 0;
	XGCValues values;
	XColor cor;
	float x1,x2,y1,y2,x1r,x2r,y1r,y2r, ang;
	printf("x1 = ");
	scanf("%f" , &x1);
	printf("x2 = ");
	scanf("%f", &x2);
	printf("y1 = ");
	scanf("%f", &y1);
	printf("y2 = ");
	scanf("%f", &y2);
	printf("Transladar eixo x = ");
	scanf("%d", &tx);
	printf("Transladar eixo y = ");
	scanf("%d", &ty);
	printf("Reflexao:\n1 - Eixo x\n2 - Eixo y\n3 - Eixo x e y: ");
	scanf("%d", &ref);
	printf("Angulo para rotacionar: ");
	scanf("%d", &rot);

//Calculando pontos para rotação
	x1r = x1*cos(rot*PI/180) - y1*sin(rot*PI/180);
	printf("cos: %f", cos(rot*PI/180));
	y1r = x1*sin(rot*PI/180) + y1*(rot*PI/180);

	x2r = x2*cos(rot*PI/180) - y2*sin(rot*PI/180);
	y2r = x2*sin(rot*PI/180) + y2*(rot*PI/180);	

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

        reta(&win, &gc, display,x1,x2,y1,y2);

//desenhando a reta translatada
	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"yellow", &cor, &cor);
	XSetForeground(display, gc, cor.pixel);
    reta(&win, &gc, display,x1+tx,x2+tx,y1+ty,y2+ty);

//desenhando a reta refletida
	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"green", &cor, &cor);
	XSetForeground(display, gc, cor.pixel);
	
	switch (ref){
		case 1: reta(&win, &gc, display,-x1,-x2,y1,y2); break;
		case 2: reta(&win, &gc, display,x1,x2,-y1,-y2); break;
		case 3:	reta(&win, &gc, display,-x1,-x2,-y1,-y2); break;
	}

//desenhando a reta rotacionada
	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"red", &cor, &cor);
	XSetForeground(display, gc, cor.pixel);	
    reta(&win, &gc, display,x1r,x2r,y1r,y2r);



	XFlush(display);

	sleep(30);

	XFreeGC(display, gc);
	XCloseDisplay(display);

	return 0;
}
