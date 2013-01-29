 # include <stdio.h>

 void main (void)
 {
 float num1,num2;
 printf ("INTRODUCIR EL NUMERO --->");
 scanf ("%f",&num1);
 num2=num1;
 if (num1>0)
	{
	for (;num1>1;)
	{
		num1--;
		num2=num2*num1;
	}
	printf ("EL FACTORIAL DEL NUMERO INTRODUCIDO ES %.0f\n",num2);
	}
 else
	printf ("EL FACTORIAL DEL NUMERO INTRODUCIDO NO EXISTE");
 }