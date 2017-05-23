#include <stdio.h>
	
	int main () {
		int	vi, xi, yi, xf, yf, t, vf; /*O objetivo da tarefa eh obter o valor de uma viagem a partir das variaveis declaradas. Na entrada, temos variaveis que irao abrigar os parametros como valor fixo inicial e distancias percorridas na horizontal e vertical.
Nome: Bruno Campos; RA: 195080*/  
		int d;	
	
		scanf ("%d", &vi);
		scanf ("%d", &xi);
		scanf ("%d", &yi);
		scanf ("%d", &xf);
		scanf ("%d", &yf);
		scanf ("%d", &t);

		d = (xf - xi) + (yf - yi); /*Sendo este o calculo das distancias, temos que 'd' eh a variavel que abriga o valor do deslocamento final*/
 		vf = vi + (d*t); /*A partir do valor do deslocamento, multiplicamos pela distancia percorrida 'd' e somamos ao valor fixo 'vi', obtendo o valor final 'vf'*/ 
 
		printf("%d\n", vf); /*Assim, sera mostrado na tela o valor final 'vf' da viagem*/

		return 0;
}
