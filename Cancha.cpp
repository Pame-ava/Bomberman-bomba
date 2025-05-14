#include "Cancha.h"

void CCancha::DefinirCancha() {
  std::cout << "Definiendo la cancha\n";
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      //cancha[i][j] = new CBloque(i, j, EElementos::piso, "bloque1.png", 99);
      cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::piso, "bloque1.png", 99);
    }
  }
}

void CCancha::Inicializar() {
  std::cout << "Inicializando las paredes \n";
  srand(time(NULL()));

  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      if ((i == 0) || (j == 0) || (i == FILAS - 1) || (j == COLUMNAS - 1)) {
        cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::paredes, "bloque1.png", 99);
      } else {
        if (((i % 2) == 0) && ((j % 2) == 0)) {
          cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::paredes, "bloque1.png", 99);
        } else {
          if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) ||
            (i == FILAS - 2 && j == COLUMNAS - 2) ||
            (i == FILAS - 3 && j == COLUMNAS - 2) ||
            (i == FILAS - 2 && j == COLUMNAS - 3)) {
            cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::piso, "piso1.png", 0);
          } else {
            int valor = rand() % 2 + 2;
            switch (valor) {
            case 2:
              cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::rrompible, "rrompible1.png", 1);
              break;
            case 3:
              cancha[i][j] = std::make_unique<CBloque>(i, j, EElementos::libre, "piso1.png", 0);
              break;
            }
          }
        }
      }
    }
  }
}

void CCancha::MostrarCancha() {
  std::cout << "Cancha: \n";
  for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
      std::cout << cancha[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}

CanchaArray& CCancha::getCancha() {
  return cancha;
}

void CCancha::PintarCancha(Graphics^ g, Bitmap^ bmpPiso) {
  int X = 0, Y = 0;
  for (int i = 0; i < FILAS; i++) {
    X = 0;
    for (int j = 0; j < COLUMNAS; j++) {
      if (cancha[i][j]->getTipo() == EElementos::piso || cancha[i][j]->getTipo() == EElementos::libre) {
        g->DrawImage(bmpPiso, X, Y, ANCHOIMAGEN, ALTOIMAGEN);
      }
      X += ANCHOIMAGEN;
    }
    Y += ALTOIMAGEN;
  }
}

void CCancha::PintarMatriz(Graphics^ g, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible) {
  int X = 0, Y = 0;
  for (int i = 0; i < FILAS; i++) {
    X = 0;
    for (int j = 0; j < COLUMNAS; j++) {
      if (cancha[i][j]->getTipo() == EElementos::paredes) {
        g->DrawImage(bmpIrrompible, X, Y, ANCHOIMAGEN, ALTOIMAGEN);
      }
      if (cancha[i][j]->getTipo() == EElementos::rrompible) {
        g->DrawImage(bmpRrompible, X, Y, ANCHOIMAGEN, ALTOIMAGEN);
      }
      X += ANCHOIMAGEN;
    }
    Y += ALTOIMAGEN;
  }
}