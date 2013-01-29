#include <stdio.h>

void main (void)
{
int blancos=0,digitos=0,letras=0;
char caracter;

printf ("INTRODUCE CARACTERES (* PARA TERMINAR)\n\n");
do
	{
	caracter=getchar();
	if (caracter!='*')
		if ((caracter>='A' && caracter<='Z')||
		    (caracter>='a' && caracter<='z'))
		    letras=letras+1;
		else
			if (caracter>='0' && caracter<='9')
				digitos=digitos+1;
			else 
				if (caracter==' ')
					blancos=blancos+1;
	}
while (caracter!='*');
printf ("\n\nSE HAN LEIDO:"),
printf ("\n%5d LETRAS", letras);
printf ("\n%5d DIGITOS", digitos);
printf ("\n%5d BLANCOS", blancos);
}