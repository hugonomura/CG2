
/* Programa OpenGL para visualizar o Teapot (wire-frame) */
/* Autor: prof. Murillo Rodrigo Petrucelli Homem */

/* Para compilar o programa digite: gcc teapot3d.c -o teapot3d -lGLU -lglut -lGL */

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>


/* Declaração das variáveis globais ao programa */
GLdouble angle, fAspect;
GLdouble eyex, eyey, eyez;
GLdouble rot_ang, rot_eixo_x, rot_eixo_y, rot_eixo_z;


void Desenha(void) {

  /* Limpa o buffer de cor e de profundidade */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

  /* define a cor do desenho como azul */
  glColor3f(0.0f, 0.0f, 1.0f);  

  glRotatef(rot_ang, rot_eixo_x, rot_eixo_y, rot_eixo_z);
  glScalef(1.0f, 1.0f, 1.0f);

  /* Desenha o teapot (wire-frame) com a cor corrente */
  glutWireTeapot(40.0f);

  /* garante que o desenho é realizado */
  glutSwapBuffers(); 
   
  }  /* fim da função Desenha() */

  

void Inicializa (void) {
  /* Inicializa parâmetros de rendering */  
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
  angle = 45.0;
  fAspect = 1.0;
  
  eyex = 0.0;
  eyey = 0.0;
  eyez = 200.0;
  
  rot_ang = 0.0;
  rot_eixo_x = 0.0;
  rot_eixo_y = 0.0;
  rot_eixo_z = 0.0;
  
  }   /* fim da função Inicializa() */



/* Função usada para especificar o volume de visualização */
void EspecificaParametrosVisualizacao(void) {

  /* Especifica sistema de coordenadas de projeção */
  glMatrixMode(GL_PROJECTION); 
  /* Inicializa sistema de coordenadas de projeção */
  glLoadIdentity(); 

  /* Especifica a projeção perspectiva */
  /* Protótipo: void gluPerspective( GLdouble fovy, GLdouble aspect, 
                                     GLdouble zNear, GLdouble zFar ); */
  gluPerspective(angle,fAspect,0.1,500);

  /* Especifica sistema de coordenadas do modelo */
  glMatrixMode(GL_MODELVIEW);
  /* Inicializa sistema de coordenadas do modelo */
  glLoadIdentity(); 

  /* Especifica posição do observador e do alvo */
  /* Protótipo: void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, 
                                GLdouble centerx, GLdouble centery, GLdouble centerz, 
                                GLdouble upx, GLdouble upy, GLdouble upz ); */
  gluLookAt(eyex,eyey,eyez,0,0,0,0,1,0);
  
  }  /* fim da função EspecificaParametrosVisualizacao() */



/* Função callback chamada quando o tamanho da janela é alterado */
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
  
  /* Para previnir uma divisão por zero */   
  if (h == 0) h = 1; 

  /* Especifica o tamanho da viewport */
  glViewport(0, 0, w, h);

  /* Calcula a correção de aspecto */
  fAspect = (GLfloat)w/(GLfloat)h;

  EspecificaParametrosVisualizacao();
  
  }  /* fim da função AlteraTamanhoJanela() */



/* Função chamada para gerenciar eventos de teclado */
void GerenciaTeclado(unsigned char key, int x, int y) {
  switch (key) {
    case 'x':
          rot_ang = 10.0;
          rot_eixo_x = 1.0;
          rot_eixo_y = 0.0;
          rot_eixo_z = 0.0;
          break;
    case 'y':
          rot_ang = 10.0;
          rot_eixo_x = 0.0;
          rot_eixo_y = 1.0;
          rot_eixo_z = 0.0;
          break;
    case 'z':
          rot_ang = 10.0;
          rot_eixo_x = 0.0;
          rot_eixo_y = 0.0;
          rot_eixo_z = 1.0;
          break;
    }
    
  glutPostRedisplay();
  
  }  /* fim da função GerenciaTeclado() */
  


int main(int argc, char ** argv) {
  int sizex, sizey;

  sizex = 500;
  sizey = 500;

  glutInit(&argc, argv);  /* modificação */
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(sizex,sizey);
  glutCreateWindow("Teapot 3D");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutKeyboardFunc(GerenciaTeclado);
  Inicializa();
  glutMainLoop();

  return 0;
  }


