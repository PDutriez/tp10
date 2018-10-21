#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "dados.h"
//Undado se encarga de tirar el nro random, recibe la cantidad de caras del dado
static int undado(unsigned int const caras);
//Unatirada se encarga de la ejecucion de una tirada, recibiendo la cantidad de dados y sus caras
static void unatirada(unsigned int const cantdados,unsigned int const caras,FILE* output);

void fullroll(unsigned int tiradas,unsigned int cantdados,unsigned int caras,FILE* output)
{
	int rollnum;		//variable de control, numero de tirada
	srand(time(NULL));	//random seed
<<<<<<< HEAD
	printf("Se están utilizando %d dados de %d caras.\n",cantdados,caras);	//imprie encabezado
=======
	fprintf(output,"Se están utilizando dados de %d caras.\n",caras);	//imprie encabezado
>>>>>>> ab0159ff959d4699e0c995709ceb3fbbf2e10f83
	for(rollnum=1;rollnum<=tiradas;rollnum++)
	{
		fprintf(output,"Tirada %d:",rollnum);	//imprime subencabezado de tirada
		unatirada(cantdados,caras,output);		//resuelve el resto de la tirada
	}

}

static int undado(unsigned int const caras)
{
	int result;						//resultado de la tirada
	result=((rand() % caras)+1);	//limita resultados segun num de caras
	return result;
}

static void unatirada(unsigned int const cantdados,unsigned int const caras,FILE* output)
{
	int uno;					//resultado de una dado
	int total=0;					//suma de los dados de la tirada
	int i;						//variable de control, numero de dado

	for(i=0;i<cantdados;i++)
	{
		uno=undado(caras);
<<<<<<< HEAD
		printf("  %d,",uno);		//imprime result de cada dado
		total+=uno;				//los suma al total
	}
	printf("\t- Suma:%d \n",total);	//imprime total
=======
		fprintf(output,", %d",uno);		//imprime result de cada dado
		total+=uno;				//los suma al total
	}
	fprintf(output," - Suma:%d \n",total);	//imprime total
>>>>>>> ab0159ff959d4699e0c995709ceb3fbbf2e10f83
}
