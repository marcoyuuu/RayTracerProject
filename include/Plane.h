#ifndef PLANE_H
#define PLANE_H

#include "Vector3D.h"
#include "Ray.h"

/**
 * @brief Clase que representa un plano en la escena.
 */
class Plane {
public:
    /**
     * @brief Constructor que inicializa el plano con un punto y una normal.
     * 
     * @param point Un punto en el plano.
     * @param normal Vector normal al plano.
     * @param color Color del plano.
     * @param specular Valor especular del plano para cálculos de iluminación.
     * @param reflectivity Coeficiente de reflectividad del plano.
     */
    Plane(const Vector3D& point, const Vector3D& normal, const Vector3D& color, double specular, double reflectivity);

    /**
     * @brief Método para comprobar si un rayo intersecta el plano y proporcionar el punto de intersección.
     * 
     * @param ray Rayo con el que se verifica la intersección.
     * @param t Distancia desde el origen del rayo hasta el punto de intersección.
     * @param intersectionPoint Punto de intersección si la hay.
     * @return true Si hay una intersección válida.
     * @return false Si no hay intersección.
     */
    bool intersects(const Ray& ray, double& t, Vector3D& intersectionPoint) const;

    /**
     * @brief Getter para obtener el color del plano.
     * @return Vector3D que representa el color del plano.
     */
    Vector3D getColor() const;

    /**
     * @brief Getter para obtener el valor especular del plano.
     * @return Valor especular del plano.
     */
    double getSpecular() const;

    /**
     * @brief Getter para obtener el coeficiente de reflectividad del plano.
     * @return Coeficiente de reflectividad del plano.
     */
    double getReflectivity() const;

    /**
     * @brief Getter para obtener el vector normal del plano.
     * @return Vector normal del plano.
     */
    Vector3D getNormal() const;

private:
    Vector3D point;       ///< Un punto sobre el plano.
    Vector3D normal;      ///< Vector normal al plano.
    Vector3D color;       ///< Color del plano.
    double specular;      ///< Valor especular para los cálculos de iluminación.
    double reflectivity;  ///< Coeficiente de reflectividad para los cálculos de reflexión.
};

#endif // PLANE_H
