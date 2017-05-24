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

#include <stdio.h> //abaixo temos as funcoes para operar as matrizes 

void zerarMatriz(int mat[][200]) { //inicializacao da matriz com todos os elementos iguais a zero
    int i, j;
    for (i=0; i<200; i++) {
        for (j=0; j<200; j++) {
            mat[i][j] = 0;
        }
    }
}

void read(int mat[][200], int lin, int col) { //leitura da matriz
    int i,j;
    for (i=1; i<lin-1; i++) {
        for (j=1; j<col-1; j++) {
            scanf("%d", &mat[i][j]);
            
        }
    }
}

void printMatriz(int mat[][200], int lin, int col) { //print da matriz
    int i,j;
    for (i=1; i<lin-1; i++) {
        for (j=1; j<col-1; j++) {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}

void atualizaMatriz(int mat[][200], int mat_aux[][200], int lin, int col) { //atualizacao da matriz
    int i,j;
    for (i=0; i<lin; i++) {
        for (j=0; j<col; j++) {
            mat[i][j] = mat_aux[i][j];
        }
    }
}


int humans (int mat[]) { //verificao de humanos como vizinhos
    int acu=0;
    for (int k=0; k< 8; k++) {
        if (mat[k] == 1) {
            acu++;
        }
    }
    return acu;
}

int zombies (int mat[]) { //mesma ideia acima, mas para zumbis
    int acu = 0;
    for (int k=0; k<8; k++) {
        if (mat[k] == 2) {
            acu++;
        }
    }
    return acu;
}

int main () {
    int mat_aux[200][200], viz[8]; //matrizes e vetor de vizinhos
    int mat[200][200];
    int lin, col, day, i, j, k; 
    zerarMatriz(mat);
    scanf ("%d %d %d", &lin, &col, &day);
    lin = lin+2;
    col = col+2;
    read(mat, lin, col);
    atualizaMatriz(mat_aux, mat, lin, col);
        
    for(k=0; k<=day; k++) { //iteracao a cada dia
        printf ("iteracao %d\n", k);
        printMatriz(mat, lin, col);
        for (i=1; i<lin-1; i++) {
            for (j=1; j<col-1; j++) {
                viz[0] = mat[i-1][j-1]; //linearizacao da matriz para um vetor para verificacao dos vizinhos 
                viz[1] = mat[i-1][j];
                viz[2] = mat[i-1][j+1];
                viz[3] = mat[i][j-1];
                viz[4] = mat[i][j+1];
                viz[5] = mat[i+1][j-1];
                viz[6] = mat[i+1][j];
                viz[7] = mat[i+1][j+1];
                if (mat[i][j] == 1) { //caso haja humano
                    if (zombies(viz) >= 1) { //mais de um zumbi como vizinho
                        mat_aux[i][j] = 2; //humano se torna zumbi
                    }
                }
                else if (mat[i][j] == 2) { //caso haja zumbi
                    if (humans(viz) >= 2) { //mais de dois humanos como vizinhos
                        mat_aux[i][j] = 0; //zumbi morre
                    }
                    if (humans(viz) == 0) { //sem vizinhos
                        mat_aux[i][j] = 0; //zumbi morre de fome
                    }
                }
                else if (mat[i][j] == 0) { //caso vazio
                   if (humans(viz) == 2) { //mais de dois humanos
                       mat_aux[i][j] = 1; //na proxima iteracao surgira um novo humano
                   }
                }
            }
        }
        atualizaMatriz(mat, mat_aux, lin, col); //atualizacao da matriz para a proxima iteracao, ordem inversa de 'mat' e 'mat_aux' para atualizacao correta
    }
}
