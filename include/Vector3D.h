#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * @brief Clase para representar un vector en 3 dimensiones.
 */
class Vector3D {
public:
    /**
     * @brief Constructor que inicializa el vector con los valores dados x, y, z.
     * @param x Componente x del vector.
     * @param y Componente y del vector.
     * @param z Componente z del vector.
     */
    Vector3D(double x, double y, double z);

    /**
     * @brief Constructor por defecto que inicializa el vector a (0, 0, 0).
     */
    Vector3D();

    /**
     * @brief Obtiene el componente x del vector.
     * @return Valor del componente x.
     */
    double getX() const;

    /**
     * @brief Obtiene el componente y del vector.
     * @return Valor del componente y.
     */
    double getY() const;

    /**
     * @brief Obtiene el componente z del vector.
     * @return Valor del componente z.
     */
    double getZ() const;

    /**
     * @brief Calcula la norma (magnitud) del vector.
     * @return La norma del vector.
     */
    double norm() const;

    /**
     * @brief Normaliza el vector.
     * @return Un nuevo vector con la misma dirección pero de norma unitaria.
     * @throws std::runtime_error Si el vector es un vector cero y no puede ser normalizado.
     */
    Vector3D normalize() const;

    /**
     * @brief Calcula el producto punto entre este vector y otro.
     * @param other Otro vector con el cual calcular el producto punto.
     * @return Resultado del producto punto.
     */
    double dot(const Vector3D& other) const;

    /**
     * @brief Calcula el producto cruzado entre este vector y otro.
     * @param other Otro vector con el cual calcular el producto cruzado.
     * @return Un nuevo vector resultado del producto cruzado.
     */
    Vector3D cross(const Vector3D& other) const;

    // Sobrecarga de operadores para operaciones aritméticas con vectores

    /**
     * @brief Suma este vector con otro.
     * @param other Otro vector a sumar.
     * @return Un nuevo vector resultado de la suma.
     */
    Vector3D operator +(const Vector3D& other) const;

    /**
     * @brief Resta otro vector de este vector.
     * @param other Otro vector a restar.
     * @return Un nuevo vector resultado de la resta.
     */
    Vector3D operator -(const Vector3D& other) const;

    /**
     * @brief Multiplica este vector por un escalar.
     * @param scalar Valor escalar por el cual multiplicar.
     * @return Un nuevo vector resultado de la multiplicación.
     */
    Vector3D operator *(double scalar) const;

    /**
     * @brief Calcula el producto punto entre este vector y otro.
     * @param other Otro vector con el cual calcular el producto punto.
     * @return Resultado del producto punto.
     */
    double operator *(const Vector3D& other) const;

    /**
     * @brief Realiza la negación de este vector.
     * @return Un nuevo vector con todos sus componentes negados.
     */
    Vector3D operator -() const;

    // Funciones amigas

    /**
     * @brief Suma un vector y un escalar.
     * @param vector El vector a sumar.
     * @param scalar El valor escalar a sumar.
     * @return Un nuevo vector resultado de la suma.
     */
    friend Vector3D operator +(const Vector3D& vector, double scalar);

    /**
     * @brief Suma un escalar y un vector.
     * @param scalar El valor escalar a sumar.
     * @param vector El vector a sumar.
     * @return Un nuevo vector resultado de la suma.
     */
    friend Vector3D operator +(double scalar, const Vector3D& vector);

    /**
     * @brief Sobrecarga del operador << para imprimir un vector.
     * @param out Flujo de salida.
     * @param obj El vector a imprimir.
     * @return El flujo de salida.
     */
    friend std::ostream& operator <<(std::ostream& out, const Vector3D& obj);

private:
    double v[3]; ///< Array que contiene los componentes x, y, z del vector.
};

#endif // VECTOR3D_H
