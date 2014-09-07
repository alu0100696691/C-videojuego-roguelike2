/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2� CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: ROGUELIKE.CPP
******************************************************************
*/



#include "tablero.h"

int main()
{
  char fichero[] = "Mazmorra_30_30.dat";
  char tecla;
  int ganar = FALSE;  
  
  
  
  
  
  
  
  
  
  system("clear");
    cout<<"                         *                *                   *     "<<endl;
    cout<<"             *                                     *                "<<endl;
    cout<<"     *              |           *             *        *         *  "<<endl;
    cout<<"          *        -+-                 *                            "<<endl;
    cout<<"       __           |      *             *          *        *      "<<endl;
    cout<<"   ___|  |   *     _|_              *    ____    ____               "<<endl;
    cout<<"   [_]|같|__      _| |_        *    |   |....|  |....|    *     *   "<<endl;     
    cout<<"      |     |   _|[] []|_    ___    |   |....|  | ___|__            "<<endl;
    cout<<"   [_]|  같 |__|_  ______|  |   |  |_|  |....|  || -- - |   *     * "<<endl;
    cout<<"      |________  |__     |  |# #|  |_|  |....|  || - -- |  _____    "<<endl;
    cout<<"   [_]| _____ |     |__[]|  |   |  |_|  |....|__|| -- - | |* * *|   "<<endl;
    cout<<"      | [___] |        |__  |# #|  |_|  |....|__|| -- -_|_|* * *|   "<<endl;
    cout<<"   [_]|       | 같        | |   |__| |__|....|  || ___|* *|* * *|   "<<endl;
    cout<<"      | _____ |           |__  #|_______|....|  | |* *|* *|* * *|   "<<endl;    
    cout<<"   [_]| [___] |       같     |__|_______|__  |  | |* *|* *|* * *|   "<<endl;
    cout<<"      |       |            __|_____________|__    |* *|* *|* * *|   "<<endl;
    cout<<"   [_]| _____ |  같      _|___________________|_  |* *|* *|* * *|   "<<endl;
    cout<<"      | [___] |         |_______________________|  ______________   "<<endl;
    cout<<"    __|_______|_________|_______________________| _________________ "<<endl;
    cout<<"   |_______________________________________________________________|"<<endl;
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"   ||||||||||||||||||||ROGUELIKE||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"   ||||||||||||PRACTICA 2 ALGORITMOS AVANZADOS||||||||||||||||||||||"<<endl;
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"   |||||||||Creado por: Jose Antonio Rodriguez leandro||||||||||||||"<<endl;
    cout<<"   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    
         
  cout << "\n\nFichero de donde se lee la mazmorra: " << fichero << endl;
  cout << "Pulse una tecla para continuar o X para cambiar nombre.\n";
  cin >> tecla;
  
  
  if(tecla == 'x' || tecla == 'X')
  {
    cout << "\nFICHERO: ";
    cin >> fichero;
  }
  
  
  Tablero mazmorra(fichero);
  
  system("clear");
     
  while(mazmorra.vidas() > 0)
  {
  cout << "VIDAS: " << mazmorra.vidas();
  cout << "  BENEFICIO: " << mazmorra.pProtagonista->get_beneficio();
  cout << "  FUERZA: " << mazmorra.pProtagonista->get_fuerza();
  mazmorra.mostrarMazmorra();
  mazmorra.ciclo();
  system("clear");
  if(mazmorra.pProtagonista->get_posx_jugador() == mazmorra.get_entradax() && mazmorra.pProtagonista->get_posy_jugador() == mazmorra.get_entraday()
     && mazmorra.pProtagonista->get_beneficio() >= 3)
  {
    ganar = TRUE;
    break;
  }
  
  }
  
  if(ganar == TRUE)
    cout << "\n\nganastes\n\n";
  else
    cout << "\n\nperdiste\n\n";
  
  return 0;
};
