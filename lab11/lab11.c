#include <stdio.h>  //Nome: Bruno Campos; RA:195080
#include <string.h>

int main () {
    char st[1001], N[]="mercurio", S[]="jupiter", L[]="terra", O[]="urano", NE[]="venus", NO[]="netuno", SE[]="marte", SO[]="saturno";
    int i, size;
	char vd[]= "verde", am[]= "amarelo", vm[]= "vermelho"; 
	
    fgets (st, 1001, stdin);
    size = strlen (st);
    
    for (i = 0; i < size; i++) { //estrutura para converter cada palavra maiuscula em minuscula
        if (st[i] >= 'A' && st[i] <= 'Z') {
            st[i] = st[i] + 32; 
        }
        //printf ("%c", st[i]); teste da conversao
    }
    
	for (i = 0; i < size; i++) { //laco de contagem e verificacao letra a letra
	  if (st[i] == N[0]) {
		if (st[i + 1] == N[1]) {
		  if (st[i + 2] == N[2]) {
			if (st [i + 3] == N[3]) {
			  if (st [i + 4] == N[4]) {
				if (st [i + 5] == N[5]) {
				  if (st [i + 6] == N[6]) {
					if (st [i + 7] == N[7]) {
					  printf ("N - "); //apos verificacao, se todas as letras forem iguais, sera printada a direcao referente
					}
				  }
				}
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == S[0]) {
		if (st[i + 1] == S[1]) {
		  if (st[i + 2] == S[2]) {
			if (st [i + 3] == S[3]) {
			  if (st [i + 4] == S[4]) {
				if (st [i + 5] == S[5]) {
				  if (st [i + 6] == S[6]) {
					printf ("S - ");
				  }
				}
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == L[0]) {
		if (st[i + 1] == L[1]) {
		  if (st[i + 2] == L[2]) {
			if (st [i + 3] == L[3]) {
			  if (st [i + 4] == L[4]) {
				  printf ("L - ");
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == O[0]) {
		if (st[i + 1] == O[1]) {
		  if (st[i + 2] == O[2]) {
			if (st [i + 3] == O[3]) {
			  if (st [i + 4] == O[4]) {
				printf ("O - ");
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == NE[0]) {
		if (st[i + 1] == NE[1]) {
		  if (st[i + 2] == NE[2]) {
			if (st [i + 3] == NE[3]) {
			  if (st [i + 4] == NE[4]) {
				printf ("NE - ");
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == NO[0]) {
		if (st[i + 1] == NO[1]) {
		  if (st[i + 2] == NO[2]) {
			if (st [i + 3] == NO[3]) {
			  if (st [i + 4] == NO[4]) {
				if (st [i + 5] == NO[5]) {
				  printf ("NO - ");
				}
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == SE[0]) {
		if (st[i + 1] == SE[1]) {
		  if (st[i + 2] == SE[2]) {
			if (st [i + 3] == SE[3]) {
			  if (st [i + 4] == SE[4]) {
				printf ("SE - ");
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == SO[0]) {
		if (st[i + 1] == SO[1]) {
		  if (st[i + 2] == SO[2]) {
			if (st [i + 3] == SO[3]) {
			  if (st [i + 4] == SO[4]) {
				if (st [i + 5] == SO[5]) {
				  if (st [i + 6] == SO[6]) {
					printf ("SO - ");
				  }
				}
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == vd[0]) { //apos as direcoes iremos verificar as palavras para as cores e entao printa-las com a elevacao referente
		if (st[i + 1] == vd[1]) {
		  if (st[i + 2] == vd[2]) {
			if (st [i + 3] == vd[3]) {
			  if (st [i + 4] == vd[4]) {
				printf ("30\n");
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == am[0]) {
		if (st[i + 1] == am[1]) {
		  if (st[i + 2] == am[2]) {
			if (st [i + 3] == am[3]) {
			  if (st [i + 4] == am[4]) {
				if (st [i + 5] == am[5]) {
				  if (st [i + 6] == am[6]) {
					printf ("45\n");
				  }
				}
			  }
			}
		  }
		}
	  }
	  
	  if (st[i] == vm[0]) {
		if (st[i + 1] == vm[1]) {
		  if (st[i + 2] == vm[2]) {
			if (st [i + 3] == vm[3]) {
			  if (st [i + 4] == vm[4]) {
				if (st [i + 5] == vm[5]) {
				  if (st [i + 6] == vm[6]) {
					if (st [i + 7] == vm[7]) {
					  printf ("60\n");
					}
				  }
				}
			  }
			}
		  }
		}
	  }
	}
return 0;

}
