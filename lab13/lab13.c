/*Nome: Bruno Campos; RA: 195080
 * O objetivo deste programa eh trabalhar com conjuntos e suas operacoes: pertence, contem, uniao, etc..
 * Para isso iremos receber um vetor contendo determinado conjunto e entao verificar qual das operacoes realizar
 */

#include <stdio.h>

/* Funcao: pertence
 *
 * Parametros:
 *   conj: vetor contendo o conjunto de entrada
 *    tam: tamanho do conjunto
 *  letra: elemento a ser verificado pertinencia
 *
 * Retorno:
 *   1 se letra pertence a conj e 0 caso contrario
 */
int pertence(char conj[], int tam, char letra){
    /* Implementar a funcao e trocar o valor de retorno */
    int i;
    for (i = 0; i < tam; i++) {
        if (conj[i] == letra) {
        return 1;
        }
    }
  return 0;
}

/* Funcao: contido
 *
 * Parametros:
 *   conj1: vetor contendo um conjunto de entrada
 *   conj2: vetor contendo um conjunto de entrada
 *    tam1: tamanho do conjunto conj1
 *    tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   1 se conj1 esta contido em conj2 e 0 caso contrario
 */
int contido(char conj1[], char conj2[], int tam1, int tam2){
    /* Implementar a funcao e trocar o valor de retorno */
    int i;
    for (i = 0; i < tam1; i++) {
        if (pertence(conj2, tam2, conj1[i]) == 0) {
        return 0;
        }
    }
    return 1;
}

/* Funcoes: adicao e subtracao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto que tera incluso ou removido o elemento
 *    tam: tamanho do conjunto
 *  letra: elemento a ser adicionado ou removido
 *
 * Retorno:
 *   tamanho do conjunto apos a operacao.
 */
int adicao(char conj[], int tam, char letra){
  /* Implementar a funcao e trocar o valor de retorno */
  if (pertence(conj, tam, letra) == 1) {
        return tam;
  }else {
      conj[tam] = letra;
      return tam + 1;
  }
  //return 0;
}

int subtracao(char conj[], int tam, char letra){
    int i, pos;  
        /* Implementar a funcao e trocar o valor de retorno */
    if (pertence(conj, tam, letra) == 1) {
        for (i = 0; i < tam; i++) {
            if (conj[i] == letra) {
                pos = i;
            }
        }
        //printf("estou aqui: %d\n", pos);
        for (i = pos; i < tam-1; i++) {
            conj[i] = conj[i+1];
        }
        //conj[pos]=conj[tam-1];
        return tam - 1;
    }else {
        return tam;
    } //return 0;
}

/* Funcoes: uniao, intersecao e diferenca
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *     conj1: vetor contendo o conjunto de entrada do primeiro operando
 *     conj2: vetor contendo o conjunto de entrada do segundo operando
 *      tam1: tamanho do conjunto conj1
 *      tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int uniao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int i, j, k=0;
    /* Implementar a funcao e trocar o valor de retorno */
    for (i = 0; i < tam1; i++) {
        destRes[i] = conj1[i];
    }
    for (j = 0; j < tam2; j++) {
        if (!pertence(destRes, tam1+k, conj2[j])) {
            destRes[tam1+k] = conj2[j];
            k++;
        }
    }
    //printf("t:%d" tam1+k);
    return tam1+k;
  //return 0;
}

int intersecao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int i, j, k=0;
    /* Implementar a funcao e trocar o valor de retorno */
    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            if (conj1[i] == conj2[j]) {
                destRes[k] = conj1[i];
                k++;
            }
        }
    }
    return k;
}

int diferenca(char destRes[], char conj1[], char conj2[], int tam1, int tam2){
    int i, j, k=0, tam3;
    char aux[26];
    /* Implementar a funcao e trocar o valor de retorno */
    //k = uniao(destRes, conj1, conj2, tam1, tam2);
    //tam3 = intersecao(aux, conj1, conj2, tam1, tam2);
    
    for (i = 0; i < tam1; i++) {
        if(!pertence(conj2, tam2, conj1[i])) {
            //k = subtracao(destRes, k, aux[i]);
            k = adicao(destRes, k, conj1[i]);
            //printf("letra: %c\n", conj1[i]);
        }
    }
    return k;
}


/* Funcao: complemento
 * Guarda em conjRes o resultado da operação U-conj, onde U é o conjunto 
  int i = 0;
 * de todas as letras minusculas do alfabeto ingles
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *      conj: vetor contendo o conjunto de entrada do primeiro operando
 *       tam: tamanho do conjunto conj
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int complemento(char conjRes[], char conj[], int tam){
  /* Implementar a funcao e trocar o valor de retorno */
    int i, k;  
    char U[26];
    for (i =0; i < 26; i++) {
        U[i]= 'a'+i;
    }
    k = diferenca(conjRes, U, conj, 26, tam);
    return k;
}
