#include "Ray.h"
#include "Vector3D.h"
#include <cmath> // Para funciones matemáticas como sqrt, si son necesarias

// Constructor que inicializa el rayo con origen y dirección
Ray::Ray(const Vector3D& origin, const Vector3D& direction) 
    : origin(origin), direction(direction.normalize()) {
    // Se normaliza la dirección para asegurarse de que siempre tenga una magnitud de 1
}

// Método para obtener el origen del rayo
Vector3D Ray::getOrigin() const {
    return origin;
}

// Método para obtener la dirección del rayo
Vector3D Ray::getDirection() const {
    return direction;
}
