
   .........
#include <X11/keysym.h>

   ......... 

#define EventMask (KeyPressMask | ExposureMask)

   ........



int main(int argc, char ** argv) {

    ......



Janela = OpenX(largura,altura); 
XSelectInput(Janela->display, Janela->win, EventMask);  /* eventos do X */


    ......

 sair = 0;
 while (!sair) {
   XNextEvent(Janela->display, &an_event);
   switch (an_event.type) {
     case Expose:
          Handle_exposure(Objeto, Janela, centro_projecao, plano_projecao, normal);
          break;
     case KeyPress:
          if (XLookupKeysym(&an_event.xkey, 0) == XK_z) {
	       theta_z+=35.0;
               Handle_rotation(Objeto, Janela, centro_projecao, plano_projecao, normal, theta_z, 3);
               }
          if (XLookupKeysym(&an_event.xkey, 0) == XK_y) {
	       theta_y+=35.0;
               Handle_rotation(Objeto, Janela, centro_projecao, plano_projecao, normal, theta_y, 2);
               }
          if (XLookupKeysym(&an_event.xkey, 0) == XK_x) {
	       theta_x+=35.0;
               Handle_rotation(Objeto, Janela, centro_projecao, plano_projecao, normal, theta_x, 1);
               }
          if (XLookupKeysym(&an_event.xkey, 0) == XK_q) {
               sair = 1;
               }
          break;
     default:
          break;
     }
   }

 CloseX(Janela);
 
 return 0;
 }


struct X * OpenX(int largura, int altura) {
  
 struct X * Janela;
 Window root_window;
 XGCValues values;
 unsigned long white_pixel, black_pixel;

 Janela = (struct X *) malloc(sizeof(struct X));

 Janela->display = XOpenDisplay(NULL);
 Janela->largura = largura;
 Janela->altura = altura;
 root_window = RootWindow(Janela->display, DefaultScreen(Janela->display)); 
 black_pixel = BlackPixel(Janela->display, DefaultScreen(Janela->display));  
 white_pixel = WhitePixel(Janela->display, DefaultScreen(Janela->display)); 
 Janela->win = XCreateSimpleWindow(Janela->display,root_window,0,0,Janela->largura,Janela->altura,4,black_pixel,white_pixel);
 Janela->gc = XCreateGC(Janela->display, Janela->win, 0, &values);
 XMapWindow(Janela->display, Janela->win); 
 XSync(Janela->display, False);

 return Janela;
 }

int CloseX(struct X * Janela) {
  
 XFreeGC(Janela->display,Janela->gc); 
 XCloseDisplay(Janela->display);

 return 0;
 }


