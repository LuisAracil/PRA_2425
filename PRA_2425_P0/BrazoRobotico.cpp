#include "BrazoRobotico.h"
#include <iostream>

// Constructor
BrazoRobotico::BrazoRobotico(double x, double y, double z) 
	: x{x}, y{y}, z{z}, sujeto{0} {
}

// Métodos consultores
double BrazoRobotico::getX() {
       	return this->x;
}

double BrazoRobotico::getY() {
       	return this->y;
}

double BrazoRobotico::getZ() {
       	return this->z;
}

int BrazoRobotico::EstaSujeto() {
       	return this->sujeto;
}


// Métodos de comportamiento
void BrazoRobotico::coger() {
    if (this->sujeto == 0) {
        this->sujeto = 1;
        std::cout << "Objeto cogido\n";
    } else {
        std::cout << "Ya se está sujetando un objeto\n";
    }
}

void BrazoRobotico::soltar() {
    if (this->sujeto == 1) {
        this->sujeto = 0;
        std::cout << "Objeto soltado.\n";
    } else {
        std::cout << "No hay nada que soltar.\n";
    }
}

void BrazoRobotico::mover(double dx, double dy, double dz) {
    this->x += dx;
    this->y += dy;
    this->z += dz;
    std::cout << "Movido a: ("  << this->x << ", "  << this->y << ", "  << this->z << ")\n";
}

