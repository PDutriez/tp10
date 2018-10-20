#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

/*NOTAS EQUIPO BORRAR antaes de entregar:
funciones para calcular e imprimir tiradas de dados.
desde el main solo se nesecita invocar la funcion:

fullroll(int numero*de*tiradas, int dados*por*tirada, int caras*por*dado)

no puse controles de error porque pense que seria mejor hacerlo directamente cuando
 se obtiene la data del imput. recomendaria poner un limite de 1000/2000 a numero de
  dados y caras y 200.000.000.000 a la s tiradas (se pueden a cambiar algunos int por unsiged int si les parece)

todo output esta como printf necesita redireccion a file.txt
*/
//UNDADO se ocupa de obtener el resultado de un dado
void fullroll(int tiradas, int cantdados, int caras)
{
	int rollnum;		//variable de control, numero de tirada
	printf("Se están utilizando dados de %d caras.\n",caras);	//imprie encabezado
	for(rollnum=1;rollnum<=tiradas;rollnum++)
	{
		printf("Tirada %d:",rollnum);	//imprime subencabezado de tirada
		unatirada(cantdados,caras);		//resuelve el resto de la tirada
	}

}

int undado(int const caras)
{
	int result;						//resultado de la tirada
	result=((rand() % caras)+1);	//limita resultados segun num de caras
	return result;
}

int unatirada(int cantdados, int caras)
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
	return 0;	//para debug
}
