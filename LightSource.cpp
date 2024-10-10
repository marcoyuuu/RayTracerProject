#include "LightSource.h"

// Constructor que inicializa el tipo, intensidad, posición y dirección de la luz
LightSource::LightSource(Type type, double intensity, const Vector3D& position, const Vector3D& direction)
    : type(type), intensity(intensity), position(position), direction(direction) {}

// Obtener el tipo de la luz
LightSource::Type LightSource::getType() const {
    return type;
}

// Obtener la intensidad de la luz
double LightSource::getIntensity() const {
    return intensity;
}

// Obtener la posición de la luz
Vector3D LightSource::getPosition() const {
    return position;
}

// Obtener la dirección de la luz
Vector3D LightSource::getDirection() const {
    return direction;
}
