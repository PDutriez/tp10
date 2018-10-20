#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "dados.h"
//Undado se encarga de tirar el nro random, recibe la cantidad de caras del dado
static int undado(unsigned int const caras);
//Unatirada se encarga de la ejecucion de una tirada, recibiendo la cantidad de dados y sus caras
static void unatirada(unsigned int const cantdados,unsigned int const caras);

void fullroll(unsigned int tiradas,unsigned int cantdados,unsigned int caras)
{
	int rollnum;		//variable de control, numero de tirada
	srand(time(NULL));	//random seed
	printf("Se están utilizando dados de %d caras.\n",caras);	//imprie encabezado
	for(rollnum=1;rollnum<=tiradas;rollnum++)
	{
		printf("Tirada %d:",rollnum);	//imprime subencabezado de tirada
		unatirada(cantdados,caras);		//resuelve el resto de la tirada
	}

}

static int undado(unsigned int const caras)
{
	int result;						//resultado de la tirada
	result=((rand() % caras)+1);	//limita resultados segun num de caras
	return result;
}

static void unatirada(unsigned int const cantdados,unsigned int const caras)
{
	int uno;					//resultado de una dado
	int total=0;					//suma de los dados de la tirada
	int i;						//variable de control, numero de dado

	for(i=0;i<cantdados;i++)
	{
		uno=undado(caras);
		printf(", %d",uno);		//imprime result de cada dado
		total+=uno;				//los suma al total
	}
	printf(" - Suma:%d \n",total);	//imprime total
}
