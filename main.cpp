#include "Camera.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Triangle.h"
#include "Scene.h"
#include "createPPM.h"
#include "generateImage.h"
#include "LightSource.h"

#define IMAGE_WIDTH 300
#define IMAGE_HEIGHT 300
#define MAX_RECURSION_DEPTH 3

using namespace std;

int main() {
    // 1. Configuración de la escena
    Scene scene;

    // Añadir triángulos a la escena
    scene.addTriangle(Triangle(Vector3D(0, 0, 2), Vector3D(1, 2, 2), Vector3D(-1, 2, 2), Vector3D(255, 0, 0), 500, 0.2));
    scene.addTriangle(Triangle(Vector3D(2, 0, 4), Vector3D(3, 2, 4), Vector3D(1, 2, 4), Vector3D(0, 255, 0), 300, 0.5));

    // Añadir luces a la escena
    scene.addLight(LightSource(LightSource::AMBIENT, 0.2));
    scene.addLight(LightSource(LightSource::POINT, 0.6, Vector3D(2, 1, 0)));
    scene.addLight(LightSource(LightSource::DIRECTIONAL, 0.2, Vector3D(), Vector3D(1, 4, 4)));

    // 2. Crear la cámara en el origen
    Camera cam(0, 0, 0);

    // 3. Generar el framebuffer
    std::vector<Vector3D> framebuffer(IMAGE_WIDTH * IMAGE_HEIGHT);

    // 4. Generar la imagen utilizando reflexión y especularidad
    generateImage(scene, cam, framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    // 5. Guardar la imagen en formato PPM
    createPPM(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}
