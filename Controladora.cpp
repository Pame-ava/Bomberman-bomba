#include "Controladora.h"
#include "Jugador.h"

CControladora::CControladora() {
	cancha = new CCancha();
	jugador = new CJugador(ANCHOIMAGEN, ALTOIMAGEN);
	bombas = new CColeccionBomba();
}

void CControladora::inicializar() {
	cancha->Inicializar();
}

void CControladora::Dibujar() {
	cancha->Inicializar();
};
void CControladora::dibujarCancha(Graphics^ g, Bitmap^ bmpPiso, Bitmap^ bmpIrrompible, Bitmap^ bmpRrompible) {
	cancha->PintarCancha(g, bmpPiso);
	cancha->PintarMatriz(g, bmpIrrompible, bmpRrompible);
};

void CControladora::dibujarJugador(Graphics^ g, Bitmap^ bmpJugador) {
	jugador->dibujar(g, bmpJugador, cancha->getCancha());
}

void CControladora::adicionarBomba() {
	bombas->crearBomba(jugador->getX(), jugador->getY());
}

void CControladora::moverJugador(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion) {
	jugador->mover(g, bmpJugador, cancha->getCancha());
	bombas->dibujarBomba(g, bmpBomba, bmpExplosion, jugador->getX(), jugador->getY(), cancha->getCancha());
}

CJugador* CControladora::getJugador() {
	return jugador;
}
