#ifndef UTILS_H
#define UTILS_H

#include "Vector3D.h"

/**
 * @brief Calcula el vector de reflexión dado un vector incidente y un vector normal.
 * 
 * Este método devuelve el vector resultante cuando un rayo incide sobre una superficie y se refleja,
 * basándose en las leyes de la reflexión.
 * 
 * @param incident Vector que representa el rayo incidente.
 * @param normal Vector que representa la normal de la superficie sobre la cual se refleja el rayo.
 * @return Vector reflejado como un nuevo Vector3D.
 */
Vector3D reflectRay(const Vector3D& incident, const Vector3D& normal);

#endif // UTILS_H
