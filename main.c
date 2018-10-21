#include <stdio.h>
#include "dados.h"
#include "modulall.h"
typedef char**  pointall_t;
typedef char*   point_t;
/**********************************DECLARACIONES**********************************/
/*La Funcion searchvalue se encarga de buscar el valor de una opcion,debe recibir
* el arreglo de opciones, su tamaño y el nombre de la opcion. En caso de no
* encontrarlo pasa el puntero NULL.*/
static char* searchvalue(char** arr,int arrsize,char* word);
/*La Funcion passint se encarga de pasar un string de numeros a unsigned int, solo
* debe recibir un puntero al string y devuelve el resultado.*/
static unsigned int passint(char* pointer);
/*La Funcion searchtxt busca entre los parametros el nombre de un tipo archivo que
* se esta buscando. Debe recibir el inicio de parametros, su tamaño y el ".xxx" que
* se quiere encontrar. Devuelve un puntero al arreglo, en caso de no encontrarlo,
* devuelve el puntero NULL.*/
static char* searchtxt(char** arr,int arrsize,char* word);
/***************************************MAIN***************************************/
int main(int argc,char* argv[])
{
	FILE *output;
 	int fileflag=0;
	pointall_t opciones, parametros;//Arreglo con las opciones y los parametros
  point_t pointdados, pointtiradas, pointcaras/*, archivo*/;
  opciones=checkopt(argc,argv);//Cantidad de opciones que hay
  parametros=checkpar(argc,argv);//Cantidad de parametros que hay
  pointdados=searchvalue(opciones,countopt(argc,argv),"-cantidad");//Puntero a la cantidad de dados
  pointtiradas=searchvalue(opciones,countopt(argc,argv),"-tiradas");//Puntero a la cantidad de tiradas
  pointcaras=searchvalue(opciones,countopt(argc,argv),"-caras");//Puntero a la cantidad de caras
  archivo=searchtxt(parametros,countpar(argc,argv),".txt");
	if(archivo)
	{
      output=fopen(archivo,"w");
			fileflag=1;
	}
	else
	{
		output=stdout;
	}
printf("tiradas: %u\t caras: %u\t cantidad: %u\n",passint(pointtiradas),passint(pointdados),passint(pointcaras));
  fullroll(passint(pointtiradas),passint(pointdados),passint(pointcaras),output);

	if(fileflag)
		fclose(output);
}

static char* searchvalue(char** arr,int arrsize,char* word)
{
    int status;
    char* resultado=NULL;
    for(int count1=0;count1<(arrsize*2);count1+=2)//Sumamos de 2 en 2 debido a la forma del arreglo
    {
        status=1;//Inicialmente se cree que son iguales y luego se verifica si realmente lo es
        for(int count2=0;(arr[count1][count2]!=0 || word[count2]!=0) && status!=0;++count2)
        //No es necesario "!=0" pero ayuda a la comprension
        {
            if(arr[count1][count2] != word[count2])
            {
                status=0; //Implica que son distintos sus valore
            }
        }
        if(status)//En caso de que no haya cambiado el valor de status implica que encontramos la palabra
        {
            resultado=arr[++count1];//Seteamos el resultado al valor identificado
            count1=arrsize;//Hacemos que termine el loop del "for"
        }
    }
  return resultado;
}
static char* searchtxt(char** arr,int arrsize,char* word)
{

    int status;
    char* resultado=NULL;
    int length;//Esta variable va a indicar el largo de la palabra a analizar
    int lengthword;//Esta variable va a indicar el largo del ".xxx" a buscar
    for(lengthword=0;word[lengthword]!=0;++lengthword);//Calculamos el largo del sufijo para el tipo de archivo
    for(int count1=0;count1<arrsize;++count1)//Contador para las palabras dentro del arreglo
    {
        status=1;
        for(length=0;arr[count1][length]!=0;++length);//Calculamos el largo de la palabra nueva

				char* check=&arr[count1][length-lengthword];//Creamos un puntero al inicio de donde deberia estar el ".xxx"

				for(int count2=0;(check[count2]!=0 || word[count2]!=0) && status!=0;++count2)
        //No es necesario "!=0" pero ayuda a la comprension
        {
            if(check[count2] != word[count2])
            {
                status=0; //Implica que son distintos sus valore
            }
        }
        if(status)
        {
            resultado=arr[++count1];//Seteamos el resultado al valor identificado
            count1=arrsize;//Hacemos que termine el loop del "for"
        }
    }
  return resultado;
}

static unsigned int passint(char* pointer)//Pasa un string de numeros en char a un numero unsigned int completo
{
    unsigned int numero=0;
    while((*pointer)!=0)//si es igual a 0
    {
            numero=numero*10+(*pointer++-'0');
    }
    return numero;
}
