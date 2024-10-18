#include "Scene.h"
#include "Camera.h"
#include "createPPM.h"
#include "generateImage.h"
#include <vector>
#include <chrono>
#include <iostream>

#define IMAGE_WIDTH 1000
#define IMAGE_HEIGHT 1000
#define VIEWPORT_WIDTH 2
#define VIEWPORT_HEIGHT 2
#define DISTANCE_TO_VIEWPORT 1
#define MAX_REFLECTION_DEPTH 10  // Profundidad de reflejo alta para reflejos detallados

/**
 * @brief Función principal que configura la escena, agrega objetos y luces, genera la imagen y la guarda como un archivo PPM.
 */
int main() {
    // 1. Crear la escena
    Scene scene;

    // Agregar triángulos a la escena con propiedades específicas y mejor separados
    scene.addTriangle(Triangle(Vector3D(-2, 0, 3), Vector3D(-1, 2, 3), Vector3D(-3, 2, 3), Vector3D(80, 80, 255), 1000, 0.02)); // Triángulo azul brillante (baja reflectividad, mate)
    scene.addTriangle(Triangle(Vector3D(0, 0, 2), Vector3D(1, 2, 2), Vector3D(-1, 2, 2), Vector3D(255, 50, 50), 2000, 1.0));  // Triángulo rojo brillante (alta reflectividad, como espejo)
    scene.addTriangle(Triangle(Vector3D(2, 0, 4), Vector3D(3, 2, 4), Vector3D(1, 2, 4), Vector3D(50, 255, 50), 1000, 0.02));  // Triángulo verde brillante (baja reflectividad, mate)
    scene.addTriangle(Triangle(Vector3D(-2, 3, 3), Vector3D(-1, 5, 3), Vector3D(-3, 5, 3), Vector3D(0, 255, 255), 800, 0.5));   // Triángulo cian (posicionado más cerca para mejor visibilidad)
    scene.addTriangle(Triangle(Vector3D(5, 3, 10), Vector3D(7, 8, 10), Vector3D(3, 8, 10), Vector3D(150, 150, 255), 1000, 0.4)); // Triángulo azul claro grande
    scene.addTriangle(Triangle(Vector3D(8, 0, 12), Vector3D(9, 5, 12), Vector3D(7, 5, 12), Vector3D(255, 200, 0), 1200, 0.6)); // Triángulo amarillo alto
    scene.addTriangle(Triangle(Vector3D(-8, -3, 10), Vector3D(-7, 2, 10), Vector3D(-9, 2, 10), Vector3D(200, 100, 100), 900, 0.3)); // Triángulo rojo oscuro (más abajo)
    scene.addTriangle(Triangle(Vector3D(3, 1, 6), Vector3D(4, 3, 6), Vector3D(2, 3, 6), Vector3D(100, 255, 100), 1000, 0.2)); // Triángulo verde claro
    scene.addTriangle(Triangle(Vector3D(-6, 4, 8), Vector3D(-5, 7, 8), Vector3D(-7, 7, 8), Vector3D(255, 0, 255), 1100, 0.7)); // Triángulo magenta reflectivo (más arriba)
    scene.addTriangle(Triangle(Vector3D(0, 6, 15), Vector3D(1, 8, 15), Vector3D(-1, 8, 15), Vector3D(150, 150, 150), 1200, 0.5)); // Triángulo gris claro (alto, en el centro)
    scene.addTriangle(Triangle(Vector3D(-10, 8, 20), Vector3D(-9, 12, 20), Vector3D(-11, 12, 20), Vector3D(200, 200, 50), 1300, 0.8)); // Triángulo dorado (muy alto)
    scene.addTriangle(Triangle(Vector3D(10, -5, 25), Vector3D(12, -2, 25), Vector3D(8, -2, 25), Vector3D(100, 100, 100), 1100, 0.3)); // Triángulo gris oscuro (más abajo y lejos)

    // Agregar esferas a la escena y mejor separadas
    scene.addSphere(Sphere(Vector3D(0, 3, 3), 1, Vector3D(255, 0, 0), 500, 0.5));  // Esfera roja sobre los triángulos (reflectividad media)
    scene.addSphere(Sphere(Vector3D(0, -1, 3), 1, Vector3D(0, 255, 0), 500, 0.5)); // Esfera verde debajo de los triángulos (reflectividad media)
    scene.addSphere(Sphere(Vector3D(7, 0, 15), 1.5, Vector3D(238, 130, 238), 400, 0.6)); // Esfera violeta grande (reflectividad alta, posicionada más cerca para mejor visibilidad)
    scene.addSphere(Sphere(Vector3D(-5, 2, 7), 1.2, Vector3D(0, 255, 255), 600, 0.4)); // Esfera cian mediana
    scene.addSphere(Sphere(Vector3D(4, -4, 10), 2.0, Vector3D(255, 255, 0), 700, 0.3)); // Esfera amarilla grande (más abajo)
    scene.addSphere(Sphere(Vector3D(-7, 5, 12), 1.8, Vector3D(100, 100, 255), 500, 0.5)); // Esfera azul claro (más arriba)
    scene.addSphere(Sphere(Vector3D(6, 3, 8), 0.9, Vector3D(255, 100, 100), 800, 0.6)); // Esfera roja pequeña (media altura)
    scene.addSphere(Sphere(Vector3D(-4, 0, 5), 1.3, Vector3D(0, 200, 100), 450, 0.4)); // Esfera verde oscuro
    scene.addSphere(Sphere(Vector3D(8, -2, 11), 1.1, Vector3D(200, 200, 50), 600, 0.5)); // Esfera dorada mediana (más abajo)
    scene.addSphere(Sphere(Vector3D(-9, 6, 14), 1.4, Vector3D(150, 50, 150), 500, 0.7)); // Esfera púrpura reflectiva (alta)
    scene.addSphere(Sphere(Vector3D(3, -3, 13), 1.6, Vector3D(50, 150, 200), 550, 0.6)); // Esfera azul celeste grande (más abajo)
    scene.addSphere(Sphere(Vector3D(-10, 1, 16), 1.0, Vector3D(100, 255, 100), 650, 0.4)); // Esfera verde claro (media altura)
    scene.addSphere(Sphere(Vector3D(10, 4, 18), 2.2, Vector3D(255, 215, 0), 700, 0.3)); // Esfera dorada grande (alta)
    scene.addSphere(Sphere(Vector3D(-15, -6, 20), 2.5, Vector3D(100, 255, 255), 750, 0.6)); // Esfera cian gigante (muy lejos y abajo)
    scene.addSphere(Sphere(Vector3D(15, 10, 25), 1.8, Vector3D(255, 0, 100), 800, 0.7)); // Esfera rosa alta y lejos
    scene.addSphere(Sphere(Vector3D(-12, 3, 18), 1.3, Vector3D(0, 100, 255), 550, 0.5)); // Esfera azul medio (media altura y lejos)
    scene.addSphere(Sphere(Vector3D(12, -8, 22), 1.7, Vector3D(255, 150, 0), 600, 0.4)); // Esfera naranja (muy abajo y lejos)

    // Agregar planos para crear un efecto de "caja" con reflectividad reducida para un mejor contraste de los triángulos
    scene.addPlane(Plane(Vector3D(0, -10, 0), Vector3D(0, 1, 0), Vector3D(50, 50, 50), 10, 0.1));   // Plano del piso (gris oscuro, reflectividad baja)
    scene.addPlane(Plane(Vector3D(0, 10, 0), Vector3D(0, -1, 0), Vector3D(150, 150, 150), 50, 0.0));   // Plano del techo (gris claro, sin reflectividad)
    scene.addPlane(Plane(Vector3D(-20, 0, 0), Vector3D(1, 0, 0), Vector3D(120, 120, 120), 10, 0.2));   // Plano de la pared izquierda (gris medio, reflectividad media)
    scene.addPlane(Plane(Vector3D(20, 0, 0), Vector3D(-1, 0, 0), Vector3D(130, 130, 130), 10, 0.2));   // Plano de la pared derecha (gris medio claro, reflectividad media)
    scene.addPlane(Plane(Vector3D(0, 0, -10), Vector3D(0, 0, 1), Vector3D(80, 80, 80), 10, 0.0));   // Plano de la pared trasera (gris oscuro, sin reflectividad)

    // Agregar luces a la escena
    scene.addLight(LightSource(LightSource::AMBIENT, 0.015));  // Luz ambiental ligeramente aumentada para una mejor iluminación de áreas oscuras
    scene.addLight(LightSource(LightSource::POINT, 60.0, Vector3D(0, 10, 4)));  // Luz puntual fuerte posicionada más arriba y hacia el frente para iluminar los objetos superiores
    scene.addLight(LightSource(LightSource::DIRECTIONAL, 12.0, Vector3D(), Vector3D(-1, -1, -1))); // Luz direccional fuerte para sombras bien definidas
    scene.addLight(LightSource(LightSource::POINT, 50.0, Vector3D(-5, -8, -4)));  // Luz puntual adicional desde otro ángulo para una mejor iluminación

    // 2. Crear la cámara con una posición ajustada para visualizar bien la escena
    Camera camera(0, 1.8, -8);  // Posicionada más lejos para tener una buena perspectiva de todos los objetos

    // 3. Inicializar el framebuffer
    std::vector<Vector3D> framebuffer(IMAGE_WIDTH * IMAGE_HEIGHT);

    // Medir el tiempo de generación de la imagen
    auto start = std::chrono::high_resolution_clock::now();

    // 4. Generar la imagen usando la escena y la cámara
    generateImage(scene, camera, framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT, MAX_REFLECTION_DEPTH, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, DISTANCE_TO_VIEWPORT);

    // Medir el tiempo después de la generación
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de renderizado: " << duration.count() << " segundos" << std::endl;

    // 5. Guardar la imagen como un archivo PPM
    createPPM(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}
