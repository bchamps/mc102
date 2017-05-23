#include <stdio.h>

int main () {

        float  h, vb, d, T, a, b, c; /*O objetivo deste programa eh obtermos o valor do tempo, em segundos, de queda da bomba. Sendo assim, obteremos o tempo para que a bomba seja ativada. Nome: Bruno Campos;RA:195080*/

        scanf ("%f",&h); /*Criadas as variaveis para plotarmos os valores de altura, velocidade, deslocamento horizontal e empuxo,teremos como obter o tempo de queda*/
        scanf ("%f", &vb);
        scanf ("%f", &d);
        scanf ("%f", &T);

        a = h / vb; /*A partir das equacoes teremos o tempo 'c' em que a bomba sera ativada*/
        b = d / T;
        c = a - b;

        printf ("%.3f\n", c); /*Tendo 'c', o tempo em questao sera mostrado com 3 casas decimais*/ 

        return 0;
}

