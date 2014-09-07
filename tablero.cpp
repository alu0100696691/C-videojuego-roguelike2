/*
******************************************************************
PROGRAMA: Practica 2, Roguelike.
ASIGNATURA: 2º CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 15 de Marzo del 2013
FICHERO: TABLERO.CPP
******************************************************************
*/



#include "tablero.h"



using namespace std;

Tablero::Tablero()  //constructor
{
  
};

Tablero::Tablero(char *fichero)
{
  fstream fi;
  fi.open(fichero, ios::in);  //abrimos fichero para lectura
  dim_x_1=dim_y_1=pos1x=pos1y=dim_x_2=dim_y_2=pos2x=pos2y=dim_x_3=dim_y_3=pos3x=pos3y=0;  //inicializamos a cero posiciones de la habitaciones
  if (!fi)
  {
    throw "Error leyendo fichero";
    exit(1);
  } 
  
  char linea[100];  //donde guardamos los caracteres leidos por el fichero  
  int fila=0;
  int colum=0;
  
  fi.getline(linea,100,'\n');  //leemos una linea hasta salto de linea
  colum = strlen(linea);  //numero de caracteres en cada fila
  colum--;
  fila++;
  
  while(fi.getline(linea,100,'\n'))
    fila++;  //numero de filas del fichero
      
     
  alto_tablero=fila;
  ancho_tablero=colum;
  entrada_x = 0;
  entrada_y = 0;
  
  pCelda = new Celda *[fila];   //construimos la matriz
  for(int i=0;i<colum;i++)
    pCelda[i] = new Celda[colum]; 
  
  fi.clear();
  fi.seekg(0, ios::beg);  //comienzo del fichero
  fila = 0;
  
  while (fi.getline(linea,100,'\n'))  //vamos leyendo las lineas del fichero
  {
    for(int i = 0;i<colum;i++)  //vamos llenando la matriz pcelda
      pCelda[fila][i].setCelda(linea[i]);
      
    fila++;  
  }
  if(!fi.eof()) //si al terminar eof distinto de eof
	throw "Error al leer el fichero";
  
  fi.close(); //cerramos el fichero
  
  srand (time(NULL));  //semilla ramdon con el time del sistema
  habitaciones();  //obtenemos posiciones de las habitaciones
  crearProtagonista();
  crearMonstruos();
  crearObjetos();
  
  
  
};

Tablero::Tablero(int alto, int ancho)
{
  alto_tablero=alto;
  ancho_tablero=ancho;
  
  pCelda = new Celda *[alto];   //construimos la matriz
  for(int i=0;i<ancho;i++)
    pCelda[i] = new Celda[ancho];
  
  crearMazmorra();  //creamos mazmorra de forma aleatoria
  
};

void Tablero::crearMazmorra()
{
  cout << "crearMazmorra" << endl;
};

void Tablero::mostrarMazmorra()
{
  pCelda[get_entradax()][get_entraday()].setCelda('X');
  for(int i = 0;i<alto_tablero;i++)
    for(int j = 0;j<ancho_tablero;j++)
    {
      if(ancho_tablero-j == 1)  //salto de linea
	cout << endl;
      cout << pCelda[i][j].getCelda();
    }
    
     
};

