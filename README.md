# OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS = PARA UTILIZAR EL PROYECTO DEBES TENER GLFW REFERENCIADO


__Paso #1: Dependencias C++__
Primeramente, se debe instalar las dependencias de C++ para IDE, por lo que debemos entrar a VISUAL STUDIO INSTALLER y seleccionar para instalar el “Desarrollo para el escritorio con C++”


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/27012ee7-acba-46a4-8a2e-4899ed69f17a)


__Paso #2: Descargar binarios GLFW__
Una vez instalado, se necesita descargar los binarios de GLFW, por lo que buscamos su página oficial, en su sección de descargas https://www.glfw.org/download.html, Luego descargamos los binarios, en este caso 64 bits, pero eso dependerá del sistema operativo.


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/bbc25874-6a72-47dd-904f-3160d81e9de8)


Una vez tengas descargados los binarios extraes el .zip y guardas en un lugar que recuerdes, ya que se utilizará para el proyecto.


__Paso #3: Configuración del proyecto__
Entras a la configuración del proyecto y en la Dropbox de configuraciones indicas “Todas las config.” Y en plataforma “x64”


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/88db9834-857e-4489-84eb-cda57952f06e)


Luego nos vamos a la sección “C/C++” entramos en “General” y agregamos Directorios de inclusión adicionales.


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/123807f6-09a1-4600-b1f2-3e993c78c75b)


Le damos agregar nueva línea, y buscamos en la carpeta donde guardamos los binarios del GLFW y pegamos la ruta de la carpeta “include”, por ejemplo, en mi caso: C:\OPENGL\glfw-3.3.8.bin.WIN64\include


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/92236075-a7e2-470c-a2cb-528738ec99cb)


 Luego nos vamos a la sección Vinculador/General/Directorios de bibliotecas adicionales/editar.


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/1182eeb1-4dbf-4647-87e4-ee1cb42c7204)


Una vez dentro de editar le damos a ingresar nueva línea y pegamos la dirección de “lib-vc” ubicado dentro de la carpeta de los binarios, en este paso deberás elegir esta carpeta según la versión de visual que tengas en el momento en mi caso la 2022.



![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/dfbcc02f-c075-4c45-a019-524e8df4c7ba)



Ahora nos vamos a la sección Entrada/Dependencias adicionales y agregamos las siguientes dependencias. 
  	glfw3.lib
  	opengl32.lib
  	user32.lib
  	gdi32.lib
  	shell32.lib


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/dfb50731-b483-4be7-9c3d-fc24b3b2a29f)


![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/b311d01e-d9e9-4eec-8379-ecca188d9592)


una vez agregamos estas dependencias simplemente damos a aplicar y aceptamos y ya podremos probar OPENGL en nuestra computadora con GLFW



# EJECUCIÓN

![image](https://github.com/YERCKEN/OpenGl-GLFW-LAB-1-HERRAMIENTAS-COMPUTACION-GRAFICAS/assets/42678417/230ae4fb-b5c2-45c5-b09a-04dec6ad06a1)

