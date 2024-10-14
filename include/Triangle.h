// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector3D.h"
#include "Ray.h"

class Triangle {
public:
    /**
     * @brief Constructor que inicializa los vértices, color, valor especular y reflectividad del triángulo.
     * 
     * @param a Primer vértice del triángulo.
     * @param b Segundo vértice del triángulo.
     * @param c Tercer vértice del triángulo.
     * @param color Color del triángulo.
     * @param specular Valor de la reflexión especular.
     * @param reflectivity Coeficiente de reflectividad del material.
     */
    Triangle(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& color, double specular, double reflectivity);

    /**
     * @brief Método para comprobar si un rayo intersecta el triángulo.
     * 
     * Utiliza el algoritmo de intersección de Möller-Trumbore.
     * 
     * @param ray Rayo con el que se verifica la intersección.
     * @param t Parámetro que indica la distancia a la intersección más cercana.
     * @param intersectionPoint Punto de intersección calculado si existe.
     * @return true si el rayo intersecta el triángulo, false en caso contrario.
     */
    bool intersects(const Ray& ray, double& t, Vector3D& intersectionPoint) const;

    // Métodos para obtener propiedades del triángulo
    Vector3D getNormal() const;       // Obtener el vector normal del triángulo.
    double getSpecular() const;       // Obtener el valor especular del material.
    Vector3D getColor() const;        // Obtener el color del triángulo.
    double getReflectivity() const;   // Obtener la reflectividad del material.

private:
    Vector3D a, b, c;                 // Vértices del triángulo.
    double specular;                  // Valor especular del material.
    Vector3D color;                   // Color del triángulo.
    double reflectivity;              // Reflectividad del material.
};

#endif // TRIANGLE_H
