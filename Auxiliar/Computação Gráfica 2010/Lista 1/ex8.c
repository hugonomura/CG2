#include<stdio.h>
#include<math.h> 
#include<X11/Xlib.h>

#define wTela 500
#define hTela 500


/*algoritmo de desenho de reta*/
void DesenhaReta(int x0, int y0, int x1, int y1, Display *display, Window win, GC gc)
{
  int dy = y1 - y0;
  int dx = x1 - x0;
  int stepx, stepy;
  int fracao;

  if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
  if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }

  dy *= 2;
  dx *= 2;

  XDrawPoint(display, win, gc, x0, y0);
  if (dx > dy) {
    fracao = dy - dx/2;
    while (x0 != x1) {
      if (fracao >= 0) {
        y0 += stepy;
        fracao -= dx;
      }
      x0 += stepx;
      fracao += dy;
      XDrawPoint(display, win, gc, x0, y0);
    }
  } else {
    fracao = dx - dy/2;
    while (y0 != y1) {
      if (fracao >= 0) {
        x0 += stepx;
        fracao -= dy;
      }
      y0 += stepy;
      fracao += dx;
      XDrawPoint(display, win, gc, x0, y0);
    }
  }
}




int main()
{
/* variáveis do X*/
Window win;
Display *display;
int width=wTela, height=hTela, i,j, vet=0;
GC gc;
unsigned long valuemask = 0;
XGCValues value;
XColor cor;     


/*variaveis do programa*/
int xcentro,ycentro,a,b;
float y, x;
float xaux, yaux;


/* Rotina Principal */
xcentro=0;
ycentro=0;
printf("Digite os valores de a e b (positivos e menores que 500):\n");
scanf("%d%d",&a,&b);
while(a>wTela || b>wTela || a<0 || b<0){
      printf("Insira valores válidos para a e b:\n");
scanf("%d%d",&a,&b);        
              }

/*inicializa funções para desenhar*/

display = XOpenDisplay(NULL);
    
    win = XCreateSimpleWindow(display, RootWindow(display, DefaultScreen (display)),x,y,width, height, 4, BlackPixel(display,DefaultScreen(display)),WhitePixel(display,DefaultScreen(display)));
    
    XMapWindow(display,win);
    
    gc = XCreateGC(display,win, valuemask, &value);
    XSync(display,False);
    
    XSetForeground(display,gc, WhitePixel(display,DefaultScreen(display)));
    XSetBackground(display,gc,BlackPixel(display,DefaultScreen(display)));
    
    XAllocNamedColor(display, XDefaultColormap(display,DefaultScreen(display)), "#FF09AB", &cor, &cor);
    
    XSetForeground(display,gc,cor.pixel);
/*fim das atribuições das funções de desenho*/

/* para cada x, atribui um y referente aos valores de A e B */
for (x=0; x<=a; x++)
{
y=(b-b*pow(x,2)/a);
if (y<0) y=-y;
y=sqrt(y);
printf("Y = %f \n", y);

/*desenha uma reta referente ao novo ponto com o ponto anterior*/
if (x!=0){
  DesenhaReta(xaux, yaux, x, y, display, win, gc);        
          }
/* Define que o ponto atual será o ponto origem da reta na próxima execução da função*/
xaux=x;
yaux=y;
}
}

