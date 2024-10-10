#include "Vector3D.h"

// Constructor que inicializa el vector con los valores dados x, y, z
Vector3D::Vector3D(double x, double y, double z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

// Constructor por defecto que inicializa el vector a (0, 0, 0)
Vector3D::Vector3D() : v{0,0,0} { }

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

double Vector3D::get(int index) const {
    if (index < 0 || index > 2) {
        throw std::out_of_range("Index out of bounds");
    }
    return v[index];
}

// Método para calcular la norma del vector
double Vector3D::norm() const {
    return sqrt((*this).dot(*this));
}

// Método para normalizar el vector
Vector3D Vector3D::normalize() const {
    double mag = norm();
    if (mag == 0) {
        throw std::runtime_error("Cannot normalize a zero vector");
    }
    return Vector3D(v[0] / mag, v[1] / mag, v[2] / mag);
}

// Método para calcular el ángulo entre dos vectores
double Vector3D::angle(const Vector3D& other) const {
    double dotProd = this->dot(other);
    double norms = this->norm() * other.norm();
    return acos(dotProd / norms);
}

// Método para proyectar este vector sobre otro
Vector3D Vector3D::project(const Vector3D& other) const {
    double scalar = (this->dot(other)) / (other.dot(other));
    return scalar * other;
}

// Producto punto entre dos vectores
double Vector3D::dot(const Vector3D& other) const {
    return v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2];
}

// Sobrecarga del operador +=
Vector3D& Vector3D::operator +=(const Vector3D& other) {
    v[0] += other.v[0];
    v[1] += other.v[1];
    v[2] += other.v[2];
    return *this;
}

// Sobrecarga del operador -=
Vector3D& Vector3D::operator -=(const Vector3D& other) {
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    v[2] -= other.v[2];
    return *this;
}

// Sobrecarga del operador *= con escalar
Vector3D& Vector3D::operator *=(double scalar) {
    v[0] *= scalar;
    v[1] *= scalar;
    v[2] *= scalar;
    return *this;
}

// Implementación de funciones amigas

// Sobrecarga del operador << para imprimir Vector3D
std::ostream& operator <<(std::ostream& out, const Vector3D& obj) {
    out << "<" << obj.v[0] << ", " << obj.v[1] << ", " << obj.v[2] << ">";
    return out;
}

// Sobrecarga de la multiplicación escalar
Vector3D operator *(double scalar, Vector3D obj) {
    return Vector3D(scalar * obj.v[0], scalar * obj.v[1], scalar * obj.v[2]);
}

// Sobrecarga de la multiplicación escalar (lado derecho)
Vector3D operator *(const Vector3D& obj, double scalar) {
    return Vector3D(scalar * obj.v[0], scalar * obj.v[1], scalar * obj.v[2]);
}

// Sobrecarga para el producto punto
double operator *(const Vector3D& v1, const Vector3D& v2) {
    return v1.get(0) * v2.get(0) + v1.get(1) * v2.get(1) + v1.get(2) * v2.get(2);
}

// Sobrecarga para suma escalar
Vector3D operator +(double scalar, Vector3D obj) {
    return Vector3D(scalar + obj.v[0], scalar + obj.v[1], scalar + obj.v[2]);
}

// Sobrecarga para resta escalar
Vector3D operator -(double scalar, Vector3D obj) {
    return Vector3D(scalar - obj.v[0], scalar - obj.v[1], scalar - obj.v[2]);
}

// Sobrecarga para suma de vectores
Vector3D operator +(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.get(0) + v2.get(0), v1.get(1) + v2.get(1), v1.get(2) + v2.get(2));
}

// Sobrecarga para resta de vectores
Vector3D operator -(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.get(0) - v2.get(0), v1.get(1) - v2.get(1), v1.get(2) - v2.get(2));
}

// Producto cruzado
Vector3D cross(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(
        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]
    );
}

// Comparación de igualdad
bool operator ==(const Vector3D& v1, const Vector3D& v2) {
    double epsilon = 1e-6;
    return (fabs(v1.v[0] - v2.v[0]) < epsilon) &&
           (fabs(v1.v[1] - v2.v[1]) < epsilon) &&
           (fabs(v1.v[2] - v2.v[2]) < epsilon);
}

// Comparación de desigualdad
bool operator !=(const Vector3D& v1, const Vector3D& v2) {
    return !(v1 == v2);
}
