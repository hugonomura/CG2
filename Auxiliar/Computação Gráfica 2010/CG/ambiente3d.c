/* Programa OpenGL para gerar um ambiente 3D simples */
/* Autor: prof. Murillo Rodrigo Petrucelli Homem     */

/* Para compilar o programa digite: gcc ambiente3d.c -o ambiente3d -lGLU -lglut -lGL */

#include <GL/glut.h>

/* Declaração das variáveis globais ao programa */
GLdouble angle, fAspect;
GLdouble eyex, eyey, eyez, alvox, alvoy, alvoz; /* variáveis que definem a posição da  */
                                                /* câmera e para onde ela está olhando */

void Desenha(void) {

  /* Limpa o buffer de cor e de profundidade */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

  /* começa a fazer os desenhos */

  /* desenha o chão */
  glBegin(GL_QUADS);
     glColor3f(0.0f, 1.0f, 0.0f);  /* Muda a cor do chão */
     glNormal3f(0.0, 1.0, 0.0);    /* Normal da face */
     /* É necessário informar o vetor normal de cada face, pois OpenGL */
     /* usa esta informação para calcular a cor de cada face de acordo */
     /* com os parâmetros de iluminação. */
     glVertex3f(-120, -100, -300);
     glVertex3f( 120, -100, -300);
     glVertex3f( 120, -100,  300);
     glVertex3f(-120, -100,  300);
  glEnd();
  
  /* parede do fundo */
  glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 1.0f);  /* Muda a cor da parede do fundo */
     glNormal3f(0.0, 0.0, 1.0);    /* Normal da face */
     glVertex3f(-120, -100, -300);
     glVertex3f(-120,  100, -300);
     glVertex3f( 120,  100, -300);
     glVertex3f( 120, -100, -300);
  glEnd();
  
  /* parede do lado esquerdo */
  glBegin(GL_QUADS);
     glColor3f(1.0f, 0.0f, 0.0f);  /* Muda a cor da parede esquerda */
     glNormal3f(1.0, 0.0, 0.0);    /* Normal da face */
     glVertex3f(-120, -100, -300);
     glVertex3f(-120, -100,  300);
     glVertex3f(-120,  100,  300);
     glVertex3f(-120,  100, -300);
  glEnd();
  
  /* parede do lado direito */
  glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 0.0f);  /* Muda a cor da parede direita */
     glNormal3f(-1.0, 0.0, 0.0);   /* Normal da face */
     glVertex3f(120, -100, -300);
     glVertex3f(120, -100,  300);
     glVertex3f(120,  100,  300);
     glVertex3f(120,  100, -300);
  glEnd();  

  /* desenha o teto */
  glBegin(GL_QUADS);
     glColor3f(0.0f, 1.0f, 1.0f);   /* Muda a cor do chão */
     glNormal3f(0.0, -1.0, 0.0);    /* Normal da face */
     glVertex3f(-120, 100, -300);
     glVertex3f( 120, 100, -300);
     glVertex3f( 120, 100,  300);
     glVertex3f(-120, 100,  300);
  glEnd();
  
  /* desenha o primeiro pilar */
  glBegin(GL_QUADS);
  
     glColor3f(1.0f, 0.0f, 1.5f);  /* Muda a cor da parede do pilar */
     
     glNormal3f(0.0, 0.0, 1.0);    /* Normal da face da frente */
     glVertex3f(30, -100, 140);
     glVertex3f(30,  100, 140);
     glVertex3f(50,  100, 140);
     glVertex3f(50, -100, 140);
     
     glNormal3f(0.0, 0.0, -1.0);   /* Normal da face do fundo */
     glVertex3f(30, -100, 120);
     glVertex3f(30,  100, 120);
     glVertex3f(50,  100, 120);
     glVertex3f(50, -100, 120);
     
     glNormal3f(-1.0, 0.0, 0.0);   /* Normal da face esquerda */
     glVertex3f(30, -100, 120);
     glVertex3f(30, -100, 140);
     glVertex3f(30,  100, 140);
     glVertex3f(30,  100, 120);
     
     glNormal3f(1.0, 0.0, 0.0);    /* Normal da face direita */
     glVertex3f(50, -100, 120);
     glVertex3f(50, -100, 140);
     glVertex3f(50,  100, 140);
     glVertex3f(50,  100, 120);          

  glEnd();
  
  /* desenha o segundo pilar */
  glBegin(GL_QUADS);
  
     glColor3f(1.5f, 0.5f, 0.0f);  /* Muda a cor da parede do pilar */
     
     glNormal3f(0.0, 0.0, 1.0);    /* Normal da face da frente */
     glVertex3f(-30, -100, -120);
     glVertex3f(-30,  100, -120);
     glVertex3f(-50,  100, -120);
     glVertex3f(-50, -100, -120);
     
     glNormal3f(0.0, 0.0, -1.0);   /* Normal da face do fundo */
     glVertex3f(-30, -100, -130);
     glVertex3f(-30,  100, -130);
     glVertex3f(-50,  100, -130);
     glVertex3f(-50, -100, -130);
     
     glNormal3f(-1.0, 0.0, 0.0);   /* Normal da face esquerda */
     glVertex3f(-30, -100, -130);
     glVertex3f(-30, -100, -120);
     glVertex3f(-30,  100, -120);
     glVertex3f(-30,  100, -130);
     
     glNormal3f(1.0, 0.0, 0.0);    /* Normal da face direita */
     glVertex3f(-50, -100, -130);
     glVertex3f(-50, -100, -120);
     glVertex3f(-50,  100, -120);
     glVertex3f(-50,  100, -130);          

  glEnd();  

  /* encerra os desenhos */
    
  /* garante que o desenho é realizado */
  glutSwapBuffers(); 
   
  }  /* fim da função Desenha() */

  

