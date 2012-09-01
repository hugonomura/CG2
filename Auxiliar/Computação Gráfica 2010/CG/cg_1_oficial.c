 #include <stdio.h>
#define TAM 20


int main(void){
	int i,j,op=1,x,y;
	float x1, y1, x2, y2, a, b;
	char mat[TAM][TAM];
	//Inicializa a matriz com espacos
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            mat[i][j] = '.';
        }
    }

while(op){

	printf("Digite as coordenadas do ponto A:\n");
	scanf("%f %f", &x1, &y1);
	printf("Digite as coordenadas do ponto B:\n");
	scanf("%f %f", &x2, &y2);

	a = (y1 - y2) / (x1 - x2);
	b = y1 - x1*((y1 - y2)/(x1 - x2));
    
    
    x=a;
    //if(a + 0.5 >= x + 1)
    //    x++;
    
    y=b;    
    //if(a + 0.5 >= y + 1)
    //    y++;
                
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
           	if(j == ((i*x) + y)){
           	    if((i <= x1 && i >= x2)||(i >= x1 && i <= x2) && (j <= y1 && j >= y2)||(j >= y1 && j <= y2))         
           	        mat[i][j] = '@';
           	}
        }
    }

//	for (i=x1;i<=x2;i++){
//		mat[i][i*x+y] = '@';
//	}	

    //Imprime a matriz
    for (i=0;i<TAM;i++){
            for (j=0;j<TAM;j++){
                printf("%c ",mat[i][j]);
            }
            printf("\n");
    }

    printf("Digite 0 ou 1:\n");
    scanf("%d",&op);
}


    return 0;
}
