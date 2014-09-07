/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: PROTAGONISTA.CPP
******************************************************************
*/




#include "protagonista.h"


Jugador::Jugador()
{
  vida = 5;
  posx_jugador=0; //coordenadas x,y del jugador
  posy_jugador=0; 
  beneficio = 0;
  fuerza = 5;
  
};

int Jugador::get_Vida()
{
  return(vida);
};

void Jugador::set_Vida(int v)
{
  vida = v;
};

int Jugador::get_posx_jugador()
{
  return(posx_jugador);
};

void Jugador::set_posx_jugador(int x)
{
  posx_jugador = x;
};

int Jugador::get_posy_jugador()
{
  return(posy_jugador);
};

void Jugador::set_posy_jugador(int y)
{
  posy_jugador = y;
};

void Jugador::set_fuerza(int f)
{
  fuerza = f;
};
  
int Jugador::get_fuerza()
{
  return(fuerza);
};

void Jugador::set_beneficio(int b)
{
  beneficio = b;
};

int Jugador::get_beneficio()
{
  return(beneficio);
};



	