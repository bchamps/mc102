/* Lab16
 * Nome: Bruno Campos
 * RA: 195080;
 * Objetivos: 
 */

#include <stdio.h>
#include <stlib.h>

/*Considerar:
 * tamanho maximo indeterminado;
 * Utilizar malloc e/ou calloc;
 * Funcoes Lab13;
 * Como o tamanho máximo dos conjuntos são indeterminados, usaremos alocação dinâmica para alterar o tamanho dos conjuntos em tempo de execução. 
 * Os conjuntos serão representados por um vetor e dois inteiros: tamanho e capacidade.
 * O tamanho(size) indica a quantidade de elementos que o conjunto contém e capacidade(cap) indica o tamanho do vetor alocado para o conjunto. 
 * Desta forma o conjunto consegue armazenar até cap elementos. Se o vetor ficar cheio e novos elementos precisarem ser inseridos no conjunto temos que realocá-lo para um vetor maior. 
 * De forma similar se muitos elementos forem removidos de um conjunto, o vetor alocado deverá ser diminuído para ocupar menos espaço em memória.
 * Funcoes -> Ordena(ok), Pertence(ok), Contem(ok), Inicializa(fazer), Adicao(ok), Subtracao(ok), Uniao(ok), Intersecao(ok), Diferenca(ok) [ALTERAR TODAS]
 * Apos adicao -> Ordenar
 * FREE
 */

void ordena(int *conj, int tam,) {
	int i, j, aux;
    for (i=tam-1; i > 0; i--) {
    	for (j=0; j < i; j++) {
        	if (tam[j] > tam[j + 1]) {
            	aux = conj[j];
            	conj[j] = conj[j + 1];
            	conj[j + 1] = aux;
            }
        }
    }
} 

int pertence(int *conj, int tam, int elemento) {
	int i;
    for (i = 0; i < tam; i++) {
        if (conj[i] == elemento) {
        	return 1;
        }
    }
	return 0;
}

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {
	int i;
    for (i = 0; i < tam_A; i++) {
        if (pertence(conj_B, tam_B, conj_A[i]) == 0) {
        	return 0;
        }
    }
    return 1;
}

int *init(int *tam, int *cap) {
	int *v1;
	v1 = malloc(2*sizeof(int));
	*tam = 0;
	*cap = 2;
	return v1;
}

int *adicao(int *conj, int *tam, int *cap, int elemento) {
    
	if (conj == NULL) {
		conj = init(tam, cap);
	}
	
	if (pertence(conj, *tam, elemento) == 1) {
        	return conj;
  	}
  	
	else {
        if (*tam == *cap) {
            conj = realloc (conj, *cap*2*sizeof(int));
            *cap = *cap*2;
        }
        conj[*tam] = elemento;
        *tam = *tam+1;
	}
	return conj;
}

int *subtracao(int *conj, int *tam, int *cap, int elemento) {
	int i, pos;  
    
    if (pertence(conj, *tam, elemento) == 1) {
        for (i=0; i < tam; i++) {
            if (conj[i] == elemento) {
               pos = i; 
            }
        }

        for (i=pos; i <tam-1; i++) {
            conj[i] = conj[i+1];
        }
        *tam = *tam-1;
        return conj;
    }
	else {
        return conj;
    } 
}

int *uniao(int *conj_A, int *conj_B, int *conj_C int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int i, j, k=0;
    
    for (i=0; i<tam_A; i++) {
    	adicao//continuar.. 1 adicao em cada 'for' e jogar todo mundo no conj_C
    }
    
    for (j = 0; j < tam_B; j++) {
        if (!pertence(destRes, tam1+k, conj2[j])) {
            destRes[tam1+k] = conj2[j];
            k++;
        }
    }
    //printf("t:%d" tam1+k);
    return tam1+k;
	//return 0;
}

int *intersecao(int *conj_A, int conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int i, j, k=0;
    for (i = 0; i < tam_A; i++) {
        for (j = 0; j < tam_B; j++) {
            if (conj_A[i] == conj_B[j]) {
                [k] = conj1[i];
                k++;
            }
        }
    }
    return k;
}

int *diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
    int i, j, k=0, tam3;
    char aux[26];
    //Implementar a funcao e trocar o valor de retorno
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