void Tablero::habitaciones()  //dimensiones y posicion de las distintas habitaciones
{
  int contx=0;
  int conty=0;
  for(int i = 0;i<alto_tablero;i++) {
    for(int j = 0;j<ancho_tablero;j++)
    {
      if(pCelda[i][j].getCelda() == '*' && (pCelda[i][j+1].getCelda() == '*' || pCelda[i][j+1].getCelda() == '+')  && (pCelda[i+1][j].getCelda() == '*' || pCelda[i+1][j].getCelda() == '+') )  //esquina habitacion
      { 
	if(pos1x == 0)  //habitacin 1
	{
	pos1x = i+1;
	pos1y = j+1;
	contx=0;
	conty=0;
	
	for(int z = j; pCelda[i][z].getCelda() != ' ';z++) 
	{ //buscamos el ancho           
	  conty++;  
	  dim_y_1=conty-3;  
	}
        for(int k = i; pCelda[k][j].getCelda() != ' ';k++) 
	{ //buscamos el alto
	  contx++;
	  dim_x_1=contx-3;	  
	}
	}
	else if(pos2x == 0) //habitacion 2
	{
	  pos2x = i+1;
	  pos2y = j+1;
	  contx=0;
	  conty=0;
	  
	  for(int z = j; pCelda[i][z].getCelda() != ' ';z++)  //buscamos el ancho
          {	    
	    conty++;
	    dim_y_2=conty-3;
	  }
          for(int k = i; pCelda[k][j].getCelda() != ' ';k++)  //buscamos el alto
          {
	    contx++;
	    dim_x_2=contx-3;	    
	  }
	}
	else if(pos3x == 0) //habitacion 3
	{
	  pos3x = i+1;
	  pos3y = j+1;
	  contx=0;
	  conty=0;
	  
	  for(int z = j; pCelda[i][z].getCelda() != ' ';z++)  //buscamos el ancho
          {	    
	    conty++;
	    dim_y_3=conty-3;
	  }
	  for(int k = i; pCelda[k][j].getCelda() != ' ';k++)  //buscamos el alto
          {
	    contx++;
	    dim_x_3=contx-3;	    
	  }
	  
	}
      }
    }
  }
  
};

void Tablero::crearProtagonista()
{
  pProtagonista = new Jugador();  //puntero apunta a objeto de la clase jugador
  for(int i = 0;i<alto_tablero;i++) {
    for(int j = 0;j<ancho_tablero;j++)
    {
      if(pCelda[i][j].getCelda() == 'X')  //ponemos el protagonista en la puerta de entrada
      {
	entrada(i,j);  //coordenadas de la entrada-salida del juego
	pCelda[i][j].setCelda('@');
	pProtagonista->set_posx_jugador(i); //coordenadas x,y del jugador
	pProtagonista->set_posy_jugador(j);
      }
    }
  }
};

void Tablero::crearObjetos()
{
  pAmuleto = new Amuleto(3,0); // punteros apuntan a objetos
  pEspada = new Espada(0,10);
  for(int j = 0;j<3;j++)
    pPocima[j] = new Pocima(1,5);  
  int cont=0;
  int pos1 = 0;
  int pos2 = 0;
  int hab = 0;  //variable numero de habitacion
  char objeto[] = {'A','P','E','P','P'};  //array con los distintos objetos a pintar amuleto, pocima y espada
  
  for(int j = 0;j<5;j++)
      {
	hab = rand() % 3 + 1;  //habitacion aleatoria donde meter el objeto
	if(j == 0)  //si vamos a pintar el amuleto lo pintamos en habitacion 3
	  hab = 3;
	pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
	pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria
	while( (pCelda[pos1+get_pos(hab, 'x')][pos2+get_pos(hab, 'y')].getCelda() ) != ' ')  //mientras no encontremos una celda vacia no metemos el bicho
	{
	  pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
	  pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria	  
	}	  
	switch(j)
	{
	  case 0:
	    pAmuleto->set_posx(pos1+get_pos(hab, 'x'));
	    pAmuleto->set_posy(pos2+get_pos(hab, 'y'));
	    break;
	  case 1:
	    pEspada->set_posx(pos1+get_pos(hab, 'x'));
	    pEspada->set_posy(pos2+get_pos(hab, 'y'));
	    break;
	  default:
	    pPocima[cont]->set_posx(pos1+get_pos(hab, 'x'));
	    pPocima[cont]->set_posy(pos2+get_pos(hab, 'y'));
	    cont++;
	    break;
	}
	pCelda[pos1+get_pos(hab, 'x')][pos2+get_pos(hab, 'y')].setCelda(objeto[j]);  //pintamos el objeto
      }
};
      
  
  
  
  

