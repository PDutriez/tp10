#include <stdio.h>
#include "modulall.h"
/*******************************************************************************
 * arreglos para guardar los argumentos que vamos a separar más adelante
 * en tres secciones distintas
 ******************************************************************************/
static char * opciones [2*O_MAX];  //Arreglo con todas las opciones
static char * parametros [O_MAX];   //Arreglo con todos los parametros
/******************************************************************************/
char** checkopt(int argc,char* argv[])
{
    int word,options=0;
    for(word=1;word<argc;word++) //Empezamos en 1 para saltear el nombre
    {
       if(*argv[word]=='-')
       {
               opciones[options] = argv [word]; //Guardamos su clave y valor
               if(*argv[++word]!='-') //Implica que fue cargado el valor correctamente
               opciones[++options] = argv [word];
               else
               {
		 printf("Valor de la opcion %d no encontrado",word);
                 ++options;
       	       }
	}
   }
   return opciones; //Cantidad total de opciones
}

int countopt(int argc,char* argv[])
{
    int count,cantidad=0;
    for(count=1;count<argc;++count)
    {
        if(*argv[count] == '-')
              ++cantidad;
    }
    return cantidad;
}

int countpar(int argc,char* argv[])
{
    int count,cantidad=0;
    for(count=1;count<argc;++count)
    {
        if(*argv[count] == '-')
              ++count;
        else
              ++cantidad;
    }
    return cantidad;
}

char** checkpar(int argc,char* argv[])
{
  int word,parameters=0;
  for(word=1;word<argc;word++) //Empezamos en 1 para saltear el nombre
  {
     if(*argv [word]=='-') //Si empieza con el guion, es una opcion y debemos saltearla
          word++;
     else 	//En el caso contrario la unica opcion es que sea un parametro
          parametros[parameters++] = argv[word];
  }
  return parametros; //Cantidad total de parametros
}

int checkname(const char* name,const char* mainname)
{
    int status=1;    //Inicialmente creemos que ambas son iguales
    name+=2;         //Seteamos el puntero al inicio del nombre
    printf("Nombre actual del archivo: %s\n",name);
    while((*name!=0 || *mainname!=0) && status!=0) //No es necesario "!=0" pero ayuda a la comprension
    {
        if(*name++ != *mainname++)
          {
          status=0; //Implica que son distintos sus valore
          printf("\nERROR: Se ha modificado el nombre original del archivo\n\n");
          }
    }
    return status;
}
