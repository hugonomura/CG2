
/* i e j são as coordenadas de um ponto interior ao retangulo*/
void preenche(int mat[50][50], int i, int j,int cor){
	/* os pixels analisados ficam com valor -1, que significa "em visita"*/
     if (mat[i][j]==-1)
        return;    
     /*baixo */
     if (mat[i+1][j]== mat[i][j]){
         mat[i][j]=-1;                             
         preenche(mat,i+1, j, cor);
     }
     /*esquerda*/
     if (mat[i][j-1]== mat[i][j]){
         mat[i][j]=-1;                       
         preenche(mat,i, j-1, cor);
     } 
     /*cima*/
     if (mat[i-1][j]== mat[i][j]){
         mat[i][j]=-1;                       
         preenche(mat,i-1, j, cor);
     }
     /*direita*/
     if (mat[i][j+1]== mat[i][j]){
         mat[i][j]=-1;                       
         preenche(mat,i, j+1, cor);
     }
     mat[i][j]=cor;
}

