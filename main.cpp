#include "Camera.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Triangle.h"
#include "Scene.h"
#include "createPPM.h"

#define IMAGE_WIDTH 300
#define IMAGE_HEIGHT 300

using namespace std;

int main() {
    // 1. Configuración de la escena
    Scene scene;

    // Añadir objetos a la escena (por ejemplo, un triángulo)
    scene.addTriangle(Triangle(Vector3D(0, 0, 2), Vector3D(1, 2, 2), Vector3D(-1, 2, 2)));

    // 2. Crear la cámara en el origen
    Camera cam(0, 0, 0);

    // 3. Generar la imagen
    std::vector<Vector3D> framebuffer(IMAGE_WIDTH * IMAGE_HEIGHT);

    // Recorremos cada píxel de la imagen
    for (int y = -IMAGE_HEIGHT / 2; y < IMAGE_HEIGHT / 2; ++y) {
        for (int x = -IMAGE_WIDTH / 2; x < IMAGE_WIDTH / 2; ++x) {
            // 4. Generar el rayo desde la cámara a través de cada píxel
            // Normalizamos las coordenadas para que estén en el rango [-1, 1]
            double px = static_cast<double>(x) / (IMAGE_WIDTH / 2);
            double py = static_cast<double>(y) / (IMAGE_HEIGHT / 2);
            Vector3D direction(px, py, 1);
            direction = direction.normalize(); // Normalizar la dirección para que tenga longitud 1
            Vector3D cameraPosition(cam.getX(), cam.getY(), cam.getZ());
            Ray ray(cameraPosition, direction);

            // 5. Calcular el color del píxel disparando el rayo y verificando intersecciones
            Vector3D hitPoint, normal;
            Vector3D color;
            if (scene.intersects(ray, hitPoint, normal)) {
                // Si hay intersección, asignamos un color arbitrario (por ejemplo, rojo)
                color = Vector3D(255, 0, 0);
            } else {
                // Si no hay intersección, usamos un color de fondo (negro)
                color = Vector3D(0, 0, 0);
            }

            // 6. Almacenar el color calculado en el framebuffer
            framebuffer[(y + IMAGE_HEIGHT / 2) * IMAGE_WIDTH + (x + IMAGE_WIDTH / 2)] = color;
        }
    }

    // 7. Guardar la imagen en formato PPM
    createPPM(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}