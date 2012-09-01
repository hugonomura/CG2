/*Exercicios 5,6,7 lista 1 */

/*Desenha 1/4 de uma circunferencia pelo metodo nao incremental*/
void desenharCircNIncr(){
     float raio,a,b;
     int i,j,numP;

     printf("\nInforme o raio: ");
     scanf("%f", &raio);
     printf("\nInforme o numero de pontos: ");
     scanf("%d", &numP);
     float matPontos[numP][2];     
     matPontos[0][0] = 0.0;
     matPontos[0][1] = raio;
     printf("\nInforme os pontos (informe o valor de x tecle enter depois o valor de y): ");
     for(i = 1; i < numP; i++){
           printf("\nPonto %d: ", i);
           for(j = 0; j < 2; j++){
                 scanf("%f",&matPontos[i][j]); 
           }
     }
     //calcula os coeficientes da equacao da reta entre cada 2 pontos, e desenha a reta
     j = 0;
     for(i = 0; i < numP - 2; i++){
                 a = (matPontos[i][j+1] - matPontos[i+1][j+1])/(matPontos[i][j] - matPontos[i+1][j]);
                 b = matPontos[i][j+1] - ((a)*(matPontos[i][j]));
                 desenharReta(matPontos[i][j],matPontos[i+1][j],matPontos[i][j+1],matPontos[i+1][j+1],a,b);
           }
           
           
}

/*Desenha 1/4 de uma circunferencia pelo metodo incremental
A medida que o valor de X se aproxima de R percebesse que ocorrem falhas no desenho*/
void desenharCircIncr(){
     float raio, ponto, pontoAnt, a, b;
     int x = 0;
     
     printf("\nInforme o raio: ");
     scanf("%f", &raio);
     
     ponto = sqrt(pow(raio,2) - pow(x,2));
     pontoAnt = ponto;
     while(ponto > 0){
                x++;
                ponto = sqrt(pow(raio,2) - pow(x,2));
                a = (ponto - pontoAnt);
                b = ponto - a * x; 
                desenharReta(x - 1,pontoAnt,x, ponto,a,b);
                pontoAnt = ponto;
     } 
     
}
/*Desenha 1/4 de uma circunferencia por coordenadas polares*/
void desenharCircCoordPol(){
     float raio, pontoX, pontoY, teta = 0, temp, pontoXAnt, pontoYAnt;

     printf("\nInforme o raio: ");
     scanf("%f", &raio);
     temp = PI*teta/180;
     pontoX = raio*(cos(temp)*180/PI);           
     pontoY = raio*(sin(temp)*180/PI);
     pontoXAnt = pontoX;
     pontoYAnt = pontoY;
     while(teta <= 90){
                teta++;
                temp = PI*teta/180;
                pontoX = raio*(cos(temp)*180/PI);
                pontoY = raio*(sin(temp)*180/PI);
                a = (pontoY - pontoYAnt)/(pontoX - pontoXAnt);
                b = pontoY - a * pontoX; 
                desenharReta(x - 1,pontoAnt,x, ponto,a,b);
                pontoXAnt = pontoX;
                pontoYAnt = pontoY;

     }
}