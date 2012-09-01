#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void Desenha(void) /* Fun��o callback chamada para fazer o desenho. */
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT); /* Limpa a janela de visualiza��o com a cor de fundo especificada */

     /* Especifica que a cor corrente � vermelha */
     /*         R     G     B                    */
     glColor3f(1.0f, 0.0f, 0.0f);

     glBegin(GL_QUADS); /* Desenha um quadrado preenchido com a cor corrente */
               glVertex2i(100,150);
               glVertex2i(100,100);
               glColor3f(0.0f, 0.0f, 1.0f); /* Especifica que a cor corrente � azul */
               glVertex2i(150,100);
               glVertex2i(150,150);               
     glEnd();

     glutSwapBuffers(); /* Executa os comandos OpenGL - garante que o desenho � realizado. */
} /* fim da fun��o Desenha() */

void Inicializa (void) {  /* Inicializa par�metros de rendering. */
  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* � a fun��o que determina a cor utilizada para limpar a janela. */
  
  }   /* fim da fun��o Inicializa() */
  
void AlteraTamanhoJanela(GLsizei w, GLsizei h) { /* Fun��o callback chamada quando o tamanho da janela � alterado. */

  if (h == 0) h = 1;   /* Para previnir uma divis�o por zero. */   

  glViewport(0, 0, w, h); /* Especifica o tamanho da viewport. Recebe como par�metro a nova largura e altura da janela. */

  glMatrixMode(GL_PROJECTION); /* Inicializa o sistema de coordenadas. */
  glLoadIdentity();

  if (w <= h) 
     gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w); /* Estabelece a janela de sele��o (left, right, bottom, top) */
  else 
     gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
  
  }  /* fim da fun��o AlteraTamanhoJanela() */


int main(int argc, char ** argv) {
  int sizex, sizey;

  sizex = 500;
  sizey = 500;

  glutInit(&argc, argv);
  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   /* Avisa a GLUT que tipo de modo de exibi��o deve ser usado quando a janela � criada.       */
                                                 /* O primeiro significa que todos os comandos de desenho s�o executados para criar uma      */
						 /* cena fora da tela para depois rapidamente coloc�-la na view (ou janela de visualiza��o). */
						 /* O modo de cores RGBA significa que as cores s�o especificadas atrav�s do fornecimento de */
						 /* intensidades dos componentes red, green e blue separadas.                                */
  
  glutInitWindowSize(sizex,sizey); /* Especifica o tamanho em pixels da janela GLUT. */
  glutCreateWindow("Quadrado"); /* � o comando da biblioteca GLUT que cria a janela. */
  glutDisplayFunc(Desenha); /* Estabelece a fun��o "Desenha()" previamente definida como a fun��o callback de exibi��o. */
  
  glutReshapeFunc(AlteraTamanhoJanela); /* Estabelece a fun��o "AlteraTamanhoJanela()" previamente definida como a */
                                        /* fun��o callback de altera��o do tamanho da janela. */

  Inicializa();
  glutMainLoop(); /* � a fun��o que faz com que comece a execu��o da ?m�quina de estados?    */
                  /* e processa todas as mensagens espec�ficas do sistema operacional, tais  */
		  /* como teclas e bot�es do mouse pressionados, at� que o programa termine. */

  return 0;
  }