void Tablero::crearMonstruos()
{
  pDragon = new Dragon[9];  //nueve dragones
  pTrol = new Trol[3];  //tres troll
  int pos1 = 0;
  int pos2 = 0;
  int cont = 0;  //variable contador de monstruos
  int hab = 1;  //variable contador de habitacion
  //colocamos los monstruos de forma aleatoria por las habitaciones
  
    for(int i = 0;i<3;i++)
    { 
      for(int j = 0;j<3;j++)
      {
	pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
	pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria
	while( (pCelda[pos1+get_pos(hab, 'x')][pos2+get_pos(hab, 'y')].getCelda() ) != ' ')  //mientras no encontremos una celda vacia no metemos el bicho
	{
	  pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
	  pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria	  
	}	  
	pDragon[cont].set_posx_enemigo(pos1+get_pos(hab, 'x'));
	pDragon[cont].set_posy_enemigo(pos2+get_pos(hab, 'y'));
	pDragon[cont].set_hab(hab);  //asignamos el monstruo a una habitacion
	pCelda[pDragon[cont].get_posx_enemigo()][pDragon[cont].get_posy_enemigo()].setCelda('D');  //pintamos el bicho
	cont++;  //siguiente monstruo
      }
      hab++;  //siguiente habitacion
    }
  //creamos los troll
  hab = 1;
  pos1 = pos2 = 0;
  
  for(int i = 0;i<9;i++)  //FUERZA 20 todos los dragones
  {
    pDragon[i].set_fuerza(20);
  }
  
  for(int i = 0;i<3;i++)  //TODOS LOS TROL EN PRINCIPIO SE MOVERAN A LA DERECHA Y FUERZA 10 
  {
    pTrol[i].set_sentido(TRUE);
    pTrol[i].set_fuerza(10);
  }
  
  for(int i = 0;i<3;i++) //tres troll
  {
    pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
    pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria
    while( (pCelda[pos1+get_pos(hab, 'x')][pos2+get_pos(hab, 'y')].getCelda() ) != ' ')  //mientras no encontremos una celda vacia no metemos el bicho
    {
      pos1 = rand() % get_dim(hab, 'x') + 1;  //x aleatoria	
      pos2 = rand() % get_dim(hab, 'y') + 1;  //y aleatoria	  
    }	  
    pTrol[i].set_posx_enemigo(pos1+get_pos(hab, 'x'));
    pTrol[i].set_posy_enemigo(pos2+get_pos(hab, 'y'));
    pTrol[i].set_hab(hab);  //asignamos el monstruo a una habitacion
    pCelda[pTrol[i].get_posx_enemigo()][pTrol[i].get_posy_enemigo()].setCelda('T');  //pintamos el bicho
    hab++;
  }
    
    
   
   
};
  
void Tablero::moverMonstruos()  //mover monstruos
{
  int pos1;
  int pos2 = 0;
  int cont = 0;  //variable contador de monstruos
  int hab = 1;  //variable contador de habitacion
  //colocamos los monstruos de forma aleatoria por las habitaciones
  
  for(int i = 0;i<9;i++)
    pCelda[pDragon[i].get_posx_enemigo()][pDragon[i].get_posy_enemigo()].setCelda(' '); //borramos los bichos de la antigua posicion
  
    for(int i = 0;i<3;i++)
    { 
      for(int j = 0;j<3;j++)
      {
	pDragon->mover(&pos1,&pos2,get_dim(hab, 'x'),get_dim(hab, 'y'));
	
	while( (pCelda[pos1+get_pos(hab, 'x')][pos2+get_pos(hab, 'y')].getCelda() ) != ' ')  //mientras no encontremos una celda vacia no metemos el bicho
	{
	  pDragon->mover(&pos1,&pos2,get_dim(hab, 'x'),get_dim(hab, 'y'));	  
	}	  
	pDragon[cont].set_posx_enemigo(pos1+get_pos(hab, 'x'));
	pDragon[cont].set_posy_enemigo(pos2+get_pos(hab, 'y'));
	if(pDragon[cont].get_vivo() == TRUE)
	  pCelda[pDragon[cont].get_posx_enemigo()][pDragon[cont].get_posy_enemigo()].setCelda('D');  //pintamos el bicho
	cont++;  //siguiente monstruo
      }
      hab++;  //siguiente habitacion
    }  
    
  //movemos los troll
  for(int i = 0;i<3;i++)
  {
    pCelda[pTrol[i].get_posx_enemigo()][pTrol[i].get_posy_enemigo()].setCelda(' '); //borramos los Trol de la antigua posicion
  }
    
    
  for(int i = 0;i<3;i++)
  {
    pos2 = pTrol[i].get_posy_enemigo(); 
    if(pCelda[pTrol[i].get_posx_enemigo()][pos2+1].getCelda() == ' ' && pTrol[i].get_sentido() == TRUE )
     {
       pos1=1;
       pTrol[i].mover(&pos1,&pos2,0,0); 
       pTrol[i].set_posy_enemigo(pos2);
     }
     else if(pCelda[pTrol[i].get_posx_enemigo()][pos2+1].getCelda() == '*' || pCelda[pTrol[i].get_posx_enemigo()][pos2+1].getCelda() == '+')
     {
	pTrol[i].set_sentido(FALSE);
	pos1 = 0;
	pTrol[i].mover(&pos1,&pos2,0,0); 
	pTrol[i].set_posy_enemigo(pos2);
     }
     else if(pCelda[pTrol[i].get_posx_enemigo()][pos2-1].getCelda() == ' ' && pTrol[i].get_sentido() == FALSE)
     {       
       pos1 = 0;
       pTrol[i].mover(&pos1,&pos2,0,0);  
       pTrol[i].set_posy_enemigo(pos2);
     }
     else if(pCelda[pTrol[i].get_posx_enemigo()][pos2-1].getCelda() == '*' || pCelda[pTrol[i].get_posx_enemigo()][pos2-1].getCelda() == '+')
     {
	pTrol[i].set_sentido(TRUE);
	pos1 = 1;
	pTrol[i].mover(&pos1,&pos2,0,0); 
	pTrol[i].set_posy_enemigo(pos2);
     }
   if(pTrol[i].get_vivo() == TRUE)
    pCelda[pTrol[i].get_posx_enemigo()][pTrol[i].get_posy_enemigo()].setCelda('T');  
    
  }  
};
  
