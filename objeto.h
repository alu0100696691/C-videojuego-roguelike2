/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: OBJETO.H
******************************************************************
*/




#ifndef _objecto_H_
#define _objecto_H_

#include "tablero.h"

using namespace std;



class Objeto  
{
private:
  int posx_objeto;
  int posy_objeto;
  int beneficio;
  int fuerza; 
  
public:
  Objeto();  //constructor
  Objeto(int b, int f);  //constructor con argumentos
  int get_fuerza();
  int get_beneficio();  
  int get_posx();
  int get_posy();
  void set_fuerza(int);
  void set_beneficio(int);
  void set_posx(int);
  void set_posy(int);
  
  
};

class Amuleto : public Objeto  
{
public:
  Amuleto(int,int); //constructor 
};

class Pocima : public Objeto  
{
public:
  Pocima(int,int); //constructor 
};

class Espada : public Objeto  //clase Abstracta
{
public:
  Espada(int,int); //constructor 
};

#endif