#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void Desenha(void) /* Função callback chamada para fazer o desenho. */
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT); /* Limpa a janela de visualização com a cor de fundo especificada */

     /* Especifica que a cor corrente é vermelha */
     /*         R     G     B                    */
     glColor3f(1.0f, 0.0f, 0.0f);

     glBegin(GL_QUADS); /* Desenha um quadrado preenchido com a cor corrente */
               glVertex2i(100,150);
               glVertex2i(100,100);
               glColor3f(0.0f, 0.0f, 1.0f); /* Especifica que a cor corrente é azul */
               glVertex2i(150,100);
               glVertex2i(150,150);               
     glEnd();
     
    /* Outro exemplo */
    //glBegin(GL_POINTS);
    //           glColor3f(0.0f, 0.0f, 0.0f);
    //           glVertex2i(100, 50);
    //            glVertex2i(100, 130);
    //            glVertex2i(150, 130);
    //glEnd(); 
 

     glutSwapBuffers(); /* Executa os comandos OpenGL - garante que o desenho é realizado. */
} /* fim da função Desenha() */

void Inicializa (void) {  /* Inicializa parâmetros de rendering. */
  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* É a função que determina a cor utilizada para limpar a janela. */
  
  glViewport(0, 0, 500, 500); /* Especifica o tamanho da viewport. */

  glMatrixMode(GL_PROJECTION); /* Inicializa o sistema de coordenadas. */
  glLoadIdentity();
  
  gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f);
  
  }   /* fim da função Inicializa() */
  
int main(int argc, char ** argv) {
  int sizex, sizey;

  sizex = 500;
  sizey = 500;

  glutInit(&argc, argv);
  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   /* Avisa a GLUT que tipo de modo de exibição deve ser usado quando a janela é criada.       */
                                                 /* O primeiro significa que todos os comandos de desenho são executados para criar uma      */
						 /* cena fora da tela para depois rapidamente colocá-la na view (ou janela de visualização). */
						 /* O modo de cores RGBA significa que as cores são especificadas através do fornecimento de */
						 /* intensidades dos componentes red, green e blue separadas.                                */
  
  glutInitWindowSize(sizex,sizey); /* Especifica o tamanho em pixels da janela GLUT. */
  glutCreateWindow("Quadrado"); /* É o comando da biblioteca GLUT que cria a janela. */
  glutDisplayFunc(Desenha); /* Estabelece a função "Desenha()" previamente definida como a função callback de exibição. */
  
  Inicializa();
  glutMainLoop(); /* É a função que faz com que comece a execução da ?máquina de estados?    */
                  /* e processa todas as mensagens específicas do sistema operacional, tais  */
		  /* como teclas e botões do mouse pressionados, até que o programa termine. */

  return 0;
  }
  
/*

GL_LINES: exibe uma linha a cada dois comandos glVertex; 

GL_LINE_STRIP: exibe uma seqüência de linhas conectando os pontos 
               definidos por glVertex;

GL_LINE_LOOP: exibe uma seqüência de linhas conectando os
              definidos por glVertex e ao final liga o primeiro como 
              último ponto;

GL_POLYGON: exibe um polígono convexo preenchido, definido por uma 
            seqüência de chamadas a glVertex;

GL_TRIANGLES: exibe um triângulo preenchido a cada três pontos definidos 
              por glVertex;

GL_TRIANGLE_STRIP: exibe uma seqüência de triângulos baseados no 
                   trio de vértices v0, v1, v2, depois, v2, v1, v3, 
                   depois, v2, v3, v4 e assim por diante;

GL_TRIANGLE_FAN: exibe uma seqüência de triângulos conectados 
                 baseados no trio de vértices v0, v1, v2, depois, 
                 v0, v2, v3, depois, v0, v3, v4 e assim por diante;

GL_QUADS: exibe um quadrado preenchido conectando cada quatro pontos 
          definidos por glVertex;

GL_QUAD_STRIP: exibe uma seqüência de quadriláteros conectados a cada 
               quatro vértices; primeiro v0, v1, v3, v2, depois, v2, v3, v5, v4, 
               depois, v4, v5, v7, v6, e assim por diante.

*/