int Tablero::getAlto_tablero()
{
  return(alto_tablero);
};

int Tablero::getAncho_tablero()
{
  return(ancho_tablero);
};

int Tablero::get_pos(int h, char c)   //devuelve posx de la habitacion h coordenada x,y
{
  if(c == 'x')  // pos de x
  {
    switch(h)
    {
      case 1:
	return(pos1x);
	break;
      case 2:
	return(pos2x);
	break;
      case 3:
	return(pos3x);
	break;
    }
  }
  else if(c == 'y')
  {
    switch(h)
    {
      case 1:
	return(pos1y);
	break;
      case 2:
	return(pos2y);
	break;
      case 3:
	return(pos3y);
	break;
    }
  }
};
	
int Tablero::get_dim(int h, char c) 	//devuelve dimensiones habitacion h coordenada x,y  
{
  if(c == 'x')  // pos de x
  {
    switch(h)
    {
      case 1:
	return(dim_x_1);
	break;
      case 2:
	return(dim_x_2);
	break;
      case 3:
	return(dim_x_3);
	break;
    }
  }
  else if(c == 'y')
  {
    switch(h)
    {
      case 1:
	return(dim_y_1);
	break;
      case 2:
	return(dim_y_2);
	break;
      case 3:
	return(dim_y_3);
	break;
    }
  }
};

int Tablero::getch(void)
{
  
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
    
};

void Tablero::ciclo()
{
  int tecl;
  tecl = getch();
  
 
    switch(tecl)
    {
      case 'w':
	tecla('w');
	break;       
      case 's':
	tecla('s');
	break;
      case 'a':
	tecla('a');  
	break;
      case 'd':
	tecla('d');
	break;
	
    }
  moverMonstruos();   //actualizamos posicion  
  quita_vidas();   //funcion que quita vidas al protagonista si hay un bicho cerca
  
  
};

