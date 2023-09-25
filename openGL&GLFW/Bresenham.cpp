


#include "funciones.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


//ALGORITMO BRESENHAM
void lineaBresenham(int x0, int y0, int xEnd, int yEnd, float r, float g, float b) {
    int dx = fabs(xEnd - x0);
    int dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    // Determinar qué extremo usar como posición inicial.
    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }
    else {
        x = x0;
        y = y0;
    }

    setPixel(x, y, r, g, b);

    while (x < xEnd) {
        x++;

        if (p < 0) {
            p += twoDy;
        }
        else {
            y++;
            p += twoDyMinusDx;
        }

        setPixel(x, y, r, g, b);
    }
}

