#include "Triangle.h"
#include "Vector3D.h"
#include "Ray.h"
#include <cmath> // Para fabs y otras operaciones matemáticas

// Constructor que inicializa los vértices del triángulo
Triangle::Triangle(const Vector3D& a, const Vector3D& b, const Vector3D& c) : a(a), b(b), c(c) {}

// Método para comprobar si un rayo intersecta con el triángulo mediante el algoritmo de intersección de rayos con triángulos de Möller-Trumbore
bool Triangle::intersects(const Ray& ray, double& t) const {
    // Calculamos los vectores de los lados del triángulo a-b y a-c
    Vector3D edge1 = b - a;
    Vector3D edge2 = c - a;

    // Calculamos el producto cruzado entre la dirección del rayo y el vector edge2
    Vector3D h = cross(ray.getDirection(), edge2);
    // Calculamos el producto punto entre edge1 y el vector h
    double det = edge1 * h;

    // Si el determinante es cercano a cero, el rayo no intersecta con el triángulo
    if (fabs(det) < 1e-6) {
        return false;
    }

    //  Calculamos el inverso del determinante (det)
    double invDet = 1.0 / det;
    // Calculamos el vector s que va desde el origen del rayo (ray.getOrigin()) hasta el vértice a del triángulo
    Vector3D s = ray.getOrigin() - a;
    // Calculamos el parámetro u, que representa cuánto ha avanzado el punto de intersección a lo largo del lado edge1 del triángulo
    double u = (s * h) * invDet;

    // Comprobamos si la intersección está fuera del triángulo
    if (u < 0.0 || u > 1.0) {
        return false;
    }

    // Calculamos el producto cruzado entre s y edge1
    Vector3D q = cross(s, edge1);
    // Calculamos el parámetro v, que representa cuánto ha avanzado el punto de intersección a lo largo del lado edge2
    double v = (ray.getDirection() * q) * invDet;

    // Comprobamos si la intersección está fuera del triángulo
    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    // Calcular t para comprobar la distancia al plano de intersección
    double t = (edge2 * q) * invDet;

    if (t > 1e-6) { // Si t es mayor que cero, el rayo intersecta con el triángulo
        return true;
    }

    return false; // Si t es menor o igual a cero, no hay intersección
}

// Método para obtener la normal del triángulo
Vector3D Triangle::getNormal() const {
    Vector3D edge1 = b - a;
    Vector3D edge2 = c - a;
    Vector3D normal = cross(edge1, edge2);
    return normal.normalize(); // Devuelve la normal normalizada para que tenga longitud 1
}

double Triangle::getSpecular() const {
    return specular;
}

Vector3D Triangle::getColor() const {
    return color;
}

double Triangle::getReflectivity() const {
    return reflectivity;
}
