#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h> //Compilar con -lm

//#define LIM 1000		//numeros a evaluar		

int main()
{
	unsigned short **p,NUM,LIM;//matriz que contiene NUM listas de los LIM numeros p[NUM][LIM]
	unsigned short i, j, k = 1, num = 0;
	char resp;
	printf("Escriba el rango maximo (menor o igual a 1000)\n");
	scanf_s("%hu",&LIM);
	while (LIM>1000) 
	{
		printf("El numero debe ser menor a 1000\n");
		scanf_s("%hu", &LIM);
	}
	NUM =(unsigned short) ceil(log10(LIM) / log10(2));//bit necesarios para formar la cantidad de numeros LIM

	p = (unsigned short **)malloc(NUM *sizeof(unsigned short **));
	for (j = 0; j < NUM; j++)
		*(p+j) = (unsigned short *)malloc(LIM * sizeof(unsigned short *));

	for (i = 1; i <= LIM; i++)
	{
		for (j = 1; j <= NUM; j++)
			p[j - 1][i - 1] = 0;		//inicializo toda la matriz a 0
	}

	for (i = 1; i <= LIM; i++)
	{
		for (j = 1; j <= NUM; j++, k <<= 1)	//k va incrementando el bit a evaluar
			if (i&k)p[j - 1][i - 1] = i;	//si un numero pertenece a la lista NUM correspondiente lo guardo
		k = 1;
	}
	k = 1;
	printf("Piense en un numero entre el 1 y el %d.\n", LIM);
	Sleep(3000);
	printf("Listo?\n");
	Sleep(3000);
	for (j = 1; j <= NUM; j++, k <<= 1)
	{
		resp = getchar();
		printf("Este numero en esta lista?(s\\n):\n");
		for (i = 1; i <= LIM; i++)
			if (p[j - 1][i - 1])printf("%d ", p[j - 1][i - 1]);	//muestro los numeros distintos de 0 
		printf("\n");
		resp = getchar();
		if (resp == 's' || resp == 'S')num += k;	//calculo el numero como si transformara un n�mero de binario a decimal(hace eso)
		system("cls");
	}
	if (num <= LIM)
		printf("El numero es:%d \n", num);
	else
		printf("No existe n\243mero que se encuentre en todas las listas indicadas\n"
			"O sea que o bien te equivocaste cuando dijiste que el n\243mero se encontraba en una lista\n"
			"O pusiste si y no al azar para ver que pasaba\n");
	system("pause");
	return 0;
}
