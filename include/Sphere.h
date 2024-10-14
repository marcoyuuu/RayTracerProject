// Sphere.h
#ifndef SPHERE_H
#define SPHERE_H

#include "Vector3D.h"
#include "Ray.h"

class Sphere {
public:
    /**
     * @brief Constructor que inicializa el centro, radio, color, valor especular y reflectividad de la esfera.
     * 
     * @param center Centro de la esfera.
     * @param radius Radio de la esfera.
     * @param color Color de la esfera.
     * @param specular Coeficiente de reflexión especular.
     * @param reflectivity Coeficiente de reflectividad de la esfera.
     */
    Sphere(const Vector3D& center, double radius, const Vector3D& color, double specular, double reflectivity);

    /**
     * @brief Método para comprobar si un rayo intersecta la esfera.
     * 
     * @param ray Rayo con el que se verifica la intersección.
     * @param t Parámetro que indica la distancia a la intersección más cercana.
     * @return true si el rayo intersecta la esfera, false en caso contrario.
     */
    bool intersects(const Ray& ray, double& t) const;

    /**
     * @brief Método para obtener la normal en un punto específico de la esfera.
     * 
     * @param point Punto en la superficie de la esfera.
     * @return Vector normal en el punto especificado.
     */
    Vector3D getNormal(const Vector3D& point) const;

    // Getters para las propiedades de la esfera
    Vector3D getColor() const;        // Obtener el color de la esfera.
    double getSpecular() const;       // Obtener el coeficiente especular.
    double getReflectivity() const;   // Obtener el coeficiente de reflectividad.

private:
    Vector3D center;       // Centro de la esfera.
    double radius;         // Radio de la esfera.
    Vector3D color;        // Color de la esfera.
    double specular;       // Coeficiente de reflexión especular.
    double reflectivity;   // Coeficiente de reflectividad.
};

#endif // SPHERE_H
