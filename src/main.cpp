#include "Scene.h"
#include "Camera.h"
#include "createPPM.h"
#include "generateImage.h"
#include <vector>

#define IMAGE_WIDTH 1000
#define IMAGE_HEIGHT 1000
#define VIEWPORT_WIDTH 1
#define VIEWPORT_HEIGHT 1
#define DISTANCE_TO_VIEWPORT 1
#define MAX_REFLECTION_DEPTH 10  // Profundidad de reflejo alta para reflejos detallados

/**
 * @brief Función principal que configura la escena, agrega objetos y luces, genera la imagen y la guarda como un archivo PPM.
 */
int main() {
    // 1. Crear la escena
    Scene scene;

    // Agregar triángulos a la escena con propiedades específicas
    // Estos triángulos están coloreados con alto brillo para una mejor visibilidad
    scene.addTriangle(Triangle(Vector3D(-2, 0, 3), Vector3D(-1, 2, 3), Vector3D(-3, 2, 3), Vector3D(80, 80, 255), 1000, 0.02)); // Triángulo azul brillante (baja reflectividad, mate)
    scene.addTriangle(Triangle(Vector3D(0, 0, 2), Vector3D(1, 2, 2), Vector3D(-1, 2, 2), Vector3D(255, 50, 50), 2000, 1.0));  // Triángulo rojo brillante (alta reflectividad, como espejo)
    scene.addTriangle(Triangle(Vector3D(2, 0, 4), Vector3D(3, 2, 4), Vector3D(1, 2, 4), Vector3D(50, 255, 50), 1000, 0.02));  // Triángulo verde brillante (baja reflectividad, mate)

    // Agregar esferas a la escena
    // Estas esferas tienen diferentes colores y reflectividades para probar el efecto de iluminación
    scene.addSphere(Sphere(Vector3D(0, 3, 3), 1, Vector3D(255, 0, 0), 500, 0.5));  // Esfera roja sobre los triángulos (reflectividad media)
    scene.addSphere(Sphere(Vector3D(0, -1, 3), 1, Vector3D(0, 255, 0), 500, 0.5)); // Esfera verde debajo de los triángulos (reflectividad media)

    // Agregar planos para crear un efecto de "caja" con reflectividad reducida para un mejor contraste de los triángulos
    scene.addPlane(Plane(Vector3D(0, -2, 0), Vector3D(0, 1, 0), Vector3D(60, 60, 60), 10, 0.1));   // Plano del piso (gris oscuro, reflectividad reducida)
    scene.addPlane(Plane(Vector3D(0, 5, 0), Vector3D(0, -1, 0), Vector3D(180, 180, 180), 50, 0.0));   // Plano del techo (gris claro, sin reflectividad)
    scene.addPlane(Plane(Vector3D(-5, 0, 0), Vector3D(1, 0, 0), Vector3D(255, 120, 120), 10, 0.05));   // Plano de la pared izquierda (tono rojo brillante, mínima reflectividad)
    scene.addPlane(Plane(Vector3D(5, 0, 0), Vector3D(-1, 0, 0), Vector3D(120, 180, 255), 10, 0.05));   // Plano de la pared derecha (tono azul brillante, mínima reflectividad)
    scene.addPlane(Plane(Vector3D(0, 0, -8), Vector3D(0, 0, 1), Vector3D(80, 80, 80), 10, 0.0));   // Plano de la pared trasera (fondo más oscuro para resaltar los reflejos)

    // Agregar luces a la escena con intensidad ajustada para enfatizar los colores de los triángulos
    scene.addLight(LightSource(LightSource::AMBIENT, 0.015));  // Luz ambiental ligeramente aumentada para una mejor iluminación de áreas oscuras
    scene.addLight(LightSource(LightSource::POINT, 50.0, Vector3D(0, 6, 4)));  // Luz puntual fuerte posicionada sobre los triángulos y hacia el frente
    scene.addLight(LightSource(LightSource::DIRECTIONAL, 8.0, Vector3D(), Vector3D(-1, -1, -1))); // Luz direccional fuerte para sombras bien definidas
    scene.addLight(LightSource(LightSource::POINT, 20.0, Vector3D(-2, 3, 1)));  // Luz puntual adicional enfocada más en el triángulo del medio
    scene.addLight(LightSource(LightSource::POINT, 40.0, Vector3D(-5, 8, -4)));  // Luz puntual adicional desde otro ángulo para una mejor iluminación

    // 2. Crear la cámara con una posición ajustada para una mejor visualización de la escena
    Camera camera(0, 1.8, -8);  // Posicionada en -8 para tener una buena perspectiva de todos los objetos

    // 3. Inicializar el framebuffer
    std::vector<Vector3D> framebuffer(IMAGE_WIDTH * IMAGE_HEIGHT);

    // 4. Generar la imagen usando la escena y la cámara
    generateImage(scene, camera, framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT, MAX_REFLECTION_DEPTH, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, DISTANCE_TO_VIEWPORT);

    // 5. Guardar la imagen como un archivo PPM
    createPPM(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}