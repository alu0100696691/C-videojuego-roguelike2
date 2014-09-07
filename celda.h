/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: CELDA.H
******************************************************************
*/



#ifndef _celda_H_
#define _celda_H_



class Celda
{
private:
  char elemento;
public:
  Celda();
  Celda(char elem); //constructor 
  void setCelda(char elem);  //asignar valor a elemento
  char getCelda();   //devuelve valor celda
  
};

#endif