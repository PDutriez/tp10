#ifndef JUSTPOINT_H
#define JUSTPOINT_H
/************************************************************************************
 * PROTOTIPOS DE FUNCIONES
 ***********************************************************************************/
int checkname(const char* name,const char* mainname);
/*Funcion que se encarga de verificar la veracidad del nombre, tiene incorporado
un mensaje de error en caso de ser distinto el nombre del archivo (mainname) y el
 nombre del ejecutable (name)*/
int countpar(int argc,char *argv[]);
/*Funcion que cuenta la cantidad de parametros, devuelve la cantidad total*/
int countopt(int argc,char *argv[]);
/*Funcion que cuenta la cantidad de operandos, devuelve la cantidad total*/
char** checkpar(int argc,char *argv[]);
/*Funcion que se encarga de detectar y ordenar todos los parametros enviados por la
 terminal. Devuelve un puntero al arreglo de parametros que fueron encontrados*/
char** checkopt(int argc,char* argv[]);
/*Funcion que se encarga de detectar y ordenar todas las opciones enviadas por la
 terminal. Devuelve un puntero al arreglo de opciones que fueron encontradas */
/************************************************************************************
 * CONSTANTES
 ***********************************************************************************/
#define O_MAX 10
#endif
