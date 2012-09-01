//Utilizando X
// Para compilar!
// gcc -c cg2d.c
// gcc p1_2.c -o p1_2 cg2d.o -lm -lX11

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  object * poligono1, * poligono2, * poligono3;
  ColorValues * rgb, * hsv;
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  palheta = CreatePalette(8);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  rgb = (ColorValues *) malloc(sizeof(ColorValues));
  hsv = (ColorValues *) malloc(sizeof(ColorValues));
  
  hsv->red = 261;
  hsv->green = 0.87;
  hsv->blue = 0.50;
  rgb = HSV2RGB(hsv);  
  SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  hsv->red = 355;
  hsv->green = 0.89;
  hsv->blue = 0.43;
  rgb = HSV2RGB(hsv);  
  SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  hsv->red = 129;
  hsv->green = 0.70;
  hsv->blue = 0.46;
  rgb = HSV2RGB(hsv);  
  SetColor(rgb->red,rgb->green,rgb->blue,palheta);
  
  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);
  
  SetObject(SetPoint(-9.0,-8.0,5), poligono1);
  SetObject(SetPoint(-7.0,-3.0,5), poligono1);
  SetObject(SetPoint(-4.0,-4.0,5), poligono1);
  SetObject(SetPoint(-3.0,-6.0,5), poligono1);
  SetObject(SetPoint(-6.0,-9.0,5), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,6), poligono2);
  SetObject(SetPoint(-1.0,-2.0,6), poligono2);
  SetObject(SetPoint(-1.0,-6.0,6), poligono2);
  SetObject(SetPoint(-6.0,-6.0,6), poligono2);
  
  janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  //janela = CreateWindow(-20.0,10.0,-20.0,15.0);
  
  DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  
  poligono3 = Rotate(poligono1,45);
  poligono3 = ChangeColor(poligono3,7);
  DrawObject(poligono3,janela,dispositivo); // desenha o poligono 3 dentro da janela no buffer do dispositivo
  
  /*
   * Junto com a operação de rotação temos uma translação.
   * Para verificar se os limites do mundo estão adequados para as operações do exercício
   * basta considerar uma janela do tamanho do mundo e verificar se todos os objetos
   * são desenhados corretamente. No caso, a resposta é sim, pois todos os pontos estão dentro do mundo.
   */
  
  DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);
  
  return 0;
  }
