/* Lab 15A
 * Nome: Bruno Campos;
 * RA: 195080
 * Objetivos: Operacoes com matrizes/the walking dead
 */

/*Considerar:
 * Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
 * Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
 * Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
 * Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis ou vazio, então um humano
 * nasce em X no dia seguinte;
 * Se nenhuma das alternativas anteriores for verdade, então X permanece como está.
 * 0 == empty;
 * 1 == human;
 * 2 == zombie.
 * Um indivíduo X que esteja numa posição (i,j) desta matriz, tem como vizinhos àqueles nas posições (i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1) que correspondem respectivamente aos vizinhos v1, v2, v3, v4, v5, v6, v7, e v8 da figura.
*/

#include <stdio.h>

void zerarMatriz(int mat[][200]) {
    int i, j;
    for (i=0; i<200; i++) {
        for (j=0; j<200; j++) {
            mat[i][j] = 0;
        }
    }
}

void read(int mat[][200], int lin, int col) {
    int i,j;
    for (i=1; i<lin-1; i++) {
        for (j=1; j<col-1; j++) {
            scanf("%d", &mat[i][j]);
            
        }
    }
}

void printMatriz(int mat[][200], int lin, int col) {
    int i,j;
    for (i=1; i<lin-1; i++) {
        for (j=1; j<col-1; j++) {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}

void atualizaMatriz(int mat[][200], int mat_aux[][200], int lin, int col) {
    int i,j;
    for (i=0; i<lin; i++) {
        for (j=0; j<col; j++) {
            mat[i][j] = mat_aux[i][j];
        }
    }
}

int main () {
    int mat[200][200];
    int mat_aux[200][200]; // quantidade de vizinhos humanos
    int lin, col, day, i, j, k;
    zerarMatriz(mat);
    scanf ("%d %d %d", &lin, &col, &day);
    lin = lin+2;
    col = col+2;
    read(mat, lin, col);
    printf ("iteracao 0\n");
    printMatriz(mat, lin, col);
        
    for(k=1; k<=day; k++) {
        for (i=1; i<lin-1; i++) {
            for (j=1; j<col-1; j++) {
                //if 
                
                if (mat[i][j] == 0) {
                    // Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis ou vazio, então um humano           
                }
                
                // humanos = 0
            }
        }
        atualizaMatriz(mat, mat_aux, lin, col);        
    }
}
