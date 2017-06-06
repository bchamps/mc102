/* Lab17
 * Nome: Bruno Campos
 * RA: 195080 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Considerar:
 * struct
 * funcoes lab14 + ponteiro
 * O campo armazenado deverá conter o número de alunos cadastrados na base, 
 * o campo capacidade deverá conter o tamanho alocado do vetor alunos, 
 * enquanto que este último deverá apontar para o vetor alunos alocado. 
 * Implementar 6 funcoes: 
 *	Criar a base(ok);
 * 	Liberar a base(ok);
 * 	Buscar(ok);
 * 	Adicionar/Alterar(ok);
 * 	Imprimir(ok);
 * 	Remover(ok);
 */

typedef struct {
  int ra, telefone;
  char nome[100];
} Aluno;

typedef struct {
  int armazenado;
  int capacidade;
  Aluno *alunos;
} Base;

/* Funcao: criar_base
 *
 * Inicializa a base ja com a capacidade.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   n: quantidade maxima de alunos
 */
void criar_base(Base (*base), int n) {

	(*base).alunos = malloc(n*sizeof(Base));
	(*base).capacidade = n;
	(*base).armazenado = 0;
	printf ("Base criada.\n");
			 
	return;
}

/* Funcao: buscar
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *
 * Retorno:
 *   Indice do registro com RA no vetor de alunos
 *   -1 caso contrario.
 */
int buscar(Base *base, int ra) {

	for (int i=0; i<(*base).armazenado; i++) {
		if ((*base).alunos[i].ra == ra) {
			return i;
		}
	}
	
	return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {
int i;

	if (buscar (base,ra) == -1) {
		printf("Aluno %d nao encontrado.\n", ra);
	}
	else {
		i = buscar(base, ra);
		printf("%d - %d - %s\n", (*base).alunos[i].ra, (*base).alunos[i].telefone, (*base).alunos[i].nome);	
	}
	return;
}

/* Funcoes: adicionar
 *
 * Inclui um registro sem permitir RAs duplicados.
 * O quantidade de alunos deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *   telefone: numero do telefone
 *   nome: string com o nome
 */
void adicionar(Base *base, int ra, int telefone, char *nome) {
	
	if (buscar(base, ra) == -1) {
		if ((*base).capacidade != (*base).armazenado) {
			(*base).alunos[(*base).armazenado].ra = ra;
			(*base).alunos[(*base).armazenado].telefone = telefone;
			strcpy((*base).alunos[(*base).armazenado].nome, nome); 
	
			(*base).armazenado++;

			printf("Adicionado: ");
			imprimir(base, ra);
		}
		else {
			printf("Erro: base cheia.\n");
		}
	}

	else {
		int pos = buscar(base, ra);
		(*base).alunos[pos].ra = ra;
		(*base).alunos[pos].telefone = telefone;
		strcpy((*base).alunos[pos].nome, nome);

		printf("Alterado: ");
		imprimir(base, ra);
	}
	return;
}

/* Funcoes: remover
 *
 * Remove um registro se o ra estiver presente.
 * O quantidade de registro deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void remover(Base *base, int ra) {
	
	if (buscar(base, ra) == -1) {
		printf("Aluno %d nao encontrado.\n", ra);
	}
	else {
		int pos = buscar(base, ra); 
		for (int i=pos; i<(*base).armazenado-1; i++) {
			((*base)).alunos[i] = ((*base)).alunos[i+1];
		}

		((*base)).armazenado--;
		
		printf("Aluno %d removido.\n", ra);
	}
	return;
}

/* Funcao: liberar_base
 *
 * Libera a memoria de todos alunos da base.
 * Deve deixar a base com capacidade e quantidade armazenada igual a zero
 * e o ponteiro para alunos igual a NULL.
 *
 * Parametros:
 *   base: ponteiro para a base
 */
void liberar_base(Base *base) {
	
	((*base)).armazenado = 0;
	((*base)).capacidade = 0;
	((*base)).alunos = NULL;

	free(((*base)).alunos);
	return;
}
