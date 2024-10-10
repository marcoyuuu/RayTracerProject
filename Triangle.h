#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3D.h"
#include "Ray.h"

class Triangle {
public:
    Triangle(const Vector3D& a, const Vector3D& b, const Vector3D& c); // Constructor que inicializa los vértices del triángulo
    bool intersects(const Ray& ray, double& t) const; // Método para comprobar si un rayo intersecta con el triángulo
    Vector3D getNormal() const; // Método para obtener la normal del triángulo
    double getSpecular() const; // Devuelve el valor de especularidad del material
    Vector3D getColor() const;  // Devuelve el color del triángulo
    double getReflectivity() const; // Devuelve la reflectividad del material

private:
    Vector3D a, b, c; // Vértices del triángulo
};

#endif // TRIANGLE_H
