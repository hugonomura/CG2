//Utilizando X
// Para compilar!
// gcc -c cg2d.c
// gcc p1_1.c -o p1_1 cg2d.o -lm -lX11

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  object * poligono1, * poligono2, * poligono3;
  ColorValues * rgb, * hsv;  
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  palheta = CreatePalette(4);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,0,1,palheta);
  
  rgb = (ColorValues *) malloc(sizeof(ColorValues));
  hsv = (ColorValues *) malloc(sizeof(ColorValues));
  
  hsv->red = 129;
  hsv->green = 0.70;
  hsv->blue = 0.46;
  rgb = HSV2RGB(hsv);  
  SetColor(rgb->red,rgb->green,rgb->blue,palheta);  
  
  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);
  poligono3 = CreateObject(4);
  
  SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,2), poligono2);
  SetObject(SetPoint(-1.0,-2.0,2), poligono2);
  SetObject(SetPoint(-1.0,-6.0,2), poligono2);
  SetObject(SetPoint(-6.0,-6.0,2), poligono2);
  
  SetObject(SetPoint(-6.0,-3.3,3), poligono3);
  SetObject(SetPoint(-4.0,-4.0,3), poligono3);
  SetObject(SetPoint(-3.0,-6.0,3), poligono3);
  SetObject(SetPoint(-6.0,-6.0,3), poligono3);  

  janela = CreateWindow(-10.0,0.0,-10.0,0.0); // define uma janela de visualização 
  
  DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  
  Fill(poligono3,janela,dispositivo,3); // preenche o poligono 3 

  DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);  
  
  return 0;
  
  }
