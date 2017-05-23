#include <stdio.h> //Nome: Bruno Campos;RA: 195080

int main () {
	int hit, hits, ryu, ken, sum, start, i;
	ryu = 0;
	ken = 0;
	start = 1;
	hits = 0;

	do {
	scanf("%d", &hit);
	if (hit >= 0 && start == 1) { //identificador de rounds
			if (hits > 0) { //round para Ryu
				ryu = ryu + 1;
			}
			if ( hits < 0) { //round para Ken
				ken = ken + 1;
			}
			hits = 0;
			start = 0;
		}		
		if (hit < 0) { //Ataque Ken
			start = 1;
			sum = 0;
			for (i = 1; i < -hit; i++) { //multiplicador
				if(-hit % i == 0){
					sum = sum + i;
				}	
			}
			if(sum == -hit) { //multplicador para numero perfeito
				hit = hit * 3;
			}
			else {
				sum = 0;
				for (i = 1; i <= -hit && sum <= -hit; i++) { //..para triangular
					sum = sum + i;
					if (sum == -hit) {
						hit = hit * 2;
					}
				}
			}
			hits += hit;
		}
		if (hit > 0) { //Ataque Ryu
			sum = 0;
			for (i = 1; i < hit; i++) {
				if(hit % i == 0) {
					sum = sum + i;
				}	
			}
			if(sum == hit) {
				hit = hit * 3;
			}
			else {
				sum = 0;
				for (i = 1; i <= hit && sum <= hit; i++) {
					sum = sum + i;
					if (sum == hit) {
						hit = hit * 2;
					}
				}
			}
			hits += hit;
		}
	} while (hit != 0);

	if (ken > ryu)
		printf ("Ken venceu\n");
	if (ryu > ken)
		printf ("Ryu venceu\n");
	if (ryu == ken)
		printf ("empatou\n");
return 0;
}
