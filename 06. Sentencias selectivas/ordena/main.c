# include <stdio.h>

void main (void)
{
int numero1, numero2, numero3, temporal;
printf ("INTRODUZCA 3 NUMEROS \n");
scanf ("%d %d %d",&numero1,&numero2,&numero3);

if (numero1>=numero2)
	{
	temporal=numero1;
	numero1=numero2;
	numero2=temporal;
	}
if (numero1>=numero3)
	{
	temporal=numero1;
	numero1=numero3;
	numero3=temporal;
	}
if (numero2>=numero3)
	{
	temporal=numero2;
	numero2=numero3;
	numero3=temporal;
	}

printf ("%d %d %d",numero1,numero2,numero3);
}