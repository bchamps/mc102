#include <stdio.h> //Nome: Bruno Campos; RA: 195080

int main () {
	int C, f;
	C = 0;
	scanf ("%d", &C);
	
	while (1) {
	scanf ("%d", &f);
		if (f >= 1) {
			if (C - f >= 0) {	
			C = C - f;
			printf ("Seja bem-vindo! Capacidade restante: %d\n", C);
			}		
			else {
			printf ("Veiculo muito grande! Capacidade restante: %d\n", C); 	
			}
		}
		else if (C < f) {
		printf ("Veiculo muito grande! Capacidade restante: %d\n", C);
		}	
		else if (f == 0) {
		break;		
		}
		else {
			if (C - f >= 0) {
			C = C - f;
			printf ("Volte sempre! Capacidade restante: %d\n", C);
			}
			else if (C < f) {
			printf ("Veiculo muito grande! Capacidade restante: %d\n", C);
			}			
		}

	}

return 0;
}
