#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>
#define MAX 256



int main(void){

	float y1,x1,x2,y2,a,b,xx,yy;
	int i, j,i2,aux;
	printf("x1 = ");
	scanf("%f" , &x1);
	printf("x2 = ");
	scanf("%f", &x2);
	printf("y1 = ");
	scanf("%f", &y1);
	printf("y2 = ");
	scanf("%f", &y2);
	a = (y2-y1)/(x2-x1);
	b = y1 - a*x1;
	printf("a : %f",a);
	printf("\nb: %f", b);




	Window win;
	Display *display;
	int width = 256, height = 256, x = 0, y = 0;
	GC gc;
	unsigned long valuemask = 0;
	XGCValues values;
	XColor cor;
	
	display = XOpenDisplay(NULL);

	win = XCreateSimpleWindow(display, RootWindow(display, DefaultScreen(display)), x, y, width, height, 4, BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen(display)));
	XMapWindow(display, win);
	gc = XCreateGC(display, win, valuemask, &values);
	XSync(display, False);

	XSetForeground(display, gc, WhitePixel(display, DefaultScreen(display)));
	XSetBackground(display, gc, BlackPixel(display, DefaultScreen(display)));

	XAllocNamedColor(display, XDefaultColormap(display, DefaultScreen(display)),"red", &cor, &cor);

	XSetForeground(display, gc, cor.pixel);



	i=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
//	j=MAX;
//	XDrawPoint(display, win, gc, j, i);
	i = x2;
	j = y2;
	XDrawPoint(display, win, gc, j, i); 
	xx = x1++;
	yy = a*xx + b;

if(y1!=y2){
if(x1!=x2){
xx = x1++;
yy = a*xx + b; 
if (yy<y2){
while (yy< y2 ){
   i = xx;
   j = MAX - yy;
//   j = yy;
   XDrawPoint(display, win, gc, i, j);   
   yy = a*(++xx) + b;
}
}
else{
while (yy> y2 ){
   i = xx;
   //j = MAX - yy;
j = yy;
   XDrawPoint(display, win, gc, j, i);
   yy = a*(++xx) + b;
}
}

}


//x igual (vertical)
else{
if(y1<y2){
yy = y1;	
i = x1;
}
else{
yy = y2;
i = x1;
}
while (yy< y2){
	//j = MAX - yy;
j = yy;
	XDrawPoint(display, win, gc, j, i);
	yy++;		
}
}
}
else{ //y1=y2 (reta horizontal)
if(x1<x2){
yy = y1;	
i = x1;
}
else{
yy = y2;
i = x2;
}//j= MAX -yy;
j = yy;
while(i<x2){
	XDrawPoint(display, win, gc, j, i);
	i++;
}		
}

	XFlush(display);

	sleep(30);

	XFreeGC(display, gc);
	XCloseDisplay(display);

	return 0;

}
