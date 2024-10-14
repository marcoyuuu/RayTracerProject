# Proyecto: Examen - Ray Tracer

Este proyecto consiste en la implementación de un **Ray Tracer** básico en C++. El programa renderiza una imagen utilizando técnicas de trazado de rayos para simular luces, sombras, reflexiones, y materiales. Este README te ayudará a entender la estructura del proyecto, cómo compilarlo y cómo generar la documentación.

## Características
- Soporte para figuras geométricas básicas: **esferas**, **planos** y **triángulos**.
- Soporte para varios tipos de luces: **ambiente**, **direccional** y **punto**.
- Implementación de **reflexiones** y **sombras**.
- **Gamma Correction** para mejorar la calidad de la imagen generada.
- Documentación generada mediante **Doxygen**.

## Estructura del Proyecto
El proyecto está organizado de la siguiente manera:

```
Examen/
  |-- .vscode/               # Configuración del entorno de desarrollo
  |-- docs/                  # Documentación generada por Doxygen
  |-- Camera.cpp/h           # Implementación de la clase Camera
  |-- createPPM.cpp/h        # Funciones para crear el archivo PPM con la imagen renderizada
  |-- Doxyfile               # Archivo de configuración de Doxygen
  |-- generateImage.cpp/h    # Funciones para generar la imagen final
  |-- LightSource.cpp/h      # Clase para definir diferentes fuentes de luz
  |-- main.cpp               # Archivo principal para ejecutar el programa
  |-- Plane.cpp/h            # Clase para representar planos
  |-- Ray.cpp/h              # Clase para representar un rayo
  |-- README.md              # Este archivo
  |-- Scene.cpp/h            # Clase que define la escena y maneja los objetos, luces y sombras
  |-- Sphere.cpp/h           # Clase para representar esferas
  |-- Triangle.cpp/h         # Clase para representar triángulos
  |-- utils.cpp/h            # Funciones útiles, como el cálculo de reflexiones
  |-- Vector3D.cpp/h         # Clase para manejar operaciones vectoriales
```

## Requisitos
- **C++ Compiler**: Se recomienda **g++** (MinGW para Windows).
- **Make**: Para compilar el proyecto mediante el Makefile.
- **Doxygen**: Para generar la documentación automática del código.

## Instalación
1. Clona el repositorio en tu máquina local:
   ```sh
   git clone <url-del-repositorio>
   ```

2. Asegúrate de tener **g++**, **make**, y **doxygen** instalados.

3. Instala **Doxygen** si no lo tienes:
   - En Windows puedes usar [MSYS2](https://www.msys2.org/) o [Chocolatey](https://chocolatey.org/) para instalarlo.

## Compilación
Para compilar el proyecto puedes utilizar el **Makefile** proporcionado. Abre una terminal en la carpeta del proyecto y ejecuta:

```sh
make
```
Esto generará el archivo ejecutable `main.exe`.

## Ejecución
Para ejecutar el proyecto y generar la imagen renderizada, utiliza el siguiente comando:

```sh
./bin/main
```
Esto creará un archivo llamado `output.ppm` que contiene la imagen generada.

## Visualización de la Imagen
La imagen se genera en formato **PPM**. Puedes abrir este tipo de archivo con programas como **GIMP**, **Photoshop**, o incluso algunos visores de imágenes online.

## Generación de Documentación
El proyecto está documentado utilizando **Doxygen**. Para generar la documentación:

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta el siguiente comando:
   ```sh
   doxygen Doxyfile
   ```
3. La documentación se generará en la carpeta `docs/`. Abre el archivo `index.html` en un navegador para ver la documentación.

## Uso del Proyecto
Este proyecto tiene como objetivo implementar un trazador de rayos básico que incluya sombras, luces, y reflexiones para simular la interacción entre los objetos y la luz. Puedes personalizar la escena en `main.cpp` agregando más objetos o ajustando las luces para experimentar.

### Ejemplo de Modificación
Puedes agregar una esfera más cambiando el archivo `main.cpp`:
```cpp
scene.addSphere(Sphere(Vector3D(1, 1, 5), 1.5, Vector3D(0, 0, 255), 200, 0.3));
```
Esto agregará una esfera azul a la escena con una leve reflectividad.

## Problemas Comunes
- **No se reconoce `make`**: Asegúrate de haber instalado `make` y de que esté en tu `PATH`.
- **Errores de compilación**: Verifica que todas las dependencias estén en la misma carpeta y que el Makefile apunte a los archivos correctos.

## Contribuir
Las contribuciones son bienvenidas. Puedes:
- Crear **pull requests** para agregar nuevas características o corregir errores.
- Reportar problemas mediante **issues**.

Por favor, sigue los estándares de código y la guía de estilo establecida en el proyecto.

## Licencia
Este proyecto está bajo la licencia **MIT**. Puedes usarlo y modificarlo libremente, siempre que se mantenga la licencia original.

## Autores
- **Marco Yu Cordero** - Implementación y Documentación.

Si tienes alguna pregunta o sugerencia, no dudes en contactarme.

