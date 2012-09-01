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

     glutSwapBuffers(); /* Executa os comandos OpenGL - garante que o desenho é realizado. */
} /* fim da função Desenha() */

void Inicializa (void) {  /* Inicializa parâmetros de rendering. */
  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* É a função que determina a cor utilizada para limpar a janela. */
  
  }   /* fim da função Inicializa() */
  
void AlteraTamanhoJanela(GLsizei w, GLsizei h) { /* Função callback chamada quando o tamanho da janela é alterado. */

  if (h == 0) h = 1;   /* Para previnir uma divisão por zero. */   

  glViewport(0, 0, w, h); /* Especifica o tamanho da viewport. Recebe como parâmetro a nova largura e altura da janela. */

  glMatrixMode(GL_PROJECTION); /* Inicializa o sistema de coordenadas. */
  glLoadIdentity();

  if (w <= h) 
     gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w); /* Estabelece a janela de seleção (left, right, bottom, top) */
  else 
     gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
  
  }  /* fim da função AlteraTamanhoJanela() */


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
  
  glutReshapeFunc(AlteraTamanhoJanela); /* Estabelece a função "AlteraTamanhoJanela()" previamente definida como a */
                                        /* função callback de alteração do tamanho da janela. */

  Inicializa();
  glutMainLoop(); /* É a função que faz com que comece a execução da ?máquina de estados?    */
                  /* e processa todas as mensagens específicas do sistema operacional, tais  */
		  /* como teclas e botões do mouse pressionados, até que o programa termine. */

  return 0;
  }
