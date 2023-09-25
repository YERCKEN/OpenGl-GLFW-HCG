

#include "funciones.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


//CIRCULO

// Clase PuntoPantalla
class PuntoPantalla {
private:
    GLint x, y;

public:
    PuntoPantalla() {
        x = y = 0;
    }

    void establecerCoordenadas(GLint valorX, GLint valorY) {
        x = valorX;
        y = valorY;
    }

    GLint obtenerX() const {
        return x;
    }

    GLint obtenerY() const {
        return y;
    }

    void incrementarX() {
        x++;
    }

    void decrementarY() {
        y--;
    }
};

// Función para trazar puntos del círculo
void trazarPuntosCirculo(int xc, int yc, PuntoPantalla puntoCirculo, float r, float g, float b) {
    setPixel(xc + puntoCirculo.obtenerX(), yc + puntoCirculo.obtenerY(), r, g, b);
    setPixel(xc - puntoCirculo.obtenerX(), yc + puntoCirculo.obtenerY(), r, g, b);
    setPixel(xc + puntoCirculo.obtenerX(), yc - puntoCirculo.obtenerY(), r, g, b);
    setPixel(xc - puntoCirculo.obtenerX(), yc - puntoCirculo.obtenerY(), r, g, b);
    setPixel(xc + puntoCirculo.obtenerY(), yc + puntoCirculo.obtenerX(), r, g, b);
    setPixel(xc - puntoCirculo.obtenerY(), yc + puntoCirculo.obtenerX(), r, g, b);
    setPixel(xc + puntoCirculo.obtenerY(), yc - puntoCirculo.obtenerX(), r, g, b);
    setPixel(xc - puntoCirculo.obtenerY(), yc - puntoCirculo.obtenerX(), r, g, b);
}

// Función para trazar un círculo utilizando el algoritmo de Punto Medio
void trazarCirculoPuntoMedio(int xc, int yc, int radio, float r, float g, float b) {
    PuntoPantalla puntoCirculo;
    int p = 1 - radio;

    puntoCirculo.establecerCoordenadas(0, radio);
    trazarPuntosCirculo(xc, yc, puntoCirculo, r, g, b);

    while (puntoCirculo.obtenerX() < puntoCirculo.obtenerY()) {
        puntoCirculo.incrementarX();
        if (p < 0) {
            p += 2 * puntoCirculo.obtenerX() + 1;
        }
        else {
            puntoCirculo.decrementarY();
            p += 2 * (puntoCirculo.obtenerX() - puntoCirculo.obtenerY()) + 1;
        }
        trazarPuntosCirculo(xc, yc, puntoCirculo, r, g, b);
    }
}