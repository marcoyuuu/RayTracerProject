#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"

class Camera {
public:
    Camera(double x, double y, double z); // Constructor que inicializa la posición de la cámara
    Camera(); // Constructor por defecto que inicializa la cámara a (0, 0, 0)

    double getX() const; // Obtener la posición x
    double getY() const; // Obtener la posición y
    double getZ() const; // Obtener la posición z
    Vector3D getPosition() const; // Obtener la posición completa como un Vector3D

private:
    double p[3]; // Array que contiene las coordenadas x, y, z de la cámara
};

#endif // CAMERA_H
