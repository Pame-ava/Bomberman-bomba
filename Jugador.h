#pragma once
#include <iostream>
#include "Cancha.h"

#define HABILIDADES 7
#define ANCHOJUGADOR 70
#define ALTOJUGADOR 128
#define FACTORZOOM 0.4

using namespace System::Drawing;

enum EDireccion {
	Ninguna = 0,
	Abajo,
	Arriba,
	Izquierda,
	Derecha
};

class CJugador {
	int x;		// posicion en el eje X
	int y;		// posicion en el eje y
	int dx;	// desplazamiento en x
	int dy;	// desplazamiento en y
	int indiceX;
	int indiceY;
	EDireccion ultimaTecla;
	EDireccion direccion;
	Rectangle limiteArribaAbajo;
	Rectangle limiteDerechaIzquierda;
	bool habilidades[HABILIDADES];
public:
	CJugador();
	~CJugador();
	
	CJugador(int x, int y);
	void setDx(int dx) {
		this->dx = dx;
	}
	void setDy(int dy) {
		this->dy = dy;
	}
	int getX() {
		return x + 1 * FACTORZOOM;
	}
	int getY() {
		return y + 20 * FACTORZOOM + dy;
	}
	void dibujar(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha);
	void mover(Graphics^ g, Bitmap^ bmpJugador, const CanchaArray& cancha);
	void setDireccion(EDireccion direccion);
	void controlarLimitesMovimiento(const CanchaArray& cancha);
};
