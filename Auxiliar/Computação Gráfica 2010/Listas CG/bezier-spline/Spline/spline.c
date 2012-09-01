/*
 * Spline - Computacao grafica
 * 
 * Curso de Ciencia da Computacao
 * 
 * Aluna: Beatriz Yoko Matsushita
 *
 * RA: 317098
 *
 */

#include <stdio.h>
#include <math.h>

#define N_PONTOS 5

struct ponto {
	
	float x;
	float y;
	float z;
	
};

struct ponto soma(struct ponto p1, struct ponto p2) {
	
	struct ponto r;
	
	r.x = p1.x + p2.x;
	r.y = p1.y + p2.y;
	r.z = p1.z + p2.z;
	
	return r;
}

struct ponto multiplica(struct ponto p, float j) {
	
	struct ponto r;
	
	r.x = j * p.x;
	r.y = j * p.y;
	r.z = j * p.z;
	
	return r;
}

float N(int i, int k, float t, float *T) {
	
	float a, b, c, d, sup, inf;
	
	if(k = 1)	
		
		if((T[i] <= t) && (T[i+1] >= t))
			return 1;
		
		else
			return 0;
	
	else {
        
        sup = 1 - T[i];
        inf = T[i+k-1] - T[i];
        
        if(sup == 0 && inf == 0)
            a = 0;
        
        else
		    a = sup / inf;
		
        b = N(i, k-1, t, T);
		
		sup = T[i+k] - t;
		inf = T[i+k] - T[i+1];
		
		if(sup == 0 && inf == 0)
			c = 0;
		
		else
			c = sup / inf;
		
		d = N(i+1, k-1, t, T);
		
		return (a * b + c * d);
    }
}

// Spline
struct ponto P(int n, int k, float t, struct ponto *b, float *T) {
	
	int i;
	struct ponto p;
	
	p.x = 0;
	p.y = 0;
	p.z = 0;
	
	for(i=0; i<=n; i++)
		p = soma(p, multiplica(b[i], N(i, k, t, T)));
	
	return p;
}



struct ponto ler(int i) {
	
	struct ponto p;
	
	printf("\nB%d:\n\n", i+1);
	printf("x: ");
	scanf("%f", &p.x);
	printf("y: ");
	scanf("%f", &p.y);
	printf("z: ");
	scanf("%f", &p.z);
	
	return p;
}

int main() {
	
	// Bi
	struct ponto b[N_PONTOS];
	// ti são números discretizados de um intervalo
	float T[N_PONTOS];
	float t;
	int k;
	int i;
	struct ponto p;
	
	// leitura de k
	printf("\nInforme o grau k: ");
	scanf("%d", &k);
	
	// leitura de t
	printf("\nInforme o t: ");
	scanf("%f", &t);
	
	// leitura de ti
    i = 0;
    printf("\nt%d: ", i+1);
	scanf("%f", &T[i]);
	i++;
	while(i < (N_PONTOS + k)) {
        printf("\nt%d: ", i+1);
		scanf("%f", &T[i]);
		while(T[i] < T[i-1]) {
 			printf("t%d deve ser maior ou igual a t%d", i+1, i);
            printf("\nt%d: ", i+1);
    		scanf("%f", &T[i]);
        }
        i++;
    }
	
	// leitura de Bi
	for(i=0; i<N_PONTOS; i++)
		b[i] = ler(i);
		
	p = P(N_PONTOS, k, t, b, T);
	
	printf("\n<<Spline>>\n\nP(t) = (%.0f, %.0f, %.0f)\n", p.x, p.y, p.z);
	
	return 0;
}
