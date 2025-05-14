#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <memory>
#include <array>
#include "Items.h"

using namespace System::Drawing;
//using CanchaArray = std::unique_ptr<CBloque>[FILAS][COLUMNAS];
// using CanchaArray = std::array<std::array<std::unique_ptr<CBloque>, FILAS>, COLUMNAS>;
using CanchaArray = std::array<std::array<std::unique_ptr<CBloque>, COLUMNAS>, FILAS>;

class CCancha {
private:
  //int cancha[FILAS][COLUMNAS];
  //CBloque* cancha[FILAS][COLUMNAS];  
  //std::unique_ptr<CBloque> cancha[FILAS][COLUMNAS];
  CanchaArray cancha;

public:
  CCancha() {}
  void DefinirCancha();
  void Inicializar();
  void MostrarCancha();
  CanchaArray& getCancha();
  void PintarCancha(Graphics^ g, Bitmap^ bmpPiso);
  void PintarMatriz(Graphics^ g, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible);
};
