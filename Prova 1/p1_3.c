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
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo
  
  palheta = CreatePalette(4);
  SetColor(0,0,0,palheta);  
  SetColor(1,0,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,0,palheta);
  
  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);
  
  SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,2), poligono2);
  SetObject(SetPoint(-1.0,-2.0,2), poligono2);
  SetObject(SetPoint(-1.0,-6.0,2), poligono2);
  SetObject(SetPoint(-6.0,-6.0,2), poligono2);
  
  poligono1 = Translate(poligono1,5,5);        // centraliza em relação a origem do sistema
  poligono2 = Translate(poligono2,5,5); 

  poligono3 = Translate(poligono2,-1.5,-1.0);   
  poligono3 = Rotate(poligono3,45);
  poligono3 = Translate(poligono3,1.5,1.0);
  poligono3 = ChangeColor(poligono3,3);
  
  poligono1 = Scale(poligono1,0.4,0.4);
  poligono2 = Scale(poligono2,0.4,0.4);
  poligono3 = Scale(poligono3,0.4,0.4);
  
  janela = CreateWindow(-2.0,2.0,-2.0,2.0); // define uma janela de visualização
  
  DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo
  DrawObject(poligono3,janela,dispositivo); // desenha o poligono 3 dentro da janela no buffer do dispositivo  
  
  /*
   * O sistema RGB é aditivo pois cada cor nesse modelo é representada por uma soma ponderada de três componentes
   * primárias (o vermelho, o verde e o azul).
   */
  
  DumpX(dispositivo,palheta); // desenha o buffer na tela
  //DumpOpenGL(argc,argv,dispositivo,palheta);
  
  return 0;
  }

