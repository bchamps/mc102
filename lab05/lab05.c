#include <stdio.h> /*O objetivo deste programa eh computar valores positivos e negativos, soma-los e verificar se a condicao proposta sera valida, onde sera dado um tempo para que a soma dos valores impostos seja feita e comparada ao combustivel necessario. 
Nome: Bruno Campos;RA: 195080*/

int main () {

	int t, c, f, i, a;

	scanf ("%d %d", &t, &c);	
	
	for (i = 0; i < t; i++) {
		if (a >= c) { //condicao de quebra caso o valor necessario seja antingido antecipadamente
		break;
		}	
	scanf ("%d", &f);
	a = a + f;// variavel 'a' como acumuladora do fluxo 
	}
	
	if (a >= c) {
	printf ("sim\n%d\n", i);
	}
	else {
	printf ("nao\n%d\n", t+1);	
	}
}
