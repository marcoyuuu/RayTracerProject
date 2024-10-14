// Camera.cpp
#include "Camera.h"

// Constructor que inicializa la posición de la cámara a las coordenadas dadas.
Camera::Camera(double x, double y, double z) {
    p[0] = x;  // Asignar la coordenada x
    p[1] = y;  // Asignar la coordenada y
    p[2] = z;  // Asignar la coordenada z
}

// Constructor por defecto que inicializa la cámara en la posición (0, 0, 0)
Camera::Camera() : p{0, 0, 0} { }

// Getter para obtener la posición de la cámara como un objeto Vector3D
Vector3D Camera::getPosition() const {
    return Vector3D(p[0], p[1], p[2]);
}

/**
 * Genera un rayo que parte desde la cámara hacia un píxel específico en la pantalla.
 *
 * @param pixelX: Coordenada x del píxel.
 * @param pixelY: Coordenada y del píxel.
 * @param imageWidth: Ancho de la imagen en píxeles.
 * @param imageHeight: Alto de la imagen en píxeles.
 * @param viewportWidth: Ancho del viewport.
 * @param viewportHeight: Alto del viewport.
 * @param distanceToViewport: Distancia de la cámara al viewport.
 * @return Ray: Rayo generado desde la posición de la cámara hacia el píxel.
 */
Ray Camera::generateRay(int pixelX, int pixelY, int imageWidth, int imageHeight, double viewportWidth, double viewportHeight, double distanceToViewport) const {
    // Calcular la posición x e y en el plano del viewport basado en la posición del píxel
    double x = (pixelX - imageWidth / 2.0) * viewportWidth / imageWidth;
    double y = -(pixelY - imageHeight / 2.0) * viewportHeight / imageHeight; // Invertir y para la orientación correcta

    // Crear la dirección del rayo hacia el viewport
    Vector3D direction(x, y, distanceToViewport);

    // Devolver el rayo normalizado que comienza en la posición de la cámara y apunta en la dirección calculada
    return Ray(Vector3D(p[0], p[1], p[2]), direction.normalize());
}
