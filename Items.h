#pragma once
#include <iostream>

#define FILAS 7
#define COLUMNAS 9
#define ANCHOIMAGEN 64
#define ALTOIMAGEN 64
#define HABILIDADES 7

enum EElementos {
  piso = 0,
  paredes,
  rrompible,
  libre,
  obstaculos,
  poder,
  jugador,
  bomba,
  enemigos
};

enum EHabilidades {
  fuego = 0,
  bombas,
  golpe,
  resistencia,
  muerte,
  velocidad,
  alto
};

class CBloque {
	int x;
	int y;
	EElementos tipo;
  std::string apariencia;
  int resistencia;
  bool habilidades[HABILIDADES];
public:
  CBloque();
  CBloque(int x, int y, EElementos tipo, std::string apariencia, int resistencia);

  void setX(int x);
  int getX();
  void setY(int y);
  int getY();
  void setTipo(EElementos tipo);
  EElementos getTipo();
  void setApariencia(std::string apariencia);  
  std::string getApariencia();
  void setResistencia(int resistencia);
  int getResistencia();  
  void adicionarHabilidad(EHabilidades habilidad);
  void quitarHabilidad(EHabilidades habilidad);
  bool getHabilidad(EHabilidades habilidad);
};
