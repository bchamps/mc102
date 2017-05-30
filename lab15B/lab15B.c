/* Lab 15B
 * Nome: Bruno Campos;
 * RA: 195080;
 */

#include <stdio.h>
#include <string.h>



/* Funcao: removePadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo as ocorrencias de um dado padrao.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *       padrao: subsequencia de movimentos, cujas ocorrencias devem ser removidas
 *    targetStr: sequencia obtida apos a remocao de str de todas as ocorrencias do dado padrao.
 *               
 *  
 * Retorno:
 *
 *    1, se as occorrencias do dado padrao foram removidas
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15];
 *
 *     char padrao1[3] = "+-"
 *     char padrao2[3] = "**"
 * 
 *     removePadrao(seq1, padrao1, seq2); // seq2 sera "**-*+++"
 *     removePadrao(seq1, padrao2, seq2); // seq2 sera "+-*+-*-*+++" 
 * 
 */
int removePadrao(char str[], char padrao[], char targetStr[]) {
    int a, i, j=0, flag=0;
    a = strlen(str);
    
    for (i=0; i<a; i++) {
        while (str[i] == padrao[0] && str[i+1] == padrao[1] && i<a) {
            i = i+2;
            flag = 1;
        }
        if (i>=a) {
            break;
        }
        targetStr[j] = str[i];
        j++;
    }
    
    targetStr[j] = '\0';
    
    if (flag) {
        return 1;
    }
    return 0;
}

/* Funcao: removeBloco
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo o bloco inicial delimitado pelo dado caractere.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *            c: caractere delimitador do bloco a ser removido
 *    targetStr: se str comeca com o caractere do parametro c, targetStr contera a sequencia obtida
 *               apos a remocao (de str) do bloco de movimentos da primeira posicao de str ate a 
 *               segunda ocorrencia (inclusive) do caractere do parametro c. Se nao exsitir uma segunda 
 *               ocorrencia do caracter do parametro c, targetStr deve conter a sequencia vazia.
 *
 * Retorno:
 *
 *    1, se o bloco foi removido
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15] = "*+-*+-*-*+++";
 *     char seq3[15] = "*+-+--+++";
 *     char seq4[15];
 * 
 *     removeBloco(seq1, '*', seq4); // seq4 sera "+-*+-*-*+++"
 *     removeBloco(seq2, '*', seq4); // seq4 sera "+-*-*+++"
 *     removeBloco(seq3, '*', seq4); // seq4 sera "" (sequencia vazia)
 * 
 */

int removeBloco(char str[], char c, char targetStr[]) {
    int a, i, j=0;
    a = strlen(str);
    
    if (str[0] == c) {
        i = 1;
        while(i<a && str[i] != c){
            i++;
        }

        if (str[i] == c) {
            for(i=i+1; i<a; i++, j++){
                targetStr[j] = str[i];
            }
            targetStr[j] = '\0';
            return 1;
        }
        else {
            targetStr[j] = '\0';
            return 1;
        }
    }
    return 0;
}

/* Funcao: substituiPadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    substituindo as ocorrencias de um dado padrao por um novo padrao.
 *
 * Parametros:
 *           str: sequencia de movimentos '+', '-', '*'
 *        padrao: subsequencia de movimentos, cujas ocorrencias devem ser substituidas pelo novoPadrao
 *    novoPadrao: subsequencia de movimentos que deve substituir cada ocorrencia do dado padrao
 *     targetStr: sequencia obtida apos a substituicao em str de todas as ocorrencias do dado padrao 
 *                pelo novoPadrao
 *
 *     Voce pode assumir que as subsequencias padrao e novoPadrao tem o mesmo tamanho.
 *
 * Retorno:
 *
 *    1, se as ocorrencias do dado padrao foram substituidas pelo novoPadrao
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+*+-+*+-*++";
 *     char seq2[15];
 *     char seq3[15];
 *
 *     char padrao[5] = "+*+"
 *     char novoPadrao[5] = "*-*"
 * 
 *     substituiPadrao(seq1, padrao, novoPadrao, seq2); // seq2 sera "*-*-*-*-*++"
 *     substituiPadrao(seq2, padrao, novoPadrao, seq3);  // seq3 sera "*-*-*-*-*++" 
 * 
 */

int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]) {
    int a, i, flag=0;
    a = strlen(str);
    
    for (i=0; i<a-2; i++) {
        while (str[i] == padrao[0] && str[i+1] == padrao[1] && str[i+2] == padrao[2]) {
            targetStr[i] = novoPadrao[0];
            targetStr[i+1] = novoPadrao[1];
            targetStr[i+2] = novoPadrao[2];
            
            i = i+3;
            flag=1;
        }
        targetStr[i] = str[i];
    }
    
    if (i != a) {
        targetStr[i] = str[i];
        targetStr[i+1] = str[i+1];
        targetStr[i+2] = '\0';
    }
    
    if (!flag)
        return 0;
    return 1;
}
