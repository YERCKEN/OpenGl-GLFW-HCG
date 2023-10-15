

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
    glOrtho(0, ventanaAncho, ventanaAlto,0, -1, 1);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);



        cambiarColorFondo();


        //dibujar plano
        //dibujarPlanoCartesiano(ventanaAncho, ventanaAlto, 50); 

        //lineDDA
        
        //RECTÁNGULO
        //     (x0,  y0,xend,yend,----- COLOR -----)
        lineDDA(62, 123, 280, 123, 1.0f, 1.0f, 1.0f);
        lineDDA(62, 266, 280, 266, 1.0f, 1.0f, 1.0f);
        lineDDA(62, 123, 62,  266, 1.0f, 1.0f, 1.0f);
        lineDDA(280, 123, 280,266, 1.0f, 1.0f, 1.0f);

        //CUADRADO
        //     (x0,  y0, xend,yend,----- COLOR -----)
        lineDDA(369, 123, 511, 123, 0.0f, 0.0f, 1.0f);
        lineDDA(369, 271, 511, 271, 0.0f, 0.0f, 1.0f);
        lineDDA(369, 123, 369, 271, 0.0f, 0.0f, 1.0f);
        lineDDA(511, 123, 511, 271, 0.0f, 0.0f, 1.0f);


        //ROMBO
        //     (x0,  y0, xend,yend,----- COLOR -----)
        lineDDA(580, 200, 679, 129, 1.0f, 1.0f, 0.0f);
        lineDDA(580, 200, 679, 271, 1.0f, 1.0f, 0.0f);
        lineDDA(679, 271,780 ,200, 1.0f, 1.0f, 0.0f);
        lineDDA(679, 129, 780, 200, 1.0f, 1.0f, 0.0f);


        //OTRA FORMA 
        //     (x0,  y0, xend,yend,----- COLOR -----)
        lineDDA(796, 123, 993, 123, 0.0f, 1.0f, 0.0f);
        lineDDA(796, 123, 846, 279, 0.0f, 1.0f, 0.0f);
        lineDDA(846, 279, 945, 279, 0.0f, 1.0f, 0.0f);
        lineDDA(945, 279, 992, 123, 0.0f, 1.0f, 0.0f);

        //TRIÁNGULO
        lineDDA(1117, 100, 1029, 271, 1.0f, 0.0f, 1.0f);
        lineDDA(1029, 271, 1215, 271, 1.0f, 0.0f, 1.0f);
        lineDDA(1215, 271, 1117, 100, 1.0f, 0.0f, 1.0f);

        
        //RECTÁNGULO
        lineDDA(90, 590, 90, 425, 0.5f, 1.0f, 1.0f);
        lineDDA(90, 425, 270, 590, 0.5f, 1.0f, 1.0f);
        lineDDA(90, 590, 270, 590, 0.5f, 1.0f, 1.0f);
        
        //HEXAGONO
        lineDDA(335, 420, 425, 420, 1.0f, 0.5f, 0.0f);
        lineDDA(425, 420, 475, 505, 1.0f, 0.5f, 0.0f);
        lineDDA(475, 505, 425, 590, 1.0f, 0.5f, 0.0f);
        lineDDA(425, 590, 335, 590, 1.0f, 0.5f, 0.0f);
        lineDDA(335, 590, 285, 505, 1.0f, 0.5f, 0.0f);
        lineDDA(285, 505, 335, 420, 1.0f, 0.5f, 0.0f);


        //PENTAGONO
        lineDDA(605, 395, 502, 467, 1.0f, 1.0f, 1.0f);
        lineDDA(605, 395, 708, 467, 1.0f, 1.0f, 1.0f);
        lineDDA(502, 467, 541, 579, 1.0f, 1.0f, 1.0f);
        lineDDA(708, 467, 669, 579, 1.0f, 1.0f, 1.0f);
        lineDDA(541, 579, 669, 579, 1.0f, 1.0f, 1.0f);

        /**/
        // CRUZ
        lineDDA(780, 420, 890, 420, 0.0f, 0.0f, 1.0f);
        lineDDA(890, 420, 890, 460, 0.0f, 0.0f, 1.0f);
        lineDDA(890, 460, 925, 460, 0.0f, 0.0f, 1.0f);
        lineDDA(925, 460, 925, 535, 0.0f, 0.0f, 1.0f);
        lineDDA(925, 535, 890, 535, 0.0f, 0.0f, 1.0f);
        lineDDA(890, 535, 890, 570, 0.0f, 0.0f, 1.0f);
        lineDDA(890, 570, 780, 570, 0.0f, 0.0f, 1.0f);
        lineDDA(780, 570, 780, 535, 0.0f, 0.0f, 1.0f);
        lineDDA(780, 535, 745, 535, 0.0f, 0.0f, 1.0f);
        lineDDA(745, 535, 745, 460, 0.0f, 0.0f, 1.0f);
        lineDDA(745, 460, 780, 460, 0.0f, 0.0f, 1.0f);
        lineDDA(780, 460, 780, 420, 0.0f, 0.0f, 1.0f);

        //ESTRELLA
        lineDDA(1093, 389, 1067, 464, 0.5f, 1.0f, 1.0f);
        lineDDA(1093, 389, 1112, 464, 0.5f, 1.0f, 1.0f);
        lineDDA(1067, 464, 979, 464, 0.5f, 1.0f, 1.0f);
        lineDDA(1112, 464, 1206, 464, 0.5f, 1.0f, 1.0f);
        lineDDA(979, 464, 1051, 512, 0.5f, 1.0f, 1.0f);
        lineDDA(1206, 464, 1136 , 512, 0.5f, 1.0f, 1.0f);
        lineDDA( 1051, 512, 1023, 588, 0.5f, 1.0f, 1.0f);
        lineDDA( 1136, 512, 1164, 588, 0.5f, 1.0f, 1.0f);
        lineDDA(1023, 588, 1094, 540, 0.5f, 1.0f, 1.0f);
        lineDDA(1164, 588, 1094, 540, 0.5f, 1.0f, 1.0f);


        //lineDDA(679, 271, 780, 200, 1.0f, 1.0f, 0.0f);

        //lineDDA(679, 129, 780, 200, 1.0f, 1.0f, 0.0f);


        //lineDDA(369, 271, 511, 271, 1.0f, 1.0f, 1.0f);
        //lineDDA(369, 123, 369, 271, 1.0f, 1.0f, 1.0f);
        //lineDDA(511, 123, 511, 271, 1.0f, 1.0f, 1.0f);


        //lineDDA(100, 100, 100, 500, 1.0f, 0.0f, 0.0f);

        //lineDDA(500, 100, 500, 500, 1.0f, 0.0f, 0.0f);

        //lineDDA(100, 500, 500, 500, 1.0f, 0.0f, 0.0f);



        // LineaBresenham
        //            (x0, y0,xend,yend,----- COLOR -----)
        //lineaBresenham(50, 50, 500, 100, 0.0f, 0.0f, 1.0f);

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
