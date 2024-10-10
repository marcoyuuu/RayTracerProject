#include "generateImage.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Camera.h"
#include "Scene.h"

void generateImage(const Scene& scene, const Camera& cam, std::vector<Vector3D>& framebuffer, int width, int height) {
    // Recorremos cada píxel de la imagen
    for (int y = -height / 2; y < height / 2; ++y) {
        for (int x = -width / 2; x < width / 2; ++x) {
            // Generar el rayo desde la cámara a través de cada píxel
            // Normalizamos las coordenadas para que estén en el rango [-1, 1]
            double px = static_cast<double>(x) / (width / 2);
            double py = static_cast<double>(y) / (height / 2);
            Vector3D direction(px, py, 1);
            direction = direction.normalize(); // Normalizar la dirección para que tenga longitud 1
            Vector3D cameraPosition(cam.getX(), cam.getY(), cam.getZ());
            Ray ray(cameraPosition, direction);

            // Calcular el color del píxel disparando el rayo y verificando intersecciones
            Vector3D color = scene.traceRay(ray, 0);

            // Almacenar el color calculado en el framebuffer
            framebuffer[(y + height / 2) * width + (x + width / 2)] = color;
        }
    }
}
