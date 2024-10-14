#include "generateImage.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Camera.h"
#include "Scene.h"

/**
 * Genera la imagen utilizando la escena y la cámara especificadas.
 *
 * @param scene: La escena que contiene los objetos y las luces a renderizar.
 * @param cam: La cámara desde la cual se generarán los rayos.
 * @param framebuffer: Vector que almacena los colores de cada píxel de la imagen.
 * @param width: Ancho de la imagen en píxeles.
 * @param height: Alto de la imagen en píxeles.
 * @param maxDepth: Profundidad máxima de las reflexiones para los rayos.
 * @param viewportWidth: Ancho del viewport en unidades del mundo.
 * @param viewportHeight: Alto del viewport en unidades del mundo.
 * @param distanceToViewport: Distancia desde la cámara hasta el viewport.
 */
void generateImage(const Scene& scene, const Camera& cam, std::vector<Vector3D>& framebuffer, int width, int height, int maxDepth, double viewportWidth, double viewportHeight, double distanceToViewport) {
    // Recorre cada píxel de la imagen
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Genera un rayo desde la cámara para el píxel actual
            Ray ray = cam.generateRay(x, y, width, height, viewportWidth, viewportHeight, distanceToViewport);

            // Trazar el rayo a través de la escena y almacenar el color resultante en el framebuffer
            framebuffer[y * width + x] = scene.traceRay(ray, maxDepth);
        }
    }
}
