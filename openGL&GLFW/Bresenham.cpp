


#include "funciones.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


//ALGORITMO BRESENHAM
void lineaBresenham(int x0, int y0, int xEnd, int yEnd, float r, float g, float b) {
    int dx = abs(xEnd - x0);
    int dy = abs(yEnd - y0);
    int x, y;
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    // Determinar dirección de incremento en x y y
    int xIncrement = (xEnd > x0) ? 1 : -1;
    int yIncrement = (yEnd > y0) ? 1 : -1;

    if (dx == 0) {
        // Línea vertical
        for (y = y0; y != yEnd; y += yIncrement) {
            setPixel(x0, y, r, g, b);
        }
    }
    else if (dy == 0) {
        // Línea horizontal
        for (x = x0; x != xEnd; x += xIncrement) {
            setPixel(x, y0, r, g, b);
        }
    }
    else if (dx > dy) {
        // Línea con pendiente < 45 grados
        p = twoDy - dx;
        for (x = x0, y = y0; x != xEnd; x += xIncrement) {
            setPixel(x, y, r, g, b);
            if (p < 0) {
                p += twoDy;
            }
            else {
                y += yIncrement;
                p += twoDyMinusDx;
            }
        }
    }
    else {
        // Línea con pendiente >= 45 grados
        p = twoDy - dx;
        for (y = y0, x = x0; y != yEnd; y += yIncrement) {
            setPixel(x, y, r, g, b);
            if (p < 0) {
                p += twoDy;
            }
            else {
                x += xIncrement;
                p += twoDyMinusDx;
            }
        }
    }

    setPixel(xEnd, yEnd, r, g, b);
}
