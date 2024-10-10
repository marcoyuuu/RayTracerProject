#include "Camera.h"

// Constructor que inicializa la posición de la cámara
Camera::Camera(double x, double y, double z) {
    p[0] = x;
    p[1] = y;
    p[2] = z;
}

// Constructor por defecto que inicializa la cámara a (0, 0, 0)
Camera::Camera() : p{0, 0, 0} { }

// Getter para la posición x
double Camera::getX() const {
    return p[0];
}

// Getter para la posición y
double Camera::getY() const {
    return p[1];
}

// Getter para la posición z
double Camera::getZ() const {
    return p[2];
}

// Getter para la posición completa como un Vector3D
Vector3D Camera::getPosition() const {
    return Vector3D(p[0], p[1], p[2]);
}
