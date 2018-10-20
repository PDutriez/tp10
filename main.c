#include <stdio.h>
#include "dados.h"
#include "modulall.c"

int main(int argc,char* argv[])
{
  char** opciones;//Arreglo con las opciones
  char** parametros;//Arreglo con los parametros
  char* cantdados;
  char* tiradas;
  char* caras;
  opciones=checkopt(argc,argv);
  parametros=checkpar(argc,argv);
  cantdados=searchword(opciones,countopt(argc,argv),"-cantidad");
  tiradas=searchword(opciones,countopt(argc,argv),"-tiradas");
  caras=searchword(opciones,countopt(argc,argv),"-caras");
  fullroll(passint(tiradas),passint(cantdados),passint(caras));

}

char* searchword(char** arr,int arrsize,char* word)
{
    int status;
    char* resultado=NULL;
    for(int count1=0;count<arrsize;count+=2)
    {
        status=1;
        for(int count2=0;(arr[count1][count2]!=0 || mainname[count2]!=0) && status!=0;++count2)
        //No es necesario "!=0" pero ayuda a la comprension
        {
            if(arr[count1][count2] != mainname[count2])
            {
                status=0; //Implica que son distintos sus valore
            }
        }
        if(status)
        {
            resultado=arr[count1];//Seteamos el resultado al valor identificado
            count1=arrsize;//Hacemos que termine el loop del "for"
        }
    }
  return resultado;
}
unsigned int passint(char* pointer)
{
    unsigned int numero=0;
    while(*pointer!=0)
    {
        numero=numero*10+(*pointer-'0');
    }
    return numero;
}
