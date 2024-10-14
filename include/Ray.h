#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

/**
 * @brief Clase que representa un rayo en el espacio 3D.
 */
class Ray {
public:
    /**
     * @brief Constructor que inicializa el rayo con un origen y una dirección.
     * 
     * @param origin Punto de origen del rayo.
     * @param direction Dirección del rayo.
     */
    Ray(const Vector3D& origin, const Vector3D& direction);

    /**
     * @brief Método para obtener el origen del rayo.
     * @return Vector3D que representa el origen del rayo.
     */
    Vector3D getOrigin() const;

    /**
     * @brief Método para obtener la dirección del rayo.
     * @return Vector3D que representa la dirección del rayo.
     */
    Vector3D getDirection() const;

private:
    Vector3D origin;     ///< Origen del rayo.
    Vector3D direction;  ///< Dirección del rayo, siempre normalizada.
};

#endif // RAY_H
