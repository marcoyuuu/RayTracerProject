#include "utils.h"

/**
 * @brief Calcula el vector de reflexión de un rayo incidente sobre una superficie con una normal dada.
 * 
 * Utiliza la fórmula de reflexión de vectores para calcular la dirección del rayo reflejado.
 * La fórmula es: 
 *    R = I - 2 * (N ⋅ I) * N
 * Donde:
 *  - R es el vector reflejado.
 *  - I es el vector incidente.
 *  - N es el vector normal.
 * 
 * @param incident Vector que representa el rayo incidente.
 * @param normal Vector que representa la normal de la superficie.
 * @return Vector3D que representa el rayo reflejado.
 */
Vector3D reflectRay(const Vector3D& incident, const Vector3D& normal) {
    return incident - normal * 2 * (normal.dot(incident));
}
