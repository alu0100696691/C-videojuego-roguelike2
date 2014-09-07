/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: PROTAGONISTA.H
******************************************************************
*/



#ifndef _protagonista_H_
#define _protagonista_H_

#include "tablero.h"

using namespace std;



class Jugador
{
private:
  int vida;  //vida del protagonista
  int posx_jugador; //coordenadas x,y del jugador
  int posy_jugador; 
  int fuerza;  //fuerza del protagonista para defenderse de los bichos
  int beneficio; //si el protagonista consigue 3 o mas ganamos partida
public:
  Jugador();  //constructor
  int get_Vida();
  void set_Vida(int v);
  int get_posx_jugador();
  void set_posx_jugador(int x);
  int get_posy_jugador();
  void set_posy_jugador(int y);
  void set_fuerza(int);
  int get_fuerza();
  void set_beneficio(int);
  int get_beneficio();
  
};

#endif
