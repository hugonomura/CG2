#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <allegro.h>
#include <X11/Xlib.h>
//#include <GL/glut.h>

#define EventMask (KeyPressMask | ExposureMask)

#define PI 3.1415926535

float XWMax, XWMin, YWMax, YWMin;

struct Window {
  float xmin,
        xmax,
        ymin,
        ymax;
        };
      
typedef struct Window window;

struct ViewPort {
  int xmin,
      xmax,
      ymin,
      ymax;
      };
      
typedef struct Viewport viewport;

struct Point2D {
  float x,
        y;
  int   color;
  };
      
typedef struct Point2D point;

struct Object2D {
  int numbers_of_points;
  point * points;
  };
  
typedef struct Object2D object;  

struct Color {
  float red,
        green,
        blue;
        };
      
typedef struct Color ColorValues;    
  
struct Palette {
  int numbers_of_colors;
  ColorValues * colors;
  };

typedef struct Palette palette;

struct Buffer {
  int MaxX,
      MaxY;
  int * buffer;
  };

typedef struct Buffer bufferdevice;

struct HPoint2D {
  float x,
        y,
        w;
        };

typedef struct HPoint2D hpoint;

struct HMatrix2D {
  float a11, a12, a13,
        a21, a22, a23,
        a31, a32, a33;
        };

typedef struct HMatrix2D hmatrix;

void SetWorld(float, float, float, float);
point * SetPoint(float, float, int);
object * CreateObject(int);
int SetObject(point *, object *);
object * ChangeColor(object *, int);
palette * CreatePalette(int);
int SetColor(float, float, float, palette *);
ColorValues * GetColor(int, palette *);
bufferdevice * CreateBuffer(int, int);
window * CreateWindow(float, float, float, float);
point * Sru2Srn(point *, window *);
point * Srn2Srd(point *, bufferdevice *);
int InWin(point *, window *);
point * InterX(point *, point *, float);
point * InterY(point *, point *, float);
int DrawLine(point *, point *, window *, bufferdevice *, int);
int DrawObject(object *, window *, bufferdevice *);
int FillObject(bufferdevice *, int);
int Fill(object *, window *, bufferdevice *, int);
void CopyBuffer2Device(bufferdevice *, bufferdevice *);
object * Rotate(object *, float);
object * Translate(object *, float, float);
object * Scale(object *, float, float);
hpoint * LinearTransf(hmatrix *, hpoint *);
hmatrix * ComposeMatrix(hmatrix *, hmatrix *);
hmatrix * SetRotMatrix(float);
hmatrix * SetSclMatrix(float, float);
hmatrix * SetSftMatrix(float, float);
ColorValues * RGB2HSV(ColorValues *);
ColorValues * HSV2RGB(ColorValues *);
int DumpX(bufferdevice *, palette *);
int DumpAllegro(bufferdevice *, palette *);
void Desenha(void);
int DumpOpenGL(int, char **, bufferdevice *, palette *);
