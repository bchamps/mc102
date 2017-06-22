/* Nome: Bruno Campos
 * RA: 195080
 * Objetivos: Obter um programa que nos de anagramas,
 * 			  utilizaremos recursao para obter todas as possibilidades
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Entrada: 
 *          string_ordenada: a string original, que devemos processar 
 *                           para encontrarmos todos os anagramas
 *          letra_usada: um vetor de booleanos (implementado da forma 
 *                       de um vetor de inteiros) para marcarmos quais 
 *                       posições da string original já foram usadas
 *          word: o anagrama que estamos formando
 *          n: o numero de letras do anagrama
 *          k: a posição onde incluiremos a proxima letra em word
 * 
 * A ideia para gerar sem repeticoes eh que setada a letra da posicao k,
 * e retornado da chamada recursiva, temos
 * que colocar uma letra diferente na posição k, pois senão geraríamos
 * as repetições. Quando n==k incluimos a letra faltante e imprimimos o
 * anagrama.
 */
void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k) {
	if (k == n) {
		word[n] = '\0';
		printf("%s\n", word); //caso final de impressao do anagrama
		return;
	}
	
	int i=0;
	 while(i < n) {
		if (letra_usada[i] == 0) { 
			word[k] = string_ordenada[i];
			letra_usada[i] = 1;
			generate(string_ordenada, letra_usada, word, n, k+1); //recursao ate caso base
			letra_usada[i] = 0;
			while(string_ordenada[i] == string_ordenada[i+1]) //caso para letras iguais
				i++;
		}
		i++;
	}
	return;
}