void Tablero::tecla(char tecla)
{
  char simbolo;
  int x = pProtagonista->get_posx_jugador();
  int y = pProtagonista->get_posy_jugador();
  int antx,anty;  //variables para guardar posiciones "x, y" anteriores
  antx = x;
  anty = y;
  char norte,sur, este, oeste;   //donde guardamos lo que hay alrededor de la posicion del protagonista
  norte = pCelda[x-1][y].getCelda();
  sur = pCelda[x+1][y].getCelda();
  este = pCelda[x][y+1].getCelda();
  oeste = pCelda[x][y-1].getCelda();
  
  switch(tecla)
  {
      case 'w':
	simbolo = pCelda[x-1][y].getCelda();	
	antx = x;
	anty = y;	
	x--;	
	break;
      case 's':
	simbolo = pCelda[x+1][y].getCelda();
	antx = x;
	anty = y;
	simbolo = pCelda[x+1][y].getCelda();
	x++;
	break;
	case 'd':
	simbolo = pCelda[x][y+1].getCelda();
	antx = x;
	anty = y;
	y++; 
	break;
	case 'a':
	simbolo = pCelda[x][y-1].getCelda();
	antx = x;
	anty = y;	
	y--;
	break;
  }
  
  switch(simbolo)
  {
    case 'X':
      pCelda[x][y].setCelda('@');
      pCelda[antx][anty].setCelda(' ');   
      break;
    case 'A':
      pCelda[x][y].setCelda('@');
      pCelda[antx][anty].setCelda(' ');
      pProtagonista->set_beneficio(pProtagonista->get_beneficio()+pAmuleto->get_beneficio());  //sumamos el beneficio al protagonista
      pProtagonista->set_fuerza(pProtagonista->get_fuerza()+pAmuleto->get_fuerza());  //sumamos la fuerza al protagonista
      pAmuleto->set_posx(0);
      pAmuleto->set_posy(0);
      break;
    case 'P':
      pCelda[x][y].setCelda('@');
      pCelda[antx][anty].setCelda(' ');
      pProtagonista->set_beneficio(pProtagonista->get_beneficio()+pPocima[0]->get_beneficio());  //sumamos el beneficio al protagonista
      pProtagonista->set_fuerza(pProtagonista->get_fuerza()+pPocima[0]->get_fuerza());  //sumamos la fuerza al protagonista
      break;
    case 'E':
      pCelda[x][y].setCelda('@');
      pCelda[antx][anty].setCelda(' ');
      pProtagonista->set_beneficio(pProtagonista->get_beneficio()+pEspada->get_beneficio());  //sumamos el beneficio al protagonista
      pProtagonista->set_fuerza(pProtagonista->get_fuerza()+pEspada->get_fuerza());  //sumamos la fuerza al protagonista
      pEspada->set_posx(0);
      pEspada->set_posy(0);
      break;
    case 'T':
      x = antx;
      y = anty;
      break;
    case 'D':
      x = antx;
      y = anty;
      break;
    case '*':
      x = antx;
      y = anty;
      break;
    case ' ':
      if( (norte == '#' || sur == '#' || este == '#' || oeste == '#') &&  //final de un pasillo
                                          (norte == '*' || sur == '*' || este == '*' || oeste == '*')  )
	{
	  pCelda[x][y].setCelda('@');
          pCelda[antx][anty].setCelda('+');         
	} 
      else if(norte != '#' && sur != '#' && este != '#' && oeste != '#')  //no estamos en un pasillo
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda(' ');  
	
      }
      else   //estamos en un pasillo 
      {
	x = antx;  
	y = anty;
      }
	
      break;
    case '+':
      if(norte == '#' || sur == '#' || este == '#' || oeste == '#')
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda('#');
      }
      else
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda(' ');
      }
      break;
    case '#':
      if( (norte == '#' && sur != ' ') || (sur == '#' && norte != ' ') || (este == '#' && oeste != ' ') || (oeste == '#' && este != ' ') )
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda('#'); 
      }
      else if( (norte == '#' && sur == ' ' && este != '#' && oeste != '#') || (sur == '#' && norte == ' ' && este != '#' && oeste != '#')
	|| (este == '#' && oeste == ' ' && norte != '#' && sur != '#') || (oeste == '#' && este == ' ' && norte != '#' && sur != '#')   )
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda('+'); 
      }
      else
      {
	pCelda[x][y].setCelda('@');
	pCelda[antx][anty].setCelda('#');
      }
	
      break;
  }
   pProtagonista->set_posx_jugador(x);  //nueva posicion del protagonista
   pProtagonista->set_posy_jugador(y);  
   pCelda[x][y].setCelda('@');
         
};  
	  

