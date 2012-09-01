#include <stdio.h>
#include <unistd.h>
#include <X11/Xlib.h>

int main(void){

Display * display;
GC gc;
Window win, root_window;
unsigned long valuemask = 0;
XGCValues values;
XColor cor;
int width = 256, height = 256, x = 0. y = 0, screennumber, espessura = 4;
unsigned long white_pixel, black_pixel;
display = XOpenDisplay(NULL);
screennumber = DefaultScreen(display);
root_window = RootWindow(display, screennumber);
black_pixel = BlackPixel(display, screennumber);
white_pixel = WhitePixel(display, screennumber);
win = XCreateSimpleWindow(display, root_window, x, y, width, height, espessura, black_pixel, white_pixel);
XMapWindow(display, win);
gc = XCreateGC(display, win, valuemask, &values);
XSync(display, False);
XSetForeground(display, gc, white_pixel);
XSetBackground(display, gc, black_pixel);

XAllocNamedColor(display, XDefaultColormap(display, screennumber), "red", &cor, &cor);
XSetForeground(display, gc, cor.pixel);
XDrawPoint(display, win, gc, 15, 15);

Xflush(display);
sleep(30);
XFreeGC(display, gc);
XCloseDisplay(display);
return 0;
}
