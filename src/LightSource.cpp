#include "LightSource.h"

/**
 * Constructor que inicializa el tipo, intensidad, posición y dirección de la luz.
 *
 * @param type: Tipo de luz (AMBIENT, POINT, DIRECTIONAL).
 * @param intensity: Intensidad de la luz.
 * @param position: Posición de la luz (solo relevante para luz tipo POINT).
 * @param direction: Dirección de la luz (solo relevante para luz tipo DIRECTIONAL).
 */
LightSource::LightSource(Type type, double intensity, const Vector3D& position, const Vector3D& direction)
    : type(type), intensity(intensity), position(position), direction(direction) {}

/**
 * @brief Obtiene el tipo de la luz.
 * @return Tipo de la luz.
 */
LightSource::Type LightSource::getType() const {
    return type;
}

/**
 * @brief Obtiene la intensidad de la luz.
 * @return Intensidad de la luz.
 */
double LightSource::getIntensity() const {
    return intensity;
}

/**
 * @brief Obtiene la posición de la luz.
 * @return Posición de la luz.
 */
Vector3D LightSource::getPosition() const {
    return position;
}

/**
 * @brief Obtiene la dirección de la luz.
 * @return Dirección de la luz.
 */
Vector3D LightSource::getDirection() const {
    return direction;
}
