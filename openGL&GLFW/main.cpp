

// HERRAMIENTAS GRÁFICAS: LÍNEA (DDA - BRESENHAM) CIRCULO Y ELIPSE

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "funciones.h"



// Ancho y alto de la ventana
const int ventanaAncho = 1280;
const int ventanaAlto = 720;


// Función para centrar la ventana GLFW en la pantalla
void centrarVentana(GLFWwindow* window) {

    // Obtiene la resolución del monitor primario
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    // Calcula la posición en la que se debe colocar la ventana para que esté centrada
    int xPos = (mode->width - ventanaAncho) / 2;
    int yPos = (mode->height - ventanaAlto) / 2;

    // Establece la posición de la ventana
    glfwSetWindowPos(window, xPos, yPos);
}




// Función para dibujar un plano cartesiano como guía con ejes X e Y 
void dibujarPlanoCartesiano(int ancho, int alto, int paso) {
    // Dibujar ejes X e Y
    glBegin(GL_LINES);

    // Eje X (verde)
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex2i(-ancho, 0);
    glVertex2i(ancho, 0);

    // Eje Y (rojo)
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex2i(1, -alto);
    glVertex2i(1, alto);

    glEnd();
}




//           ( x0  ,  y0  , ------ COLOR ------)
void setPixel(int x, int y, int r, int g, int b) {
    //GROZOR
    glPointSize(3.0f);

    //MODO DIBUJO PUNTOS
    glBegin(GL_POINTS);

    //COLOR
    glColor3f(r, g, b);

    //DEFINIMOS PUNTO
    glVertex2i(x, y);

    //FINALIZAMOS DIBUJO PUNTO
    glEnd();
}



void cambiarColorFondo() {
    //            R     G     B    OPACIDAD
    glClearColor(0.1f, 0.1f, 0.1f,   1.0f    );

    // Limpia el búfer 
    glClear(GL_COLOR_BUFFER_BIT);
}



int main() {

    GLFWwindow* window;

    //verificacmos que incia bien  GLFW
    if (!glfwInit()) {
        std::cerr << "Error: Fallo en la inicialización de GLFW." << std::endl;
        return -1;
    }

    // Crear una ventana con el ancho y alto definidos
    window = glfwCreateWindow(ventanaAncho, ventanaAlto, "OPENGL PRUEBA", NULL, NULL);

    // POSICIÓN MANUAL
   // glfwSetWindowPos(window, 100, 500);

    if (!window) {

        std::cerr << "Error: Fallo en la creación de la ventana GLFW." << std::endl;
        glfwTerminate();
        return -1;
    }

    // Centrar la ventana en la pantalla
    centrarVentana(window);

    glfwMakeContextCurrent(window);

    //pixeleS
    //eje arriba izquierda
    //glOrtho(0, ventanaAncho, ventanaAlto,0, -1, 1);
    //eje abajo izquierda
    glOrtho(0, ventanaAncho, 0, ventanaAlto, -1, 1);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);



        cambiarColorFondo();


        //dibujar plano
        //dibujarPlanoCartesiano(ventanaAncho, ventanaAlto, 50); 

        //lineDDA
        
        //RECTÁNGULO
        //     (x0,  y0,xend,yend,----- COLOR -----)
        //lineDDA(62, 123, 280, 123, 1.0f, 1.0f, 1.0f);
     

        // LineaBresenham
        //            (x0, y0,xend,yend,----- COLOR -----)
        lineaBresenham(165, 290, 568, 290, 0.0f, 0.0f, 1.0f);
        lineaBresenham(506, 100, 850, 327, 0.0f, 0.0f, 1.0f);
        lineaBresenham(100, 100, 100, 500, 0.0f, 0.0f, 1.0f);

        lineaBresenham(850, 600, 1200, 300, 0.0f, 0.0f, 1.0f);



        //CIRCULO
        //                       X    Y  RADIO  -----COLOR------          
        //trazarCirculoPuntoMedio(400, 400, 100, 0.0f, 1.0f, 1.0f);

        //ELIPSE
        //           CENTRO(XY), RADIOS, -----COLOR------
        //dibujarElipse(400, 400, 100, 50, 1.0f, 1.0f, 0.0f);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
