/* Lab16
 * Nome: Bruno Campos
 * RA: 195080;
 * Objetivos: Os objetivos deste programa sao criar funcoes com ponteiros para operacoes com conjuntos. 
 */

#include <stdio.h>
#include <stdlib.h>

/*Considerar:
 * tamanho maximo indeterminado;
 * Utilizar malloc, calloc ou realloc;
 * Lembrar funcoes Lab13;
 * Como o tamanho máximo dos conjuntos são indeterminados, usaremos alocação dinâmica para alterar o tamanho dos conjuntos em tempo de execução. 
 * Os conjuntos serão representados por um vetor e dois inteiros: tamanho e capacidade.
 * O tamanho(size) indica a quantidade de elementos que o conjunto contém e capacidade(cap) indica o tamanho do vetor alocado para o conjunto. 
 * Desta forma o conjunto consegue armazenar até cap elementos. Se o vetor ficar cheio e novos elementos precisarem ser inseridos no conjunto temos que realocá-lo para um vetor maior. 
 * De forma similar se muitos elementos forem removidos de um conjunto, 
 * o vetor alocado deverá ser diminuído para ocupar menos espaço em memória
 * Funcoes -> Ordena(ok), Pertence(ok), Contem(ok), Init(ok), Adicao(ok)
 * Subtracao(ok), Uniao(ok), Intersecao(ok), Diferenca(ok)
 * free ou realloc;
 */

void ordena(int *conj, int tam) { //funcao que recebe o vetor conj
	int i, j, aux;		  		 // e o ordena de maneira crescente
    for (i=tam-1; i > 0; i--) {
    	for (j=0; j < i; j++) {
        	if (conj[j] > conj[j + 1]) {
            	aux = conj[j];
            	conj[j] = conj[j + 1];
            	conj[j + 1] = aux;
            }
        }
    }
} 

int pertence(int *conj, int tam, int elemento) { //funcao pertence para verificar
	int i;					 					//elementos presentes no conj
    for (i = 0; i < tam; i++) {
        if (conj[i] == elemento) {
        	return 1; //caso pertenca
        }
    }
	return 0; //caso nao pertenca
}

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) { 
	int i; 
    for (i = 0; i < tam_A; i++) {
        if (pertence(conj_B, tam_B, conj_A[i]) == 0) {
        	return 0; // se A nao estiver contido em B
        }
    }
    return 1; // se A estiver contido em B 
}

int *init(int *tam, int *cap) { //inicializacao do vetor
	int *v1;
	v1 = malloc(2*sizeof(int)); //malloc ira dimensiona-lo
	*tam = 0;				   //uma vez que nao possuimos max_size
	*cap = 2;
	return v1; //ponteiro para o conjunto
}

int *adicao(int *conj, int *tam, int *cap, int elemento) {
    
	if (conj == NULL) {         //caso o vetor seja nulo
		conj = init(tam, cap); //iremos inicializa-lo
	}
	
	if (pertence(conj, *tam, elemento) == 1) { //se o elemento ja estiver no conj 
		return conj; //nao iremos acrescenta-lo
  	}
  	
	else {
        if (*tam == *cap) { //elemento nao presente, mas nao ha espaco
            conj = realloc(conj, *cap*2*sizeof(int)); //realocamos o conj
            *cap = *cap*2; //atualizando sua cap para o dobro da anterior
        }
        conj[*tam] = elemento; //acrescimo do novo elemento ao conjunto
        *tam = *tam+1; //atualizamos tambem o tamanho do vetor
	}
	return conj; //ponteiro para o conjunto
}

int *subtracao(int *conj, int *tam, int *cap, int elemento) {
	int i, pos;  
    
    if (pertence(conj, *tam, elemento) == 1) { //caso o elemento esteja no conj
        for (i=0; i < *tam; i++) {
            if (conj[i] == elemento) {
            	pos = i; //encontramos sua posicao
            }
        }

		for (i=pos; i < *tam-1; i++) { //a partir de sua 'pos' deslocamos o vetor
        	conj[i] = conj[i+1]; //deixando o elemento para 'fora' do vetor
        }

		if (*tam-1 <= *cap*0.25 && *cap > 2) { 
			conj = realloc(conj, *cap*0.5*sizeof(int)); //realocamos o conj 
			*cap = *cap*0.5; //atualizando sua cap para metade da anterior
		} 

        *tam = *tam-1; //apos remocao do elemento, atualizamos seu tamanho
        return conj;
    }
	else { //caso nao pertenca ao conj
		return conj;
    	}
}

int *uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int i, j;
	int *conj_C;
	
	conj_C = init(tam_C, cap_C); //inicializacao do vetor resultante

    for (i=0; i<tam_A; i++) {
        conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]); //todos os elementos de A para C
    }

    for (j = 0; j < tam_B; j++) { //como em 'adicao' ja ha funcao 'pertence'
        conj_C = adicao(conj_C, tam_C, cap_C, conj_B[j]); //podemos passar todos de B para C
    }													// sem preocupacao de elementos duplicados
    return conj_C; //retornamos o ponteiro para o vetor resultante
}

int *intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
	int i, j;
	int *conj_C;
	
	conj_C = init(tam_C, cap_C); 

	for (i = 0; i < tam_A; i++) {
        for (j = 0; j < tam_B; j++) {
            if (conj_A[i] == conj_B[j]) { //verificamos se ha elementos iguais em ambos os conj
                conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]); //caso haja, sera adicionado em C nos dando a intersecao
            }
        }
    }
    return conj_C;
}

int *diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {
    int i, j;
	int *conj_C;

	conj_C = init(tam_C, cap_C);
    
    for (i = 0; i < tam_A; i++) { //adicionamos todos os elementos de A em C
		conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);
    }
	for (j = 0; j < tam_B; j++) { //subtraimos todos os elementos de B que estao em C
		conj_C = subtracao(conj_C, tam_C, cap_C, conj_B[j]); //funcao 'pertence' presente
	}
    return conj_C; //retornamos o ponteiro para C
}