void Inicializa (void) {  /* Inicializa os parâmetros para o "rendering" */  

                          /* Renderização é a obtenção da imagem a partir do modelo.      */
                          /* É nesse processo que se adiciona, por exemplo, sombreamento, */
                          /* cores e iluminação na cena.                                  */
  
  /* Cor da luz ambiente default para uma cena. */
  /* Essa é a luz proveniente de uma fonte que não é possível determinar. */
  GLfloat luzAmbiente[4] = {0.5, 0.5, 0.5, 1.0};
  
  /* Componente de luz refletida em todas as direções quando esta incide sobre o objeto, */
  /* proveniente de uma direção específica. */
  GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
  
  /* Componente de luz refletida em uma determinada direção quando esta incide sobre o objeto, */
  /* proveniente de uma direção específica. */
  GLfloat luzEspecular[4] = {0.8, 0.8, 0.8, 1.0};
  
  /* Define a posição da fonte de luz (pode haver mais de uma fonte). */
  GLfloat posicaoLuz[4] = {-120.0, 100.0, -120.0, 1.0};
  
  /* Capacidade de brilho do material */
  GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0}; 
  GLint especMaterial = 70;
  
  /* Especifica que a cor de fundo da janela será preta */
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
  /* Parâmetros usados na projeção perspectiva */
  angle = 50.0;
  fAspect = 1.0;
  
  /* Parâmetros que definem a posição da câmera e para onde ela está "olhando" */
  eyex = 0.0;  /* Posição da câmera... */
  eyey = 0.0;
  eyez = 600.0;
  
  alvox = 0.0; /* ...e para onde ela está olhando. */
  alvoy = 0.0;    /* Estou assumindo que o centro do desenho está na */ 
  alvoz = -300.0; /* origem do sistema de coordenadas.               */
  
  /* Estabelece o modelo de colorização: GL_SMOOTH ou GL_FLAT */
  glShadeModel(GL_FLAT);

  /* Estabelece os parâmetros do modelo de iluminação usado no OpenGL:               */
  /* GL_LIGHT_MODEL_AMBIENT é usado para especificar a luz ambiente default para     */ 
  /* uma cena.                                                                       */ 
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
  
  /* Define os parâmetros de iluminação para o objeto */
  glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);   /* Define a refletância do material */
  glMateriali(GL_FRONT,GL_SHININESS,especMaterial);     /* Define a concentração do brilho */
   
  /* Define os parâmetros da luz de número 0 */
  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

  /* Habilita a definição da cor do material */
  glEnable(GL_COLOR_MATERIAL);
  
  /* Habilita o uso de iluminação */
  glEnable(GL_LIGHTING);  
  
  /* Habilita a luz de número 0 */
  glEnable(GL_LIGHT0);
  
  /* Habilita o depth-buffering */
  glEnable(GL_DEPTH_TEST);

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
  gluPerspective(angle,fAspect,0.1,1500);
  
  /* Especifica sistema de coordenadas do modelo */
  glMatrixMode(GL_MODELVIEW);
  /* Inicializa sistema de coordenadas do modelo */
  glLoadIdentity(); 

  /* Especifica posição do observador e do alvo */
  /* Protótipo: void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, 
                                GLdouble centerx, GLdouble centery, GLdouble centerz, 
                                GLdouble upx, GLdouble upy, GLdouble upz ); */
  gluLookAt(eyex,eyey,eyez,alvox,alvoy,alvoz,0,1,0);
  
  }  /* fim da função EspecificaParametrosVisualizacao() */



/* Função chamada quando o tamanho da janela é alterado */
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
    /* opções que movimentam a câmera em relação a posição inicial: */     
    case 'd':
          eyex = eyex + 10;  /* move a câmera para a direita */
          break;
    case 'e':
          eyex = eyex - 10;  /* move a câmera para a esquerda */
          break;
    case 'f':
          eyez = eyez - 10;  /* move a câmera para a frente */
          break;
    case 't':
          eyez = eyez + 10;  /* move a câmera para trás */
          break;
          
    /* opções que movimentam o ponto que a câmera está olhando: */      
    case 'r':
          alvox = alvox + 10;  /* move o ponto para a direita */
          break;
    case 'l':
          alvox = alvox - 10;  /* move o ponto para a esquerda */     
          break;
    case 'x':
          alvoz = alvoz + 10;  /* move o ponto para a frente */
          break;
    case 'y':
          alvoz = alvoz - 10;  /* move o ponto para trás */ 
          break;
          
    /* altera o ângulo de visão da câmera */      
    case 'a':
          angle = angle + 10;
          break; 
    case 'b':
          angle = angle - 10;
          break;         
    }
    
  EspecificaParametrosVisualizacao();  /* atualiza os parâmetros da câmera */
  glutPostRedisplay();
  
  }  /* fim da função GerenciaTeclado() */


int main(int argc, char **argv) {
  int sizex, sizey;

  sizex = 500;
  sizey = 500;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(sizex,sizey);
  glutCreateWindow("Ambiente 3D");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutKeyboardFunc(GerenciaTeclado);
  Inicializa();
  glutMainLoop();

  return 0;
  }

