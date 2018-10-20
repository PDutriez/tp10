#include <stdio.h>
#include "dados.h"
#include "modulall.c"
typedef char**  pointall_t;
typedef char*   point_t;
typedef unsigned int values_t;
char* searchword(char** arr,int arrsize,char* word);
unsigned int passint(char* pointer);

int main(int argc,char* argv[])
{
  pointall_t opciones, parametros;//Arreglo con las opciones y los parametros
  point_t pointdados, pointtiradas, pointcaras;
  values_t dados,tiradas,caras;
  opciones=checkopt(argc,argv);
  parametros=checkpar(argc,argv);
  pointdados=searchword(opciones,countopt(argc,argv),"-cantidad");
  pointtiradas=searchword(opciones,countopt(argc,argv),"-tiradas");
  pointcaras=searchword(opciones,countopt(argc,argv),"-caras");
  dados=passint(pointdados);
  tiradas=passint(pointtiradas);
  caras=passint(pointcaras);
  fullroll(tiradas,dados,caras);

}

char* searchword(char** arr,int arrsize,char* word)
{
    int status;
    char* resultado=NULL;
    for(int count1=0;count1<arrsize;count1+=2)
    {
        status=1;
        for(int count2=0;(arr[count1][count2]!=0 || word[count2]!=0) && status!=0;++count2)
        //No es necesario "!=0" pero ayuda a la comprension
        {
            if(arr[count1][count2] != word[count2])
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
