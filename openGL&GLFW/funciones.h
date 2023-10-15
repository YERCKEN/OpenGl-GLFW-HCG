
#pragma once

#include <GLFW/glfw3.h>



void centrarVentana(GLFWwindow* window);
void dibujarPlanoCartesiano(int ancho, int alto, int paso);
void setPixel(int x, int y, float r, float g, float b);
void lineDDA(int xO, int yO, int xEnd, int yEnd, float r, float g, float b);
void lineaBresenham(int x0, int y0, int xEnd, int yEnd, float r, float g, float b);
void trazarCirculoPuntoMedio(int xc, int yc, int radio, float r, float g, float b, float tipo, float mitad);
void dibujarElipse(int xCentro, int yCentro, int Rx, int Ry, float r, float g, float b);
