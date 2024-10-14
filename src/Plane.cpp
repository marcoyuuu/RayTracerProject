#include "Plane.h"
#include <limits> // Para std::numeric_limits
#include <cmath>  // Para fabs

/**
 * @brief Constructor para inicializar el plano con un punto, normal, color, valor especular y reflectividad.
 * 
 * @param point Un punto sobre el plano.
 * @param normal Vector normal al plano.
 * @param color Color del plano.
 * @param specular Valor especular del plano.
 * @param reflectivity Reflectividad del plano.
 */
Plane::Plane(const Vector3D& point, const Vector3D& normal, const Vector3D& color, double specular, double reflectivity)
    : point(point), normal(normal.normalize()), color(color), specular(specular), reflectivity(reflectivity) {}

/**
 * @brief Método para comprobar si un rayo intersecta con el plano y calcular el punto de intersección.
 * 
 * @param ray Rayo a comprobar.
 * @param t Distancia desde el origen del rayo hasta el punto de intersección.
 * @param intersectionPoint Punto de intersección si existe.
 * @return true Si el rayo intersecta el plano.
 * @return false Si el rayo no intersecta el plano.
 */
bool Plane::intersects(const Ray& ray, double& t, Vector3D& intersectionPoint) const {
    double denom = normal.dot(ray.getDirection());

    // Si el denominador es cercano a cero, el rayo es paralelo al plano
    if (fabs(denom) < 1e-6) {
        return false;
    }

    double t_temp = (point - ray.getOrigin()).dot(normal) / denom;

    // Si t es negativo, el plano está detrás del rayo
    if (t_temp < 1e-6) {
        return false;
    }

    t = t_temp;
    intersectionPoint = ray.getOrigin() + ray.getDirection() * t;
    return true;
}

/**
 * @brief Getter para obtener el color del plano.
 * @return Color del plano como un Vector3D.
 */
Vector3D Plane::getColor() const {
    return color;
}

/**
 * @brief Getter para obtener el valor especular del plano.
 * @return Valor especular del plano.
 */
double Plane::getSpecular() const {
    return specular;
}

/**
 * @brief Getter para obtener el coeficiente de reflectividad del plano.
 * @return Reflectividad del plano.
 */
double Plane::getReflectivity() const {
    return reflectivity;
}

/**
 * @brief Getter para obtener el vector normal del plano.
 * @return Vector normal del plano.
 */
Vector3D Plane::getNormal() const {
    return normal;
}
