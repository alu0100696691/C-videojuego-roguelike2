/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: OBJETO.CPP
******************************************************************
*/



#include "objeto.h"

Objeto::Objeto()  //constructor
{
  posx_objeto = 0;
  posy_objeto = 0;
  beneficio = 0;
  fuerza = 0;
};

Objeto::Objeto(int b, int f)
{
  posx_objeto = 0;
  posy_objeto = 0;
  beneficio = b;
  fuerza = f;
};

Amuleto::Amuleto(int b=3,int f=0) : Objeto(b,f) {};  //definicion del contructor de la clase derivada
Pocima::Pocima(int b=1,int f=5) : Objeto(b,f) {};  //definicion del contructor de la clase derivada
Espada::Espada(int b=0,int f=10) : Objeto(b,f) {};  //definicion del contructor de la clase derivada

int Objeto::get_fuerza()
{
  return(fuerza);
};

int Objeto::get_beneficio()
{
  return(beneficio);
};

void Objeto::set_fuerza(int f)
{
  fuerza = f;
};

void Objeto::set_beneficio(int b)
{
  beneficio = b;
};

int Objeto::get_posx()
{
  return(posx_objeto);
};

int Objeto::get_posy()
{
  return(posy_objeto);
};

void Objeto::set_posx(int x)
{
  posx_objeto = x;
};

void Objeto::set_posy(int y)
{
  posy_objeto = y;
};

