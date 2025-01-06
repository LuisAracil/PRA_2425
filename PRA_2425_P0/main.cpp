
#include <iostream>
#include "BrazoRobotico.h"

int main() {
    // Le damos las coordenadas iniciales al brazo
    BrazoRobotico brazo(1, 2, 3);
    std::cout << "Coordenadas actuales: (" << brazo.getX() << ", " << brazo.getY() << ", " << brazo.getZ() << ")\n";

    // Desplazamos al brazo 6 unidades en x, 5 en y, 10 en z
    brazo.mover(6, 5, -10);
    
    // COgemos un objeto
    brazo.coger();
    
    // Mostramos la informacion por pantalla
    std::cout << "Coordenadas actuales: (" << brazo.getX() << ", " << brazo.getY() << ", " << brazo.getZ() << ")\n";
    std::cout << "Sujetando objeto: " << (brazo.EstaSujeto() == 1 ? "Sí" : "No") << "\n";
    
    // Soltar el objeto
    brazo.soltar();
    std::cout << "Sujetando objeto: " << (brazo.EstaSujeto() == 1 ? "Sí" : "No") << "\n";


    return 0;
}

