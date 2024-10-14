// Triangle.cpp
#include "Triangle.h"
#include "Vector3D.h"
#include "Ray.h"
#include <cmath> // Para fabs y otras funciones matemáticas

/**
 * @brief Constructor que inicializa los vértices del triángulo, color, valor especular y reflectividad.
 * 
 * @param a Primer vértice del triángulo.
 * @param b Segundo vértice del triángulo.
 * @param c Tercer vértice del triángulo.
 * @param color Color del triángulo.
 * @param specular Valor de reflexión especular.
 * @param reflectivity Coeficiente de reflectividad del material.
 */
Triangle::Triangle(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& color, double specular, double reflectivity)
    : a(a), b(b), c(c), color(color), specular(specular), reflectivity(reflectivity) {}

/**
 * @brief Método para comprobar si un rayo intersecta con el triángulo.
 * 
 * Utiliza el algoritmo de intersección de Möller-Trumbore para determinar si existe una intersección
 * entre un rayo y el triángulo, y en caso afirmativo, calcula el punto de intersección.
 * 
 * @param ray Rayo con el que se verifica la intersección.
 * @param t Parámetro que indica la distancia al punto de intersección más cercano.
 * @param intersectionPoint Punto de intersección calculado si existe.
 * @return true si el rayo intersecta el triángulo, false en caso contrario.
 */
bool Triangle::intersects(const Ray& ray, double& t, Vector3D& intersectionPoint) const {
    Vector3D edge1 = b - a;
    Vector3D edge2 = c - a;

    // Calcular el producto cruzado entre la dirección del rayo y el edge2
    Vector3D h = ray.getDirection().cross(edge2);
    double det = edge1.dot(h);

    // Si el determinante es cercano a cero, el rayo es paralelo al triángulo
    if (fabs(det) < 1e-5) {
        return false;
    }

    double invDet = 1.0 / det;
    Vector3D s = ray.getOrigin() - a;
    double u = invDet * s.dot(h);

    // Verificar si el valor de u está dentro del rango aceptable (0 <= u <= 1)
    if (u < 0.0 || u > 1.0) {
        return false;
    }

    Vector3D q = s.cross(edge1);
    double v = invDet * ray.getDirection().dot(q);

    // Verificar si el valor de v está dentro del rango aceptable y que u + v <= 1
    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    t = invDet * edge2.dot(q);

    // Si t es mayor que un pequeño umbral, la intersección es válida
    if (t > 1e-6) {
        intersectionPoint = ray.getOrigin() + ray.getDirection() * t; // Calcular el punto de intersección real
        return true;
    }

    return false; // No hay intersección válida
}

/**
 * @brief Método para obtener el vector normal del triángulo.
 * 
 * El vector normal se calcula como el producto cruzado entre dos lados del triángulo.
 * Luego se normaliza para obtener un vector unitario.
 * 
 * @return Vector normal del triángulo.
 */
Vector3D Triangle::getNormal() const {
    Vector3D edge1 = b - a;
    Vector3D edge2 = c - a;
    Vector3D normal = edge1.cross(edge2); // Producto cruzado para obtener la normal
    return normal.normalize();            // Devolver el vector normalizado
}

/**
 * @brief Método para obtener el valor especular del triángulo.
 * 
 * @return Valor especular del material.
 */
double Triangle::getSpecular() const {
    return specular;
}

/**
 * @brief Método para obtener el color del triángulo.
 * 
 * @return Color del triángulo representado como un objeto Vector3D.
 */
Vector3D Triangle::getColor() const {
    return color;
}

/**
 * @brief Método para obtener la reflectividad del triángulo.
 * 
 * @return Reflectividad del material del triángulo.
 */
double Triangle::getReflectivity() const {
    return reflectivity;
}
