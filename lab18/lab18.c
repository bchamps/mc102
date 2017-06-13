/* Lab18
 * Nome: Bruno Campos
 * RA: 195080
 */

/* Considerar:
 * Escala de Cinza
 * Esticar Constraste
 * Normalizar
 * Tudo com matrizes e arqs
 * Imax fixo 255
 * Intensidade de cores 0-255
 * A imagem original terá intensidade máxima igual a 255
 * Tamanho n x m, onde n,m <= 128
 * Para calcular o piso utilize a função floor da biblioteca math.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int  **allocMatriz(int largura, int altura); 
void readMatriz (int **matriz, int largura, int altura, FILE *arq); 
void cinza(int **matriz, int largura, int altura);
void printMatriz(int **matriz, int largura, int altura, FILE *arqout); 
void deallocMatriz(int **matriz, int largura, int altura);
int max(int **matriz, int largura, int altura, int ini);
int min(int **matriz, int largura, int altura, int ini);
void esticar(int **matriz, int largura, int altura);

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Argumentos invalidos. Use:\n");
    	fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
    	fprintf(stderr, "Usado:");
    	for (int i=0; i<argc; i++) {
			fprintf(stderr, " %s", argv[i]);
    	}
    	fprintf(stderr, "\n");
    	return 1;
  	}

	char efeito[20];
	char *arqEntrada = argv[1];
  	char *arqSaida = argv[2];

	scanf("%s", efeito);
	
	int altura, largura;
	int **matriz;
	FILE *arqin, *arqout;
	arqin = fopen(arqEntrada, "r");
	arqout = fopen(arqSaida, "w");

	fscanf(arqin, "P3 %d %d 255", &largura, &altura);
	
	matriz = allocMatriz(largura, altura);
	readMatriz(matriz, largura, altura, arqin);
	if(strcmp(efeito, "cinza") == 0)
		cinza(matriz, largura, altura);
	
	if(strcmp(efeito, "esticar") == 0)
		esticar(matriz, largura, altura);

	printMatriz(matriz, largura, altura, arqout);
	fclose(arqin);
	
/* Escala Cinza:
 * novaR[X][Y] = ⌊(imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y]) / 3⌋
 * novaG[X][Y] = novaR[X][Y]
 * novaB[X][Y] = novaR[X][Y]
 */

/* Normalizar: 
 * novaR[X][Y] = ⌊imagemR[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 * novaG[X][Y] = ⌊imagemG[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 * novaB[X][Y] = ⌊imagemB[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 */

/* Esticar
 * novaR[X][Y] = ⌊((imagemR[X][Y] - Rmin) * 255)/(Rmax - Rmin)⌋
 * novaG[X][Y] = ⌊((imagemG[X][Y] - Gmin) * 255)/(Gmax - Gmin)⌋
 * novaB[X][Y] = ⌊((imagemB[X][Y] - Bmin) * 255)/(Bmax - Bmin)⌋
 */


  return 0;
}
int  **allocMatriz(int largura, int altura) {
	int i;
	int **matriz = malloc(altura*sizeof(int*));

	for(i=0; i<altura; i++) {
		matriz[i] = malloc(3*largura*sizeof(int));
	}
	return matriz; 
}

void readMatriz(int **matriz, int largura, int altura, FILE *arq) {
	int i, j;
	for(i=0;i<altura;i++) {
		for(j=0;j<3*largura; j++){
			fscanf (arq,"%d", &matriz[i][j]);
		}
	}
		
}
 
void cinza(int **matriz, int largura, int altura) {
	int i, j, r, g, b;
	for(i=0, r=0,g=1,b=2; i<altura; r+=3, g+=3, b+=3) {
		if(r>=3*largura) {
			r=0, g=1, b=2;
			i++;
		}
		if(i==altura){
			break;
		}	
		matriz[i][r] = floor((matriz[i][r] + matriz[i][g] + matriz[i][b])/3);
		matriz[i][g] = matriz[i][r];
		matriz[i][b] = matriz[i][r];
	}
}

void printMatriz(int **matriz, int largura, int altura, FILE *arqout) {
	fprintf(arqout, "P3\n%d %d\n255\n", largura, altura);
	for(int i=0; i<altura; i++) {
		for(int j=0; j<3*largura; j++) {
			fprintf(arqout, "%d ", matriz[i][j]);
		}
		fprintf(arqout, "\n");
	}
	fclose(arqout);	
}

void deallocMatriz(int **matriz, int largura, int altura) {
	int i;

	for(i=0; i<altura; i++) {
		free(matriz[i]);
	}
	
	free(matriz);
}

int max(int **matriz, int largura, int altura, int ini) {
	int valmax=0, i, j;

	for(i=0; i<altura; i++) {
		for(j=ini; j<3*largura; j+=3) {
			if(matriz[i][j] > valmax)
				valmax = matriz[i][j];
		}
	}

	return valmax;
}

int min(int **matriz, int largura, int altura, int ini) {
	int valmin=255, i, j;

	for(i=0; i<altura; i++) {
		for(j=ini; j<3*largura; j+=3) {
			if(matriz[i][j] < valmin)
				valmin = matriz[i][j];
		}
	}

	return valmin;
}

void esticar(int **matriz, int largura, int altura) {
	int i, j, r, g, b, rmin, rmax, gmin, gmax, bmin, bmax;

	rmin = min(matriz, largura, altura, 0);
	rmax = max(matriz, largura, altura, 0);

	gmin = min(matriz, largura, altura, 1);
	gmax = max(matriz, largura, altura, 1);
	
	bmin = min(matriz, largura, altura, 2);
	bmax = max(matriz, largura, altura, 2);

	for(i=0, r=0,g=1,b=2; i<altura; r+=3, g+=3, b+=3) {
		if(r>=3*largura) {
			r=0, g=1, b=2;
			i++;
		}
		if(i==altura){
			break;
		}
		if(rmin != rmax)
		matriz[i][r] = floor((matriz[i][r] - rmin)*255/(rmax - rmin));

		if(gmin != gmax)
		matriz[i][g] = floor((matriz[i][g] - gmin)*255/(gmax - gmin));

		if(bmin != bmax)
		matriz[i][b] = floor((matriz[i][b] - bmin)*255/(bmax - bmin));
	}	
}

int normalizar(){

}
