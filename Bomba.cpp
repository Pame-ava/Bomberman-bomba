#pragma once
#include "Bomba.h"

CBomba::CBomba(int x, int y) {
	this->x = x;
	this->y = y;
	estado = EBomba::puesto;
	tiempoExplosion = 0;
	indiceX = 0;

	// para explosion
	indiceEX = 0;
	indiceEY = 0;	
}

EBomba CBomba::getEstado() {
	return estado;
}

void CBomba::animarExplosion() {
	if (indiceEX >= 0 && indiceEX < 3) {
		indiceEX++;
	}
	else {
		estado = EBomba::explotado;
	}
}

bool CBomba::verificarLugar(int jugadorX, int jugadorY, const CanchaArray& cancha) {
	if ((cancha[jugadorY / ALTOIMAGEN][jugadorX / ANCHOIMAGEN]->getTipo() == EElementos::piso) || (cancha[jugadorY / ALTOIMAGEN][jugadorX / ANCHOIMAGEN]->getTipo() == EElementos::libre)) {
		return true;
	}

	return false;
}

void CBomba::dibujar(Graphics^ g, Bitmap^ bmpBomba, int jugadorX, int jugadorY, const CanchaArray& cancha) {
	if (verificarLugar(jugadorX, jugadorY, cancha)) {
		Rectangle rectangulo = Rectangle(indiceX * ANCHOBOMBA, 0, ANCHOBOMBA, ALTOBOMBA);
		Rectangle zoom = Rectangle(x, y, ANCHOIMAGEN * 0.7, ALTOIMAGEN * 0.7);
		g->DrawImage(bmpBomba, zoom, rectangulo, GraphicsUnit::Pixel);
		if (tiempoExplosion == TIEMPOEXPLOSION) {
			estado = EBomba::explosion;
		}
	}
}

void CBomba::animar() {
	if ((indiceX >= 0) && (indiceX < 2)) {
		indiceX++;
	}
	else {
		tiempoExplosion++;
		indiceX = 0;
	}
}

void CBomba::dibujarExplosion(Graphics^ g, Bitmap^ bmpExplosion, const CanchaArray& cancha) {
	const int newAnchoImagen = ANCHOIMAGEN - 10;
	const int newAltoImagen = ANCHOIMAGEN - 10;

	Rectangle centro = Rectangle(x, y, newAnchoImagen, newAltoImagen);
	Rectangle posicionCentro = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	g->DrawImage(bmpExplosion, centro, posicionCentro, GraphicsUnit::Pixel);

	Rectangle izquierdaDerecha = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY + 2 * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	Rectangle arribaAbajo = Rectangle(indiceEX * ANCHOEXPLOSION, indiceEY + 6 * ALTOEXPLOSION, ANCHOEXPLOSION, ALTOEXPLOSION);
	
	if (cancha[y / newAltoImagen][(x - newAnchoImagen) / newAnchoImagen]->getTipo() != EElementos::paredes) {
		Rectangle izquierda = Rectangle(x - newAnchoImagen, y, newAnchoImagen, newAltoImagen);
		g->DrawImage(bmpExplosion, izquierda, izquierdaDerecha, GraphicsUnit::Pixel);
		if (cancha[y / newAltoImagen][(x - newAnchoImagen) / newAnchoImagen]->getTipo() == EElementos::rrompible) { 
				cancha[y / newAltoImagen][(x - newAnchoImagen) / newAnchoImagen]->setTipo(EElementos::libre);
		}
	}
	if (cancha[y / newAltoImagen][(x + newAnchoImagen) / newAnchoImagen]->getTipo() != EElementos::paredes) {	
		Rectangle derecha = Rectangle(x + newAnchoImagen, y, newAnchoImagen, newAltoImagen);
		g->DrawImage(bmpExplosion, derecha, izquierdaDerecha, GraphicsUnit::Pixel);
		if (cancha[y / newAltoImagen][(x + newAnchoImagen) / newAnchoImagen]->getTipo() == EElementos::rrompible) { 
			cancha[y / newAltoImagen][(x + newAnchoImagen) / newAnchoImagen]->setTipo(EElementos::libre);
		}
	}
	
	if (cancha[(y - newAltoImagen) / newAltoImagen][x / newAnchoImagen]->getTipo() != EElementos::paredes) {
		Rectangle arriba = Rectangle(x, y - newAltoImagen, newAnchoImagen, newAltoImagen);
		g->DrawImage(bmpExplosion, arriba, arribaAbajo, GraphicsUnit::Pixel);
		if (cancha[(y - newAltoImagen) / newAltoImagen][x / newAnchoImagen]->getTipo() == EElementos::rrompible) {
			cancha[(y - newAltoImagen) / newAltoImagen][x / newAnchoImagen]->setTipo(EElementos::libre);
		}
	}
	if (cancha[(y + newAltoImagen) / newAltoImagen][x / newAnchoImagen]->getTipo() != EElementos::paredes) {
		Rectangle abajo = Rectangle(x, y + newAltoImagen, newAnchoImagen, newAltoImagen);
		g->DrawImage(bmpExplosion, abajo, arribaAbajo, GraphicsUnit::Pixel);
		if (cancha[(y + newAltoImagen) / newAltoImagen][x / newAnchoImagen]->getTipo() == EElementos::rrompible) {
			cancha[(y + newAltoImagen) / newAltoImagen][x / newAnchoImagen]->setTipo(EElementos::libre);
		}
	}
}