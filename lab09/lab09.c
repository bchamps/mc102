#include <stdio.h> //Nome: Bruno Campos; RA: 195080

int main () {
  int vetA[30]={0}, vetB[30]={0}, vetAux[30]={0}, vetResult[30]={0};
  int i, j, a, b;
  char c, d, signal;

    a = 0; //leitura Vetor A
  do {
      scanf ("%c", &c);
      if (c != '\n') {
          vetAux[a] = (int)c - 48;
          a++;
      }
  } while (c != '\n');
  
  for (i = 30 - a, j = 0; i < 30; i++ , j++) { //laco para alocar os numeros lidos nas ultimas casas do vetor A
      vetA[i] = vetAux[j];
      vetAux[j] = 0;
  }
  
    scanf ("%c\n", &signal);

    b = 0; //leitura vetor B
  do {
      scanf ("%c", &d);
      if (d!= '\n') {
          vetAux[b] = (int)d - 48;
          b++;
      }
  } while (d != '\n');
  
  for (i = 30 - b, j = 0; i < 30; i++, j++) { //laco para o vetor B
      vetB[i] = vetAux[j];
      vetAux[j] = 0;
  }
  for(a = 0; a <= 29; a++){
        printf("%d", vetA[a]);
  }
  printf("\n");
  for(a = 0; a <= 29; a++){
        printf("%d", vetB[a]);
  }
  printf("\n");
  
  
  if (signal == '+') { //estrutura de soma
      for (a = 29; a >= 0; a--) {
          vetResult[a] = vetA[a] + vetB[a]; 
          if (vetResult[0] >= 10) { 
                printf ("overflow\n");
                return 0;
              }
          vetA[a-1] += vetResult[a] / 10;  
          vetResult[a] = vetResult[a] % 10;
          for(i = 0, j = 0; i<= 29, vetResult[i] == 0; i++){
                j++;
          }           
      }for(i = 0 + j; i <= 29; i++){
                printf("%d", vetResult[i]);
            }
            printf("\n");
    
    }else if(signal == '-'){//Subtracao
        for(i = 0; i <= 29 && vetA[i] == vetB[i]; i++){
            if(i == 29){
                printf("0\n");
                return 0;
            }
        }


        for(a = 0; a <= 29; a++){
            if(vetA[a] < vetB[a]){
                for(b = 29; b >= 0; b--){
                    if(vetB[b] >= vetA[b]){
                        vetResult[b] = vetB[b] - vetA[b];
                    }else if(vetB[b] < vetA[b]){
                        vetResult[b] = ((10 + vetB[b]) - vetA[b]);
                        vetB[b-1]--;
                    }
                    if(vetResult[b + 1] < 0){
                        vetResult[b + 1] = vetResult[b+1] * (-1);
                    }
                }
            printf("-");
            break;
            }else if(vetA[a] > vetB[a]){
                for(b = 29; b >= 0; b--){
                    if(vetA[b] >= vetB[b]){
                        vetResult[b] = vetA[b] - vetB[b];
                    }else if(vetA[b] < vetB[b]){
                        vetResult[b] = (10 + vetA[b]) - vetB[b];
                        vetA[b-1]--;
                    }  
                }
            break;
            }
        }
           
        for(i = 0, j = 0; i <=29 && vetResult[i] == 0; i++){
            j++;    
        }
        for(i = 0 + j; i <= 29; i++){
            printf("%d", vetResult[i]);
        }
        printf("\n");
    }
}
