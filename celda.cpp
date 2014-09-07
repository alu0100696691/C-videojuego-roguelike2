/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: CELDA.CPP
******************************************************************
*/



#include "celda.h"



Celda::Celda() //constructor
{
  elemento = ' '; //celda vacia
};

Celda::Celda(char elem)  //constructor
{
  elemento = elem;
};

void Celda::setCelda(char elem)
{
  elemento = elem;
};

char Celda::getCelda()
{
  return(elemento);
};

