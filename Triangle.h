#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3D.h"
#include "Ray.h"

class Triangle {
public:
    // Constructor que inicializa los vértices, color, especularidad y reflectividad
    Triangle(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& color, double specular, double reflectivity);

    bool intersects(const Ray& ray, double& t) const; // Método para comprobar si un rayo intersecta con el triángulo
    Vector3D getNormal() const; // Método para obtener la normal del triángulo
    double getSpecular() const; // Devuelve el valor de especularidad del material
    Vector3D getColor() const;  // Devuelve el color del triángulo
    double getReflectivity() const; // Devuelve la reflectividad del material

private:
    Vector3D a, b, c; // Vértices del triángulo
    double specular; // Valor especular del material
    Vector3D color;  // Color del triángulo
    double reflectivity; // Reflectividad del material
};

#endif // TRIANGLE_H
