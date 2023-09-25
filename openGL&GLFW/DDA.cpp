
#include "funciones.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>




//ALGORITMO DDA PAA LINEA

//             ( x0, y0,     xend,     yend,      -------- COLOR ---------)
void lineDDA(int xO, int yO, int xEnd, int yEnd, float r, float g, float b) {

    //VARIABLES
    int dx = xEnd - xO, dy = yEnd - yO, steps, k;
    float xIncrement, yIncrement, x = xO, y = yO;


    //CÁLCULOS
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel(round(x), round(y), r, g, b);
    }
}
