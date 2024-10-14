// Camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"
#include "Vector3D.h"

class Camera {
public:
    /**
     * Constructor que inicializa la posición de la cámara a las coordenadas dadas.
     *
     * @param x: Coordenada x de la posición de la cámara.
     * @param y: Coordenada y de la posición de la cámara.
     * @param z: Coordenada z de la posición de la cámara.
     */
    Camera(double x, double y, double z);

    /**
     * Constructor por defecto que inicializa la cámara en la posición (0, 0, 0).
     */
    Camera();

    /**
     * Obtiene la posición de la cámara como un objeto Vector3D.
     *
     * @return Vector3D: Posición de la cámara.
     */
    Vector3D getPosition() const;

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
    Ray generateRay(int pixelX, int pixelY, int imageWidth, int imageHeight, double viewportWidth, double viewportHeight, double distanceToViewport) const;

private:
    double p[3]; // Array que contiene las coordenadas x, y, z de la posición de la cámara
};

#endif // CAMERA_H
