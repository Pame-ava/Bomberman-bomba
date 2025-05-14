#include "Items.h"

CBloque::CBloque() {
}

CBloque::CBloque(int x, int y, EElementos tipo, std::string apariencia, int resistencia) {
	this->x = x;
	this->y = y;
	this->tipo = tipo;
	this->apariencia = apariencia;
	this->resistencia = resistencia;
	for (int i = 0; i < HABILIDADES; i++) {
		habilidades[i] = false;
	}
}

void CBloque::setX(int x) {
	this->x = x;
}

int CBloque::getX() {
	return x;
}

void CBloque::setY(int y) {
	this->y = y;
}

int CBloque::getY() {
	return y;
}

void CBloque::setTipo(EElementos tipo) {
	this->tipo = tipo;
}

EElementos CBloque::getTipo() {
	return tipo;
}

void CBloque::setApariencia(std::string apariencia) {
	this->apariencia = apariencia;
}

std::string CBloque::getApariencia() {
	return apariencia;
}

void CBloque::setResistencia(int resistencia) {
	this->resistencia = resistencia;
}
int CBloque::getResistencia() {
	return resistencia;
}

void CBloque::adicionarHabilidad(EHabilidades habilidad) {
	this->habilidades[habilidad] = true;
}

void CBloque::quitarHabilidad(EHabilidades habilidad) {
	this->habilidades[habilidad] = false;
}

bool CBloque::getHabilidad(EHabilidades habilidad){
	return habilidades[habilidad];
}