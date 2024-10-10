#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector3D {
public:
    Vector3D(double x, double y, double z); // Constructor que inicializa con valores x, y, z
    Vector3D(); // Constructor por defecto que inicializa a (0, 0, 0)

    double getX() const; // Getter para el componente x
    double getY() const; // Getter para el componente y
    double getZ() const; // Getter para el componente z
    double get(int index) const; // Método para obtener el componente en la posición 'index'

    double norm() const; // Método para calcular la norma del vector
    Vector3D normalize() const; // Método para normalizar el vector
    double angle(const Vector3D& other) const; // Método para calcular el ángulo entre dos vectores
    Vector3D project(const Vector3D& other) const; // Método para proyectar el vector sobre otro
    double dot(const Vector3D& other) const; // Producto punto entre dos vectores (método miembro)

    Vector3D& operator +=(const Vector3D& other); // Sobrecarga del operador +=
    Vector3D& operator -=(const Vector3D& other); // Sobrecarga del operador -=
    Vector3D& operator *=(double scalar); // Sobrecarga del operador *= con escalar

    // Declaración de funciones amigas
    friend std::ostream& operator <<(std::ostream&, const Vector3D&); // Sobrecarga para imprimir el vector
    friend Vector3D operator +(double, Vector3D); // Suma escalar con un vector
    friend Vector3D operator -(double, Vector3D); // Resta escalar con un vector
    friend Vector3D operator *(double, Vector3D); // Multiplicación escalar con un vector
    friend Vector3D operator *(const Vector3D&, double); // Multiplicación escalar (lado derecho)
    friend Vector3D operator +(const Vector3D&, const Vector3D&); // Suma de vectores
    friend Vector3D operator -(const Vector3D&, const Vector3D&); // Resta de vectores
    friend double operator *(const Vector3D& v1, const Vector3D& v2); // Producto punto de dos vectores
    friend Vector3D cross(const Vector3D&, const Vector3D&); // Producto cruzado
    friend bool operator ==(const Vector3D&, const Vector3D&); // Comparación de igualdad
    friend bool operator !=(const Vector3D&, const Vector3D&); // Comparación de desigualdad

private:
    double v[3]; // Array que contiene los componentes x, y, z del vector
};

#endif // VECTOR3D_H
