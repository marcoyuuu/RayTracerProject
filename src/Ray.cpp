#include "Ray.h"
#include "Vector3D.h"
#include <cmath> // Para funciones matemáticas como sqrt, si son necesarias

/**
 * @brief Constructor que inicializa el rayo con un origen y una dirección.
 * 
 * @param origin Punto de origen del rayo.
 * @param direction Dirección del rayo. Se normaliza automáticamente para que siempre tenga magnitud 1.
 */
Ray::Ray(const Vector3D& origin, const Vector3D& direction) 
    : origin(origin), direction(direction.normalize()) {
    // Se normaliza la dirección para asegurarse de que siempre tenga una magnitud de 1.
}

/**
 * @brief Método para obtener el origen del rayo.
 * 
 * @return Vector3D que representa el origen del rayo.
 */
Vector3D Ray::getOrigin() const {
    return origin;
}

/**
 * @brief Método para obtener la dirección del rayo.
 * 
 * @return Vector3D que representa la dirección del rayo.
 */
Vector3D Ray::getDirection() const {
    return direction;
}
