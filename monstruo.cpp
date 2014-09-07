/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: MONSTRUO.CPP
******************************************************************
*/



#include "monstruo.h"

Enemigo::Enemigo()  //constructor
{
  posx_enemigo = 0;
  posy_enemigo = 0;
  vivo = TRUE;
};

int Enemigo::get_posx_enemigo()
{
  return(posx_enemigo);
};

void Enemigo::set_posx_enemigo(int x)
{
  posx_enemigo = x;
};

int Enemigo::get_posy_enemigo()
{
  return(posy_enemigo);
};
  
void Enemigo::set_posy_enemigo(int y)
{
  posy_enemigo = y;
};

bool Enemigo::get_vivo()
{
  return(vivo);
};

void Enemigo::set_vivo(bool v)
{
  vivo = v;
};

void Enemigo::set_hab(int h)  //asignar la habitacion donde pertenece el bicho
{
  habitacion = h;
};

int Enemigo::get_hab()
{
  return(habitacion);
};

int Enemigo::get_fuerza()
{
  return(fuerza);
};

void Enemigo::set_fuerza(int f)
{
  fuerza = f;
};  

void Dragon::mover(int *pos1,int *pos2,int dimx,int dimy)
{    
  *pos1 = rand() % dimx + 1;  //x aleatoria	
  *pos2 = rand() % dimy + 1;  //y aleatoria
};

void Trol::mover(int *pos1,int *pos2,int dimx,int dimy)
{
  if(*pos1 == 1) //DERECHA 
    *pos2= *pos2 + 1;
  else if(*pos1 == 0) //izquierda
    *pos2= *pos2 - 1;
};

void Trol::set_sentido(bool s)
{
  sentido = s;
};
  
bool Trol::get_sentido()
{
  return(sentido);
};