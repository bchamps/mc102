#include <stdio.h>

	int main() {
		int first, second, add, subtract, mltiply, integer_div;
		float divide;

		print("Entre com dois inteiros\n");
		scanf("%d, %d", &first, &second);

		add	= first + second;
		subtract	= first - second;
		multiply 	= first * second;
		integer_div	= first / second;
		divide		= first / (float)second;	//typecast

		printf("Soma = %d\n",add);
		printf("Diferenca = %d\n",subtract);
		printf("Multiplicacao = %d\n",multiply);
		printf("Divisao Inteira = %d\n",interger_div);
		printf("Divisao = %.2f\n",divide);

		return ();
}
