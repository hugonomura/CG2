/*
 * Bezier - Computacao grafica
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

#define N_PONTOS 3

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

float fatorial(int x) {

	int i;
	float f = 1;

	for(i=x; i>1; i--)
		f = f * i;

    printf("\nfatorial %d = %f\n", x, f);

	return f;
}

float binomial(int n, int i) {

	float b, sup, inf;

    sup = fatorial(n); 
    inf = fatorial(i) * fatorial(n-i);
    b = sup / inf;

    printf("\nbinomial %d = %f\n", i, b);

	return b;
}

float J(int n, int i, float t) {

	float j, aux1, aux2;

    aux1 = pow(t, i);
    printf("\n%f^%d = %f", t, i, aux1);
    aux2 = pow(1-t, n-1);
    printf("\n%f^%d = %f", 1-t, n-1, aux2);
	j = binomial(n, i) * aux1 * aux2;

    printf("\nJ %d = %f\n", i, j);

	return j;
}

// Bezier
struct ponto P(int n, float t, struct ponto *b) {

	int i;
	struct ponto p;
	struct ponto aux[n];

    p.x = 0;
	p.y = 0;
	p.z = 0;
	
	

	for (i=0; i<=n; i++) {
        p = soma(p, multiplica(b[i], J(n, i, t)));
        printf("\nSoma %d\n\nP(t) = (%f, %f, %f)\n", i, p.x, p.y, p.z);
    }

	return p;
}

struct ponto ler(int i) {

	struct ponto p;

	printf("\nPonto %d:\n\n", i+1);
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

	float t;
	struct ponto p;
	int i;

	for(i=0; i<N_PONTOS; i++)
		b[i] = ler(i);

	t = 1.0/N_PONTOS;

	p = P(N_PONTOS, t, b);

	printf("\n<<Bezier>>\n\nP(t) = (%f, %f, %f)\n", p.x, p.y, p.z);

    getchar();
	return 0;
}
