#include <stdio.h> /*O objetivo deste programa eh obter as possibilidades de abastecimento de tres postos.
Nome: Bruno Campos; RA: 195080*/

int main () {

	float d, h, a, b, c, gas;
	scanf ("%f %f %f %f %f", &d, &h, &a, &b, &c);
	gas = (3.14*(d/2)*(d/2)*h)*1000; /*Apos declarar as variaveis e obter seus valores, montamos uma formula do volume de gasolina para representar o volume restante ou total no cilindro*/
	if (gas >= a) {
	gas = gas-a;/*Caso um posto seja reabastecido um novo volume sera gerado e assim por diante nos outros postos*/	
	printf ("posto A foi reabastecido\n");
	}
	else {
	printf ("posto A nao foi reabastecido\n");
	}
	if (gas >= b) {
	gas = gas-b;	
	printf ("posto B foi reabastecido\n");
	}
	else { 
	printf ("posto B nao foi reabastecido\n");
	}
	if (gas >= c) {	
	printf ("posto C foi reabastecido\n");
	}
	else {
	printf ("posto C nao foi reabastecido\n");/*Ao final, temos todas as possibilidades, caso os postos sejam ou nao reabastecidos e assim obedecendo as necessidades propostas no objetivo*/
	}

	return 0;
}
