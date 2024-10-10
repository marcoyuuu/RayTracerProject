# RayTracerProject

Este proyecto es una implementación básica de un trazador de rayos (ray tracer) escrito en C++. El trazado de rayos es una técnica para generar imágenes simulando el comportamiento de la luz al interactuar con objetos 3D. Esta versión se centra en la generación de una imagen simple en formato PPM, considerando la intersección de rayos con triángulos en una escena.

## Características

- **Cámara**: Colocada en el origen de coordenadas (0, 0, 0).
- **Objetos**: Actualmente soporta triángulos. La escena puede ser extendida para incluir más objetos.
- **Intersecciones**: Se calcula la intersección entre los rayos y los triángulos para determinar el color de los píxeles.
- **Formato PPM**: La imagen generada se guarda en formato PPM, que es un formato de imagen sencillo basado en texto.
- **Sin especularidad ni reflexión**: Este proyecto no incluye cálculo de luces especulares o reflexiones para simplificar la implementación.

## Cómo Ejecutar

1. **Compilar**: Usa un compilador de C++ para compilar los archivos del proyecto. Puedes usar `g++` como sigue:
   ```sh
   g++ -o main main.cpp Camera.cpp createPPM.cpp Ray.cpp Scene.cpp Triangle.cpp Vector3D.cpp LightSource.cpp utils.cpp generateImage.cpp
   ```
2. **Ejecutar**: Ejecuta el archivo compilado:
   ```sh
   ./main
   ```
   Esto generará una imagen llamada `output.ppm`.

3. **Visualizar**: Abre el archivo `output.ppm` en cualquier visualizador compatible con este formato.

## Estructura del Proyecto

- **main.cpp**: Contiene la lógica principal para configurar la escena, disparar los rayos y generar la imagen PPM.
- **Camera.h/Camera.cpp**: Definen la cámara y su ubicación en el espacio.
- **Vector3D.h/Vector3D.cpp**: Implementan la clase para operar con vectores en 3D.
- **Ray.h/Ray.cpp**: Define los rayos que se disparan desde la cámara.
- **Triangle.h/Triangle.cpp**: Implementa la clase para representar triángulos y sus intersecciones con rayos.
- **Scene.h/Scene.cpp**: Define la escena y contiene los objetos.
- **createPPM.h/createPPM.cpp**: Contiene la lógica para generar y guardar la imagen en formato PPM.
- **LightSource.h/LightSource.cpp**: (En desarrollo) Define las fuentes de luz para futuras mejoras en la iluminación.
- **utils.h/utils.cpp**: Contiene funciones utilitarias que se usan en varias partes del proyecto para facilitar cálculos comunes.
- **generateImage.h/generateImage.cpp**: Define funciones relacionadas con la generación de la imagen, como el trazado de rayos y la configuración del framebuffer.

## Mejoras Futuras

- **Especularidad y Reflexión**: Implementar cálculo de luz especular y reflexión para dar mayor realismo a la escena.
- **Soporte para más objetos**: Agregar esferas, planos y otros objetos para hacer la escena más compleja.
- **Sombras y Luces**: Agregar fuentes de luz para calcular sombras y mejorar el realismo.

## Referencias
Este proyecto fue desarrollado como parte de un ejercicio de aprendizaje sobre cómo funcionan los trazadores de rayos y cómo se pueden implementar en C++. Se enfoca en la comprensión de conceptos fundamentales como la geometría 3D, la intersección de rayos, y la generación de imágenes.

## Autor
- **Marco Yu**: Desarrollador del proyecto.

Si tienes alguna pregunta o sugerencia, por favor siéntete libre de abrir un issue o enviar un pull request.