#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#include <math.h>

#define PI 3.14159265 

void desenharReta(float xInicial,float yInicial,float xFinal,float yFinal, float a, float b, int abordagem);

struct ponto2D{
       float x,y;
} ponto;

int  matriz[20][20];

int main(){
    float xInicial, xFinal, yInicial, yFinal, temp, y, a, b, xStart, yStart;
    int i, j, iY, x,abordagem = 0, numP, n = 1, flag = 0;
    
    //inicializar janela
    for(i = 0; i < 20; i++){
          for(j = 0; j < 20; j++){
                matriz[i][j] = 0;
          }
    }
    
    //escolher abordagem para desenhar reta
    while(abordagem <= 0 || abordagem > 4){
        printf("Informe a abordagem (1,2,3 ou 4): ");
        scanf("%d",&abordagem);
    }    
    
    //pegar o numero de pontos do poligono
    printf("Informe o numero de pontos do poligono: ");
    scanf("%d", &numP);
    
    
    //desenhar uma reta
    //pegar dois pontos
    printf("Informe o X do 1o. ponto: ");
    scanf("%f", &xInicial);
    printf("Informe o Y do 1o. ponto: ");
    scanf("%f", &yInicial);
    xStart = xInicial;
    yStart = yInicial;
    while(n < numP){
        printf("Informe o X do proximo ponto: ");
        scanf("%f", &xFinal);
        printf("Informe o Y do proximo ponto: ");
        scanf("%f", &yFinal);

        printf("xINicial: %f, yInicial: %f, xFinal: %f, yFinal: %f",xInicial,yInicial,xFinal,yFinal);
        getch();

        //verificar ordem dos pontos
        if(xFinal < xInicial){
                  temp = xInicial;
                  xInicial = xFinal;
                  xFinal = temp;
                  
                  temp = yInicial;
                  yInicial = yFinal;
                  yFinal = temp;
                  flag = 1;
        }
    
        //calcular eq da reta
        a = (yFinal - yInicial)/(xFinal - xInicial);
        b = yInicial - (a*xInicial);
        
        desenharReta(xInicial,  yInicial, xFinal, yFinal, a, b,abordagem); 
        
    printf("\nJanela: \n");
    for(i = 0; i < 20; i++){      
          printf("\n");
          for(j = 0; j < 20; j++){
                printf(" %d", matriz[i][j]);
          }
    }
        if(flag == 0){
                xInicial = xFinal;
                yInicial = yFinal;
        }
        n++;
    }
    //verificar ordem dos pontos
    if(xStart < xInicial){
              temp = xInicial;
              xInicial = xStart;
              xStart = temp;
              
              temp = yInicial;
              yInicial = yStart;
              yStart = temp;
    }

    //calcular eq da reta
    a = (yStart - yInicial)/(xStart - xInicial);
    b = yInicial - (a*xInicial);
    
    desenharReta(xInicial, yInicial, xStart, yStart,a,b,abordagem);
   
    printf("\nJanela: \n");
    for(i = 0; i < 20; i++){      
          printf("\n");
          for(j = 0; j < 20; j++){
                printf(" %d", matriz[i][j]);
          }
    }
        
    getch();
    return 0;
    
}

void desenharReta(float xInicial,float yInicial,float xFinal,float yFinal, float a, float b,int abordagem){
     float y, dif;
     int i,j,x,iY, aux;
     if(xInicial == xFinal){
             if(yInicial > yFinal){
                          i = yFinal;
                          aux = yInicial;
             }
             else{
                  i = yInicial;
                  aux = yFinal;
             }
             for (; i <= aux; i++){
                 x = xInicial;
                 matriz[x][i] = 1;
             }
    }
    else{
        if(yInicial == yFinal){
                     for (i = xInicial; i <= xFinal; i++){
                         iY = yInicial;
                         matriz[i][iY] = 1;
                     }
        }
        else{

     //calcular todos os pontos
        for(i = xInicial; i <= xFinal; i++){
              x = i;
              y = a*x + b;
              iY = y;
              printf("\na: %f, b:%f, X: %d, y: %f, iY: %d\n",a,b,x,y,iY);
              dif = y - iY;
              printf("dif : %f", dif);
              getch();
              switch(abordagem){
                                case 1:
                                     matriz[x][iY] = 1;
                                     if(dif != 0)
                                          matriz[x][iY+1] = 1;
                                     break;
                                case 2:
                                     if(y - iY == 0.5){
                                          matriz[x][iY] = 1;
                                          matriz[x][iY+1] = 1;
                                     }else
                                         if(y - iY < 0.5)
                                              matriz[x][iY] = 1;
                                         else
                                              matriz[x][iY+1] = 1;
                                     break;
                                case 3:
                                     if(y - iY >= 0.5)
                                          matriz[x][iY+1] = 1;
                                     else
                                          matriz[x][iY] = 1;
                                     break;
                                case 4:
                                     if(y - iY == 0)
                                          matriz[x][iY] = 1;
                                     break;
              
                                     }
              }
        }
        }
}
