#include "Camera.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Triangle.h"
#include "Scene.h"
#include "createPPM.h"
#include "generateImage.h"

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

    // 4. Llamar a la función para generar la imagen
    generateImage(scene, cam, framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    // 5. Guardar la imagen en formato PPM
    createPPM(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}
