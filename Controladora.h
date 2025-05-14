#pragma once
#include "Cancha.h"
#include "Jugador.h"
#include "ColeccionBomba.h"

class CControladora {
private:
	CCancha* cancha;
	CJugador* jugador;
	CColeccionBomba* bombas;

public:
	CControladora();
	~CControladora() {};

	void inicializar();
	void Dibujar();
	void dibujarCancha(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible);
	void dibujarJugador(Graphics^ g, Bitmap^ bmpJugador);
	void adicionarBomba();
	void moverJugador(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion);
	CJugador* getJugador();
};