void Tablero::quita_vidas()
{
  int vidas = 0;
  vidas = pProtagonista->get_Vida();
  //Dragones
  if((pCelda[pProtagonista->get_posx_jugador()-1][pProtagonista->get_posy_jugador()].getCelda()) == 'D' )  //norte 
  {  
      
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()-1) == pDragon[i].get_posx_enemigo() && pProtagonista->get_posy_jugador() == pDragon[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pDragon[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	      pCelda[pDragon[i].get_posx_enemigo()][pDragon[i].get_posy_enemigo()].setCelda(' ');  //limpiamos el monstruo
	      mata_monstruo(i,0);
	    }
	  }
	}
  }
  else if((pCelda[pProtagonista->get_posx_jugador()+1][pProtagonista->get_posy_jugador()].getCelda()) == 'D' )  //sur
  {
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()+1) == pDragon[i].get_posx_enemigo() && pProtagonista->get_posy_jugador() == pDragon[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pDragon[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	      pCelda[pDragon[i].get_posx_enemigo()][pDragon[i].get_posy_enemigo()].setCelda(' ');  //limpiamos el monstruo
	      mata_monstruo(i,0);	      
	    }	      
	  }
	}
  }
  else if((pCelda[pProtagonista->get_posx_jugador()][pProtagonista->get_posy_jugador()+1].getCelda()) == 'D' )  //este
  {
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()) == pDragon[i].get_posx_enemigo() && pProtagonista->get_posy_jugador()+1 == pDragon[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pDragon[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	      pCelda[pDragon[i].get_posx_enemigo()][pDragon[i].get_posy_enemigo()].setCelda(' '); //limpiamos el monstruo
	      mata_monstruo(i,0);	      
	    }
	  }
	}
  }
  else if((pCelda[pProtagonista->get_posx_jugador()][pProtagonista->get_posy_jugador()-1].getCelda()) == 'D' )   //oeste
  {
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()) == pDragon[i].get_posx_enemigo() && pProtagonista->get_posy_jugador()-1 == pDragon[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pDragon[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	      pCelda[pDragon[i].get_posx_enemigo()][pDragon[i].get_posy_enemigo()].setCelda(' ');  //limpiamos el monstruo
	      mata_monstruo(i,0);	      
	    }
	  }
	}
	
  }
//Trol
if((pCelda[pProtagonista->get_posx_jugador()-1][pProtagonista->get_posy_jugador()].getCelda()) == 'T' )  //norte 
  {  
      
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()-1) == pTrol[i].get_posx_enemigo() && pProtagonista->get_posy_jugador() == pTrol[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pTrol[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	      pCelda[pTrol[i].get_posx_enemigo()][pTrol[i].get_posy_enemigo()].setCelda(' ');  //limpiamos el monstruo
	      mata_monstruo(i,1);
	    }
	  }
	}
  }
  else if((pCelda[pProtagonista->get_posx_jugador()+1][pProtagonista->get_posy_jugador()].getCelda()) == 'T' )  //sur
  {
      for(int i = 0;i<9;i++)
	{  //ahora buscamos al monstruo
	  if( (pProtagonista->get_posx_jugador()+1) == pTrol[i].get_posx_enemigo() && pProtagonista->get_posy_jugador() == pTrol[i].get_posy_enemigo())
	  {
	    if(pProtagonista->get_fuerza() < pTrol[i].get_fuerza())
	      pProtagonista->set_Vida(vidas-1); 
	    else
	    {
	       pCelda[pTrol[i].get_posx_enemigo()][pTrol[i].get_posy_enemigo()].setCelda(' ');  //limpiamos el monstruo
	      mata_monstruo(i,1);
	    }
	  }
	}
  }

}; 

void Tablero::mata_monstruo(int i,int bicho)
{
  if(bicho == 0) //dragon
  {
    pDragon[i].set_vivo(FALSE);
    pDragon[i].set_posx_enemigo(0);
    pDragon[i].set_posy_enemigo(0);
  }
  else if(bicho == 1)  //trol
  {
    pTrol[i].set_vivo(FALSE);
    pTrol[i].set_posx_enemigo(0);
    pTrol[i].set_posy_enemigo(0);
  }
};

int Tablero::vidas()
{
  return(pProtagonista->get_Vida());
};

void Tablero::entrada(int x,int y)
{
  entrada_x = x;
  entrada_y = y;
};

int Tablero::get_entradax()
{
  return(entrada_x);
};
int Tablero::get_entraday()
{
  return(entrada_y);
};

Tablero::~Tablero()
{
  for(int i=0;i<ancho_tablero;i++)
    delete[] pCelda[i];
  delete[] pCelda;
  delete pProtagonista;
  delete[] pDragon;
  delete[] pTrol;
  delete pEspada;
  delete pAmuleto;
  
  
};




  