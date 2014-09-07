/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: MONSTRUO.H
******************************************************************
*/



#ifndef _monstruo_H_
#define _monstruo_H_

#include "tablero.h"

using namespace std;



class Enemigo
{
private:
  int posx_enemigo; //coordenadas x,y del enemigo
  int posy_enemigo;
  bool vivo;  //esta vivo o muerto
  int habitacion;  //habitacion al que pertenece
  int fuerza;  //fuerza del monstruo
public:
  Enemigo();  //constructor
  int get_posx_enemigo();
  void set_posx_enemigo(int x);
  int get_posy_enemigo();
  void set_posy_enemigo(int y);
  bool get_vivo();
  void set_vivo(bool v);
  void set_hab(int);  //asignar la habitacion donde pertenece el bicho
  int get_hab();
  int get_fuerza();
  void set_fuerza(int);
  virtual void mover(int*,int*,int,int) {};   //metodo virtual
  ~Enemigo() {}
};

class Dragon : public Enemigo  //clase derivada de enemigo
{
public:
  Dragon() : Enemigo() {}  //constructor
  virtual void mover(int*,int*,int,int);  //posx,posy, dimx,dimy
};

class Trol : public Enemigo  //clase derivada
{
private:
  bool sentido;  //el sentido del trol, derecha 1 o izquierda 0
public:
  Trol() : Enemigo() {}
  virtual void mover(int*,int*,int,int);  //posx,posy, dimx,dimy
  void set_sentido(bool);
  bool get_sentido();
};

#endif