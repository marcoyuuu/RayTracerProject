// Sphere.cpp
#include "Sphere.h"
#include <cmath> // Para la función sqrt

/**
 * @brief Constructor que inicializa el centro, radio, color, valor especular y reflectividad de la esfera.
 * 
 * @param center Centro de la esfera.
 * @param radius Radio de la esfera.
 * @param color Color de la esfera.
 * @param specular Coeficiente de reflexión especular.
 * @param reflectivity Coeficiente de reflectividad de la esfera.
 */
Sphere::Sphere(const Vector3D& center, double radius, const Vector3D& color, double specular, double reflectivity)
    : center(center), radius(radius), color(color), specular(specular), reflectivity(reflectivity) {}

/**
 * @brief Método para comprobar si un rayo intersecta la esfera.
 * 
 * Este método utiliza la ecuación del rayo y la ecuación de la esfera para determinar
 * si existe una intersección. Si hay dos posibles intersecciones, se devuelve la más cercana y positiva.
 * 
 * @param ray Rayo con el que se verifica la intersección.
 * @param t Parámetro que indica la distancia a la intersección más cercana.
 * @return true si el rayo intersecta la esfera, false en caso contrario.
 */
bool Sphere::intersects(const Ray& ray, double& t) const {
    Vector3D originToCenter = ray.getOrigin() - center;

    // Coeficientes de la ecuación cuadrática
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2 * originToCenter.dot(ray.getDirection());
    double c = originToCenter.dot(originToCenter) - radius * radius;

    // Calcular el discriminante para verificar la existencia de soluciones
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false; // No hay intersección si el discriminante es negativo
    }

    // Calcular las dos posibles soluciones para la intersección
    double sqrtDiscriminant = sqrt(discriminant);
    double t1 = (-b - sqrtDiscriminant) / (2 * a);
    double t2 = (-b + sqrtDiscriminant) / (2 * a);

    // Queremos la intersección positiva más cercana
    if (t1 > 1e-4) { // Verificar si t1 es válida
        t = t1;
        return true;
    }
    if (t2 > 1e-4) { // Si t1 no es válida, verificar t2
        t = t2;
        return true;
    }

    return false; // No hay intersección válida
}

/**
 * @brief Método para obtener la normal en un punto específico de la esfera.
 * 
 * La normal se calcula como el vector desde el centro de la esfera hacia el punto especificado,
 * y luego se normaliza para que tenga una magnitud de 1.
 * 
 * @param point Punto en la superficie de la esfera.
 * @return Vector normal en el punto especificado.
 */
Vector3D Sphere::getNormal(const Vector3D& point) const {
    return (point - center).normalize();
}

/**
 * @brief Getter para obtener el color de la esfera.
 * 
 * @return Color de la esfera representado como un objeto Vector3D.
 */
Vector3D Sphere::getColor() const {
    return color;
}

/**
 * @brief Getter para obtener el coeficiente de reflexión especular de la esfera.
 * 
 * @return Coeficiente especular de la esfera.
 */
double Sphere::getSpecular() const {
    return specular;
}

/**
 * @brief Getter para obtener el coeficiente de reflectividad de la esfera.
 * 
 * @return Coeficiente de reflectividad de la esfera.
 */
double Sphere::getReflectivity() const {
    return reflectivity;
}
