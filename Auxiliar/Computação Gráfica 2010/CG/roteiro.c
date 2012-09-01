#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>

int main (void){

	int i,j,a1,a2,b1,b2, aux, aux2;
	int a,b;
   Window win;
   Display *display;
   int width = 256, height = 256, x =0, y=0;
   GC gc;
   unsigned long valuemask=0;
   XGCValues values;
   XColor cor;

	printf("Digite o ponto a: \n");
	scanf("%d %d",&a1, &a2);

	printf("Digite o ponto b: \n");
	scanf("%d %d",&b1, &b2);

/*	if (a1>b1){
		aux = a1;
		a1 = b1;
		b1 = aux;
	}

	if (a2>b2){
		aux = a2;
		a2 = b2;
		b2 = aux;
	}

	if (a1>b1 && a2>b2){
		aux = a1;
		aux2 = a2;
		a1 = b1;
		a2 = b2;
		b1 = aux;
		b2 = aux2;
	}*/

   display = XOpenDisplay(NULL);

   win = XCreateSimpleWindow (display, RootWindow(display, DefaultScreen(display)), x,y, width, height, 4, BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen (display)));

   XMapWindow (display, win);

   gc = XCreateGC (display, win, valuemask, &values);
   XSync(display, False);

   XSetForeground(display, gc, WhitePixel (display, DefaultScreen(display)));

   XSetBackground(display, gc, BlackPixel (display, DefaultScreen(display)));

   XAllocNamedColor(display, XDefaultColormap (display, DefaultScreen(display)), "red", &cor, &cor);

   XSetForeground(display, gc, cor.pixel);
   XDrawPoint (display, win, gc, 15, 15);

	/*for(i=a2;i<b2;i++){
		for(j=a1;j<b1;j++){
			XDrawPoint (display, win, gc, i, j);
		}
	}*/

	if(a1==a2)
		error();

	a = (b2-b1)/(a2-a1);
	b = b1-a*a1;

	XDrawPoint (display, win, gc, a1, a2);
	XDrawPoint (display, win, gc, b1, b2);

/*	for(j=0;j<256;j++){
		for(i=0;i<256;i++){
			if(j==(a*i+b))
				XDrawPoint (display, win, gc, i, j);
		}
	}*/

   XFlush(display);

   sleep(30);

   XFreeGC(display, gc);
   XCloseDisplay(display);

   return 0;
}
