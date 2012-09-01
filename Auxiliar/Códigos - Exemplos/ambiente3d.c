/* Programa OpenGL para gerar um ambiente 3D simples */
/* Autor: Murillo Rodrigo Petrucelli Homem, D.Sc.    */

#include <GL/glut.h>

/* Declara��o das vari�veis globais ao programa */
GLdouble angle, fAspect;
GLdouble eyex, eyey, eyez, alvox, alvoy, alvoz; /* vari�veis que definem a posi��o da  */
                                                /* c�mera e para onde ela est� olhando */

void Desenha(void) {

  /* Limpa o buffer de cor e de profundidade */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

  /* come�a a fazer os desenhos */

  /* desenha o ch�o */
  glBegin(GL_QUADS);
     glColor3f(0.0f, 1.0f, 0.0f);  /* Muda a cor do ch�o */
     glNormal3f(0.0, 1.0, 0.0);    /* Normal da face */
     /* � necess�rio informar o vetor normal de cada face, pois OpenGL */
     /* usa esta informa��o para calcular a cor de cada face de acordo */
     /* com os par�metros de ilumina��o. */
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
     glColor3f(0.0f, 1.0f, 1.0f);   /* Muda a cor do ch�o */
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
    
  /* garante que o desenho � realizado */
  glutSwapBuffers(); 
   
  }  /* fim da fun��o Desenha() */

  

void Inicializa (void) {  /* Inicializa os par�metros para o "rendering" */  

                          /* Renderiza��o � a obten��o da imagem a partir do modelo.      */
                          /* � nesse processo que se adiciona, por exemplo, sombreamento, */
                          /* cores e ilumina��o na cena.                                  */
  
  /* Cor da luz ambiente default para uma cena. */
  /* Essa � a luz proveniente de uma fonte que n�o � poss�vel determinar. */
  GLfloat luzAmbiente[4] = {0.5, 0.5, 0.5, 1.0};
  
  /* Componente de luz refletida em todas as dire��es quando esta incide sobre o objeto, */
  /* proveniente de uma dire��o espec�fica. */
  GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
  
  /* Componente de luz refletida em uma determinada dire��o quando esta incide sobre o objeto, */
  /* proveniente de uma dire��o espec�fica. */
  GLfloat luzEspecular[4] = {0.8, 0.8, 0.8, 1.0};
  
  /* Define a posi��o da fonte de luz (pode haver mais de uma fonte). */
  GLfloat posicaoLuz[4] = {-120.0, 100.0, -120.0, 1.0};
  
  /* Capacidade de brilho do material */
  GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0}; 
  GLint especMaterial = 70;
  
  /* Especifica que a cor de fundo da janela ser� preta */
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  
  /* Par�metros usados na proje��o perspectiva */
  angle = 50.0;
  fAspect = 1.0;
  
  /* Par�metros que definem a posi��o da c�mera e para onde ela est� "olhando" */
  eyex = 0.0;  /* Posi��o da c�mera... */
  eyey = 0.0;
  eyez = 600.0;
  
  alvox = 0.0; /* ...e para onde ela est� olhando. */
  alvoy = 0.0;    /* Estou assumindo que o centro do desenho est� na */ 
  alvoz = -300.0; /* origem do sistema de coordenadas.               */
  
  /* Estabelece o modelo de coloriza��o: GL_SMOOTH ou GL_FLAT */
  glShadeModel(GL_FLAT);

  /* Estabelece os par�metros do modelo de ilumina��o usado no OpenGL:               */
  /* GL_LIGHT_MODEL_AMBIENT � usado para especificar a luz ambiente default para     */ 
  /* uma cena.                                                                       */ 
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
  
  /* Define os par�metros de ilumina��o para o objeto */
  glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);   /* Define a reflet�ncia do material */
  glMateriali(GL_FRONT,GL_SHININESS,especMaterial);     /* Define a concentra��o do brilho */
   
  /* Define os par�metros da luz de n�mero 0 */
  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

  /* Habilita a defini��o da cor do material */
  glEnable(GL_COLOR_MATERIAL);
  
  /* Habilita o uso de ilumina��o */
  glEnable(GL_LIGHTING);  
  
  /* Habilita a luz de n�mero 0 */
  glEnable(GL_LIGHT0);
  
  /* Habilita o depth-buffering */
  glEnable(GL_DEPTH_TEST);

  }   /* fim da fun��o Inicializa() */



/* Fun��o usada para especificar o volume de visualiza��o */
void EspecificaParametrosVisualizacao(void) {

  /* Especifica sistema de coordenadas de proje��o */
  glMatrixMode(GL_PROJECTION); 
  /* Inicializa sistema de coordenadas de proje��o */
  glLoadIdentity(); 

  /* Especifica a proje��o perspectiva */
  /* Prot�tipo: void gluPerspective( GLdouble fovy, GLdouble aspect, 
                                     GLdouble zNear, GLdouble zFar ); */
  gluPerspective(angle,fAspect,0.1,1500);
  
  /* Especifica sistema de coordenadas do modelo */
  glMatrixMode(GL_MODELVIEW);
  /* Inicializa sistema de coordenadas do modelo */
  glLoadIdentity(); 

  /* Especifica posi��o do observador e do alvo */
  /* Prot�tipo: void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, 
                                GLdouble centerx, GLdouble centery, GLdouble centerz, 
                                GLdouble upx, GLdouble upy, GLdouble upz ); */
  gluLookAt(eyex,eyey,eyez,alvox,alvoy,alvoz,0,1,0);
  
  }  /* fim da fun��o EspecificaParametrosVisualizacao() */



/* Fun��o chamada quando o tamanho da janela � alterado */
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
  
  /* Para previnir uma divis�o por zero */   
  if (h == 0) h = 1; 

  /* Especifica o tamanho da viewport */
  glViewport(0, 0, w, h);

  /* Calcula a corre��o de aspecto */
  fAspect = (GLfloat)w/(GLfloat)h;

  EspecificaParametrosVisualizacao();
  
  }  /* fim da fun��o AlteraTamanhoJanela() */

  
/* Fun��o chamada para gerenciar eventos de teclado */
void GerenciaTeclado(unsigned char key, int x, int y) {
  switch (key) {
    /* op��es que movimentam a c�mera em rela��o a posi��o inicial: */     
    case 'd':
          eyex = eyex + 10;  /* move a c�mera para a direita */
          break;
    case 'e':
          eyex = eyex - 10;  /* move a c�mera para a esquerda */
          break;
    case 'f':
          eyez = eyez - 10;  /* move a c�mera para a frente */
          break;
    case 't':
          eyez = eyez + 10;  /* move a c�mera para tr�s */
          break;
          
    /* op��es que movimentam o ponto que a c�mera est� olhando: */      
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
          alvoz = alvoz - 10;  /* move o ponto para tr�s */ 
          break;
          
    /* altera o �ngulo de vis�o da c�mera */      
    case 'a':
          angle = angle + 10;
          break; 
    case 'b':
          angle = angle - 10;
          break;         
    }
    
  EspecificaParametrosVisualizacao();  /* atualiza os par�metros da c�mera */
  glutPostRedisplay();
  
  }  /* fim da fun��o GerenciaTeclado() */


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
  glutInitWindowSize(sizex,sizey);
  glutCreateWindow("Ambiente 3D");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutKeyboardFunc(GerenciaTeclado);
  Inicializa();
  glutMainLoop();

  return 0;
  }

