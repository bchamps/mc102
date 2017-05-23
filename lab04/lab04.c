#include <stdio.h>/*O objetivo deste programa eh testar as possibilidades de agrupamento de caixas em que seus pesos sejam balanceados. Portanto, testamos as somas como visto no exemplo dado no enunciado. Caso as possibilidades sejam verdadeiras, printamos 'sim' na tela, caso contrario, sera printado 'nao'.
Nome: Bruno Campos; RA: 195080*/

int main () {
	int c1, c2, c3, c4;
	scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
	
	if (c1 + c2 == c3 + c4) { /*Nas tres primeiras somas testamos caixas agrupadas duas a duas*/
	printf ("sim\n");
	}
	else if (c1 + c3 == c2 + c4) {
	printf ("sim\n");
	}
	else if (c1 + c4 == c2 + c3) {
	printf ("sim\n");
	}
	else if (c1 == c2 + c3 + c4) { /*Apos os testes dois a dois, testamos uma caixa comparada a soma das outras 3, como visto no exemplo do enunciado*/
	printf ("sim\n");
	}
	else if (c2 == c1 + c3 + c4) {
	printf ("sim\n");
	}
	else if (c3 == c1 + c2 + c4) {
	printf ("sim\n");
	}
	else if (c4 == c1 + c2 + c3) {
	printf ("sim\n");
	}
	else { /*Caso as possibilidades sejam invalidas, printaremos 'nao'*/
	printf ("nao\n");
	}

	return 0;

}
