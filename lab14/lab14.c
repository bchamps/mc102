/* Nome: Bruno Campos;
 * RA: 195080;
 * Objetivos: Obter um programa que receba e organize numeros de RAs, seja de forma crescente ou decrescente
 * entre as funcoes exigidas estao: inclusao, impressao, busca binaria e remocao. 
 */

#include <stdio.h>

void ordemC(int RAs[], int numAlunos);
void ordemD(int RAs[], int numAlunos);
void read(int RAs[], int numAlunos);
void print(int RAs[], int numAlunos);
int insert(int RAs[], int numAlunos);
int removeAluno(int RAs[], int numAlunos);
int findRA(int RAs[], int numAlunos, int RA);
int Binarysearch(int RAs[], int numAlunos, int RA, int ord);

int main () {
    int numAlunos, RA, ord, f;
    int RAs[150];    
    char command;
    scanf ("%d", &numAlunos);
    read(RAs, numAlunos);
    ord=0;
        
    while (1) { //lista de comandos referente as funcoes exigidas
        scanf ("%c", &command);
        if (command == 's')
            break;
        if (command == 'p') {
            print(RAs, numAlunos);
        }
        if (command == 'i') {
            numAlunos = insert(RAs, numAlunos); //para insercao temos opcoes secundarias de ordenacao: C ou D
            if (ord == 1) {
                ordemC(RAs, numAlunos);
            }
            if (ord == 2) {
                ordemD(RAs, numAlunos);
            }
        }
        if (command == 'r') {
            numAlunos = removeAluno(RAs, numAlunos);
        }
        if (command == 'b') { //Binarysearch exige vetor ordenado
            scanf("%d", &RA);
            if (ord == 0) {
                printf("Vetor nao ordenado!\n");
            } else 
                f =  Binarysearch(RAs, numAlunos, RA, ord);
            if (f == -1)
                printf("%d nao esta na lista!\n", RA);
        }
        if (command == 'c') {
            ordemC(RAs, numAlunos);
            ord=1;
        }
        if (command == 'd') {
            ordemD(RAs, numAlunos);
            ord=2;
        }
    }
}

int pertence(int RAs[], int numAlunos, int RA) {
int i;
    for (i=0; i < numAlunos; i++) {
        if (RAs[i] == RA) {
            return 1;
        }
    }
    return 0;
}

/* Missões: 
  * impressao, ordenaçao, inclusao, remoçao e busca
  * p - print (anyway)
  * c - ordenaçao crescente -> bubble sort
  * d - ordenaçao decrescente -> mesma ideia
  * b - busca binaria (ordenada, print position by steps, print final positon -> else: error message) *ordenado*
  * i - insert (independente da ordenaçao, if ordenada -> na posiçao correta; else: final; max: 150, if max: error message)
  * r - remove (if matriculados == 0 -> error message; if RAs != matriculados -> error message)
  * s - break;
  * RAs - int; max: 150;
  * b + RAs_busca
  * i + RAs_insercao
  * r + RAs_remocao
  * entradas: int alunos, int RAs, operacoes,'s' 
  * prints exigidos: ("Vetor nao ordenado!\n");
  * 				 ("%d esta na posicao: %d\n", RAs, pos);
  * 				 ("%d nao esta na lista!\n", RAs);
  * 				 ("Limite de vagas excedido!\n");
  * 				 ("Aluno ja matriculado na turma!\n");
  * 				 ("Nao ha alunos cadastRAsdos na turma!\n");
  * 				 ("Aluno nao matriculado na turma!\n");
*/

void read(int RAs[], int numAlunos) { //recebe RAs's
int i;
    for (i=0; i < numAlunos; i++) {
        scanf ("%d", &RAs[i]);
    }
}

void print(int RAs[], int numAlunos) { //impressao
int i;
    if (numAlunos != 0) {
        for (i=0; i < numAlunos; i++) {
            printf("%d ", RAs[i]);
        }
        printf ("\n");
    }
}

int insert(int RAs[], int numAlunos) { //insercao, ha um limite de 150
int RA;
    scanf ("%d", &RA);
    if (numAlunos == 150) { //maximo de alunos, se excedido: 'error message'
            printf ("Limite de vagas excedido!\n");
            return numAlunos;
        }
    if (pertence(RAs, numAlunos, RA)) { //caso ja pertencente
        printf("Aluno ja matriculado na turma!\n");
        return numAlunos;
    }
    else {
        RAs[numAlunos] = RA;
        return numAlunos+1;
    }
}

int removeAluno(int RAs[], int numAlunos) { //remocao do RA
    int RA, i;
    int indice;    
    scanf("%d", &RA);
    indice = findRA(RAs, numAlunos, RA);
    if (!pertence(RAs, numAlunos, RA)) { //casos para RA nao pertencente
        if (numAlunos == 0) {
            printf("Nao ha alunos cadastrados na turma!\n"); //vetor nulo
        }
        else {
            printf("Aluno nao matriculado na turma!\n"); //vetor nao nulo, mas nao incluso
        return numAlunos;
        }
    }
    if (indice > -1) {
        for (i = indice; i<numAlunos-1; i++) {
            RAs[i] = RAs [i+1];
        }
        return numAlunos-1;
    } else 
        return numAlunos;
}

int findRA(int RAs[], int numAlunos, int RA) { //busca da posicao do RA
int i;
    for (i=0; i< numAlunos; i++) {
        if (RAs[i] == RA) {
            return i;
        }
    }
    return -1;
}


void ordemC(int RAs[], int numAlunos) { //Bubble Sort Crescente
int i, j, aux;
    for (i=numAlunos-1; i > 0; i--) {
        for (j=0; j < i; j++) {
            if (RAs[j] > RAs[j + 1]) { //compara o maior e troca posicao
            aux = RAs[j];
            RAs[j] = RAs[j + 1];
            RAs[j + 1] = aux;
            }
        }
    }
}

void ordemD(int RAs[], int numAlunos) { //.. decrescente
int i, j, aux;
    for(i=0; i<numAlunos-1; i++){
        for(j=0; j<numAlunos-1; j++) {
            if (RAs[j] < RAs[j+1]) { //compara RAs quem eh o menor e troca sua posicao
                aux = RAs[j];
                RAs[j] = RAs[j+1];
                RAs[j+1] = aux;
            }
        }
    }
}

int Binarysearch(int RAs[], int numAlunos, int RA, int ord) { //busca binaria
int i=0, j=numAlunos-1, k; //i = start, j = fim, k = meio, RA = chave, ord = verificao ordemC ou ordemD
    if (ord == 1) { //caso ordemC
        while (i<=j) {
            k = (i+j)/2;
            printf("%d ", k);
            if (RAs[k] == RA) {
                printf("\n%d esta na posicao: %d\n", RA, k);
                return 0;
            }
            if (RAs[k] > RA) {
                j = k-1;
            }
            if (RAs[k] < RA) {
                i = k+1;
            }
        }
    }
    if (ord == 2) { //caso ordemD
        while (i<=j) {
            k = (i+j)/2;
            printf("%d ", k);
            if (RAs[k] == RA) {
                printf("\n%d esta na posicao: %d\n", RA, k);
                return 0;
            }
            if (RAs[k] < RA) {
                j = k-1;
            }
            if (RAs[k] > RA) {
                i = k+1;
            }
        }
    }
    printf("\n");
    return -1;
}
