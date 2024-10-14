#include "Vector3D.h"

// Constructor que inicializa el vector con los valores dados x, y, z
Vector3D::Vector3D(double x, double y, double z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

// Constructor por defecto que inicializa el vector a (0, 0, 0)
Vector3D::Vector3D() : v{0, 0, 0} { }

// Getter para el componente x
double Vector3D::getX() const {
    return v[0];
}

// Getter para el componente y
double Vector3D::getY() const {
    return v[1];
}

// Getter para el componente z
double Vector3D::getZ() const {
    return v[2];
}

// Método para calcular la norma del vector
double Vector3D::norm() const {
    return sqrt(this->dot(*this));
}

// Método para normalizar el vector
Vector3D Vector3D::normalize() const {
    double mag = norm();
    if (mag == 0) {
        throw std::runtime_error("Cannot normalize a zero vector");
    }
    return Vector3D(v[0] / mag, v[1] / mag, v[2] / mag);
}

// Producto punto entre dos vectores
double Vector3D::dot(const Vector3D& other) const {
    return v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2];
}

// Producto cruzado entre dos vectores
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        v[1] * other.v[2] - v[2] * other.v[1],
        v[2] * other.v[0] - v[0] * other.v[2],
        v[0] * other.v[1] - v[1] * other.v[0]
    );
}

// Sobrecarga del operador + para suma de vectores
Vector3D Vector3D::operator +(const Vector3D& other) const {
    return Vector3D(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
}

// Sobrecarga del operador - para resta de vectores
Vector3D Vector3D::operator -(const Vector3D& other) const {
    return Vector3D(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
}

// Sobrecarga del operador * para multiplicación escalar
Vector3D Vector3D::operator *(double scalar) const {
    return Vector3D(v[0] * scalar, v[1] * scalar, v[2] * scalar);
}

// Sobrecarga del operador * para producto punto entre dos vectores
double Vector3D::operator *(const Vector3D& other) const {
    return this->dot(other);
}

// Sobrecarga del operador unario - para negación
Vector3D Vector3D::operator -() const {
    return Vector3D(-v[0], -v[1], -v[2]);
}

// Sobrecarga del operador + para suma de vector y escalar
Vector3D operator +(const Vector3D& vector, double scalar) {
    return Vector3D(vector.v[0] + scalar, vector.v[1] + scalar, vector.v[2] + scalar);
}

Vector3D operator +(double scalar, const Vector3D& vector) {
    return vector + scalar;
}

// Implementación de funciones amigas

// Sobrecarga del operador << para imprimir Vector3D
std::ostream& operator <<(std::ostream& out, const Vector3D& obj) {
    out << "<" << obj.v[0] << ", " << obj.v[1] << ", " << obj.v[2] << ">";
    return out;
}
