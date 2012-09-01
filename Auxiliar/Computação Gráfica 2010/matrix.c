#include <stdio.h>
#include <math.h>
#define MAX 20

int main(){

char matrix[MAX][MAX];
float y1,x1,x2,y2,a,b,x,y;
int i, j,i2,aux;
printf("I'M BANANA");
	printf("x1 = ");
	scanf("%f" , &x1);
	printf("x2 = ");
	scanf("%f", &x2);
	printf("y1 = ");
	scanf("%f", &y1);
	printf("y2 = ");
	scanf("%f", &y2);
	a = (y2-y1)/(x2-x1);
	b = y1 - a*x1;
	printf("a : %f",a);
	printf("\nb: %f", b);
	//eq = a*x1+b;
	printf("\n\n");
    	for(i = 0 ; i < MAX; i++){
    		for(j = 0; j<MAX; j++){
    matrix[i][j] = 'Æ';
    }
    }

	/* PRIMEIRO METODO   */
	
    	
    i=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
    j=MAX;
    matrix[j][i] = 254;
    i = x2;
    j = MAX - y2;
    matrix[j][i] = 254;
    x = x1++;
    y = a*x + b; 
    
    while (y< y2 ){
       i = x;
       j = MAX - y;
       matrix[j][i] = 254;
       y = a*(++x) + b;
    }
    
    // Exibindo o segmento de reta
    for (j=0 ; j<MAX; j++){
       for (i=0; i<MAX ; i++){
          printf("%c",matrix[j][i]);
       }
       printf("\n");
    }
    printf("\n");
    
    	/* SEGUNDO METODO   */
    		for(i = 0 ; i < MAX; i++){
    		for(j = 0; j<MAX; j++){
    matrix[i][j] = '.';
    }
    }
    i2=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
    j=MAX;
    matrix[j][i] = 254;
    i2 = x2;
    j = MAX - y2;
    matrix[j][i2] = 254;
    x = x1++;
    y = a*x + b; 
    
    
    while (y< y2 ){
    
       i2 = x;
       aux = y;
          if (y/aux != 1){
          if(y/aux>=0.5)      
       j = MAX - y+1;
       else
          j = MAX - y-1;   
          }
       matrix[j][i2] = 254; 
          j = MAX -y;
       matrix[j][i2] = 254;
       y = a*(++x) + b;
    }
    
    // Exibindo o segmento de reta
    for (j=0 ; j<MAX; j++){
       for (i2=0; i2<MAX ; i2++){
          printf("%c",matrix[j][i2]);
       }
       printf("\n");
    }
    printf("\n");
    
    
    
    
    
    
    
    	/* TERCEIRO METODO   */
    	
    			for(i = 0 ; i < MAX; i++){
    		for(j = 0; j<MAX; j++){
    matrix[i][j] = '.';
    }
    }
    i=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
    j=MAX;
    matrix[j][i] = 254;
    i = x2;
    j = MAX - y2;
    matrix[j][i] = 254;
    x = x1++;
    y = a*x + b; 
    
    while (y< y2 ){
       i = x;
       aux = y;
          j = MAX - y;
             matrix[j][i] = 254; 
          if (y/aux != 1){
          if(y/aux>=0.5)      
       i = i+1;
       else
          i = i-1;   
          }
       matrix[j][i] = 254;   
       y = a*(++x) + b;
    }
    
    // Exibindo o segmento de reta
    for (j=0 ; j<MAX; j++){
       for (i=0; i<MAX ; i++){
          printf("%c",matrix[j][i]);
       }
       printf("\n");
    }
    printf("\n");
    
    	/* QUARTO METODO   */
    	
    i=x1;      // conversão implicita de um valor em ponto flutuante para um inteiro
    j=MAX;
    matrix[j][i] = 254;
    i = x2;
    j = MAX - y2;
    matrix[j][i] = 254;
    x = x1++;
    y = a*x + b; 
    
    while (y< y2 ){
       i = x;
       j = MAX - y;
       matrix[j][i] = 254;
       matrix[j+1][i] = 254;
          matrix[j-1][i] = 254;
       y = a*(++x) + b;
    }
    
    // Exibindo o segmento de reta
    for (j=0 ; j<MAX; j++){
       for (i=0; i<MAX ; i++){
          printf("%c",matrix[j][i]);
       }
       printf("\n");
    }
    printf("\n");

	system("PAUSE");
}
