
#include "funciones.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>




// Función para dibujar una elipse
void dibujarElipse(int xCentro, int yCentro, int Rx, int Ry, float r, float g, float b) {

    // Establecer el color de la LÍNEA
    glColor3f(r, g, b);

    // Dibujo por puntos
    glBegin(GL_POINTS);

    // VARIABLES NECESARIAS
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int dosRx2 = 2 * Rx2;
    int dosRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = dosRx2 * y;

    // Región 1
    p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py) {
        x++;
        px += dosRy2;
        if (p < 0) {
            p += Ry2 + px;
        }
        else {
            y--;
            py -= dosRx2;
            p += Ry2 + px - py;
        }

        // DIBUJA EN LOS PUNTOS CALCULADOS
        glVertex2i(xCentro + x, yCentro + y);
        glVertex2i(xCentro - x, yCentro + y);
        glVertex2i(xCentro + x, yCentro - y);
        glVertex2i(xCentro - x, yCentro - y);
    }

    // Región 2
    p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0) {
        y--;
        py -= dosRx2;
        if (p > 0) {
            p += Rx2 - py;
        }
        else {
            x++;
            px += dosRy2;
            p += Rx2 - py + px;
        }

        // DIBUJA EN LOS PUNTOS CALCULADOS
        glVertex2i(xCentro + x, yCentro + y);
        glVertex2i(xCentro - x, yCentro + y);
        glVertex2i(xCentro + x, yCentro - y);
        glVertex2i(xCentro - x, yCentro - y);
    }

    glEnd();
}

