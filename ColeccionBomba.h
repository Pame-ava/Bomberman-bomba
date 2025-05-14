#pragma once
#include <vector>
#include "Bomba.h";
#define TOTALBOMBAS 3

using namespace std;

class CColeccionBomba {
	vector<CBomba*> bombas;
	int totalBombas;

public:
	CColeccionBomba() {
		totalBombas = 1;
	}

	void crearBomba(int x, int y) {
		if (bombas.size() < totalBombas) {
			CBomba* nuevaBomba = new CBomba(x, y);
			bombas.push_back(nuevaBomba);
		}
	}

	void dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int jugadorX, int jugadorY, const CanchaArray& cancha) {
		for (int i = 0; i < bombas.size(); i++) {
			switch (bombas.at(i)->getEstado()) {
			case EBomba::puesto:
				bombas.at(i)->dibujar(g, bmpBomba, jugadorX, jugadorY, cancha);
				bombas.at(i)->animar();
				break;
			case EBomba::explosion:
				bombas.at(i)->dibujarExplosion(g, bmpExplosion, cancha);
				bombas.at(i)->animarExplosion();
				break;
			case EBomba::explotado:
				bombas.erase(bombas.begin() + i);
				break;
			}
		}
	}
};
