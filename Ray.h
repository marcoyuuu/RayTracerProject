#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

class Ray {
public:
    Ray(const Vector3D& origin, const Vector3D& direction); // Constructor que inicializa el rayo con origen y dirección
    Vector3D getOrigin() const; // Obtener el origen del rayo
    Vector3D getDirection() const; // Obtener la dirección del rayo

private:
    Vector3D origin; // Origen del rayo
    Vector3D direction; // Dirección del rayo
};

#endif // RAY_H
