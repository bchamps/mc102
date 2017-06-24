/* Nome: Bruno Campos
 * RA: 195080
 * Objetivos: Obter um programa que verifica um mapa de determinada proporcao
 * 				a partir disso verificar as posicoes onde se encontram as bases
 * 					do imperio e da alianca. Quando encontradas, destrui-las. 
 */

#include <stdio.h>
#include <stdlib.h>

/* Considerar:
 * 		'*' = imperio
 * 		'#' = rebeldes
 * 		'-' = nada
 * 		bases iguais nao podem estar encostadas
 */

void destruir(char **map, char id, int lin, int col, int lins, int cols);

int main() {

	int lins, cols;
	int rebels = 0;
	int empire = 0;
	char **map;

	scanf("%d %d ", &lins, &cols); //determinacao das proporcoes do mapa

	map = malloc(lins*sizeof(char*)); //alocacao das linhas

	for(int k = 0; k<lins; k++){ //para as colunas utilizamos um for 
		map[k] = malloc(cols*sizeof(char)); //para cada linha alocarmos todas as colunas
	}

	for (int i=0; i<lins; i++) { //laco para verificar todo o mapa
		for(int j=0; j< cols; j++) {
			scanf("%c ", &map[i][j]);
		}
	}
	
	for(int i=0; i<lins; i++) { //laco para verificar presenca de base do imperio
		for(int j=0; j<cols; j++) {
			if(map[i][j] == '*') { //caso encontrada, destruimos
				empire++; //acrescemos uma base de imperio para a saida
				destruir(map, '*', i, j, lins, cols);
			}
			if(map[i][j] == '#') {
				rebels++; //mesmo para bases rebeldes
				destruir(map, '#', i, j, lins, cols);
			}
		}
	}

	printf("Bases rebeldes: %d\n", rebels); //print das bases encontradas e destruidas
	printf("Bases do imperio: %d\n", empire); 

}

void destruir(char **map, char id, int lin, int col, int lins, int cols) { //funcao destruir

	if (lin < 0 || lin >= lins) { //casos de parada 
		return;
	}
	if (col < 0 || col >= cols) { //.. 
		return;
	}
	if (map[lin][col] == id) { //caso encontremos um char de alguma base 
		map[lin][col] = '-'; //destruimos e mudamos seu char 
		
	destruir(map, id, lin+1, col, lins, cols); //verificacao de todas as posicoes dos vizinhos no mapa
	destruir(map, id, lin+1, col+1, lins, cols);
	destruir(map, id, lin+1, col-1, lins, cols);
	destruir(map, id, lin-1, col, lins, cols);
	destruir(map, id, lin-1, col+1, lins, cols);
	destruir(map, id, lin-1, col-1, lins, cols);
	destruir(map, id, lin, col+1, lins, cols);
	destruir(map, id, lin, col-1, lins, cols);
	}
}

