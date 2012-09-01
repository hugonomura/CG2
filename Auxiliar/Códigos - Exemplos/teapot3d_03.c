
/* Programa OpenGL para visualizar o Teapot (wire-frame) */
/* Autor: Murillo Rodrigo Petrucelli Homem, D.Sc. */

#include <GL/glut.h>

/* Declaração das variáveis globais ao programa */
GLdouble eyex, eyey, eyez;
GLdouble rot_ang, rot_eixo_x, rot_eixo_y, rot_eixo_z;
GLdouble Tx, Ty, Tz;

void Desenha(void) {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combinações de buffers, onde   */
                                                      /* buffer é uma área de armazenamento para informações da imagem. */
						      /* Neste caso, limpa o buffer de cor e de profundidade.           */

  glColor3f(0.0f, 0.0f, 1.0f);    /* Define a cor do desenho como azul. */

  glRotatef(rot_ang, rot_eixo_x, rot_eixo_y, rot_eixo_z);
  
  glMatrixMode(GL_PROJECTION);
  
  glTranslatef(Tx, Ty, Tz);
  
  glMatrixMode(GL_MODELVIEW);
  
  glutWireTeapot(40.0f);   /* Desenha o teapot (wire-frame) com a cor corrente. */

  glutSwapBuffers(); /* Executa os comandos OpenGL - garante que o desenho é realizado. */
   
  }  /* fim da função Desenha() */
  

void Inicializa (void) {  /* Inicializa parâmetros de rendering. */
  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* É a função que determina a cor utilizada para limpar a janela. */

  eyex = 0.0;
  eyey = 0.0;
  eyez = 200.0;
  
  rot_ang = 0.0;
  rot_eixo_x = 0.0;
  rot_eixo_y = 0.0;
  rot_eixo_z = 0.0;
  
  Tx = 0.0;
  Ty = 0.0;
  Tz = 0.0;
  
  }   /* fim da função Inicializa() */


void AlteraTamanhoJanela(GLsizei w, GLsizei h) { /* Função callback chamada quando o tamanho da janela é alterado e para */
                                                 /* especificar o volume de visualização. */

  glViewport(0, 0, w, h); /* Especifica o tamanho da viewport. Recebe como parâmetro a nova largura e altura da janela. */  
 
  glMatrixMode(GL_PROJECTION);  /* Especifica sistema de coordenadas de projeção. */
  glLoadIdentity(); /* Inicializa sistema de coordenadas de projeção. */
  
  glOrtho(-150.0f, 150.0f, -150.0f, 150.0f, 0.1f, 500.0f); /* Especifica uma projeção paralela. */

  glMatrixMode(GL_MODELVIEW);   /* Especifica sistema de coordenadas do modelo. */
  glLoadIdentity();   /* Inicializa sistema de coordenadas do modelo. */

  gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);   /* Especifica a posição do observador e do alvo. */
  /* Experimente comentar esta linha. O que acontece? Por quê? */
  
  }  /* fim da função AlteraTamanhoJanela() */


void GerenciaTeclado(unsigned char key, int x, int y) { /* Função chamada para gerenciar eventos de teclado. */
  switch (key) {
    case 'x':
          rot_ang = 10.0;
          rot_eixo_x = 1.0;
          rot_eixo_y = 0.0;
          rot_eixo_z = 0.0;
	  Tx = 0.0;
          break;
    case 'y':
          rot_ang = 10.0;
          rot_eixo_x = 0.0;
          rot_eixo_y = 1.0;
          rot_eixo_z = 0.0;
	  Tx = 0.0;
          break;
    case 'z':
          rot_ang = 10.0;
          rot_eixo_x = 0.0;
          rot_eixo_y = 0.0;
          rot_eixo_z = 1.0;
	  Tx = 0.0;
          break;
    case '.':
         rot_ang = 0.0;
         Tx = 10.0;
	 break;
    case ',':
         rot_ang = 0.0;
         Tx = -10.0;
	 break;
    }
    
  glutPostRedisplay();
  
  }  /* fim da função GerenciaTeclado() */
  


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
  glutCreateWindow("Teapot 3D"); /* É o comando da biblioteca GLUT que cria a janela. */
  glutDisplayFunc(Desenha); /* Estabelece a função "Desenha()" previamente definida como a função callback de exibição. */
  
  glutReshapeFunc(AlteraTamanhoJanela); /* Estabelece a função "AlteraTamanhoJanela()" previamente definida como a */
                                        /* função callback de alteração do tamanho da janela. */
					
  glutKeyboardFunc(GerenciaTeclado);    /* Estabelece a função "GerenciaTeclado()" previamente definida como a */
                                        /* função callback de gerenciamento do teclado. */ 
  Inicializa();
  glutMainLoop(); /* É a função que faz com que comece a execução da “máquina de estados”    */
                  /* e processa todas as mensagens específicas do sistema operacional, tais  */
		  /* como teclas e botões do mouse pressionados, até que o programa termine. */

  return 0;
  }
