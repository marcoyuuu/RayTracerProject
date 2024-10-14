#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <vector>
#include "Vector3D.h"

/**
 * Clase que representa una fuente de luz en la escena.
 */
class LightSource {
public:
    /**
     * Tipo de luz.
     * - AMBIENT: Luz ambiente que afecta a todos los objetos de manera uniforme.
     * - POINT: Luz que emana de un punto específico en todas las direcciones.
     * - DIRECTIONAL: Luz que proviene de una dirección específica, como el sol.
     */
    enum Type { AMBIENT, POINT, DIRECTIONAL };
    
    /**
     * Constructor que inicializa la fuente de luz.
     * 
     * @param type: Tipo de luz (AMBIENT, POINT, DIRECTIONAL).
     * @param intensity: Intensidad de la luz.
     * @param position: Posición de la luz, solo para luz tipo POINT (valor por defecto Vector3D()).
     * @param direction: Dirección de la luz, solo para luz tipo DIRECTIONAL (valor por defecto Vector3D()).
     */
    LightSource(Type type, double intensity, const Vector3D& position = Vector3D(), const Vector3D& direction = Vector3D());

    /**
     * @brief Devuelve el tipo de luz.
     * @return Tipo de la luz.
     */
    Type getType() const;

    /**
     * @brief Devuelve la intensidad de la luz.
     * @return Intensidad de la luz.
     */
    double getIntensity() const;

    /**
     * @brief Devuelve la posición de la luz (si aplica).
     * @return Posición de la luz.
     */
    Vector3D getPosition() const;

    /**
     * @brief Devuelve la dirección de la luz (si aplica).
     * @return Dirección de la luz.
     */
    Vector3D getDirection() const;

private:
    Type type;                // Tipo de luz (AMBIENT, POINT, DIRECTIONAL)
    double intensity;         // Intensidad de la luz
    Vector3D position;        // Posición de la luz, aplicable a luz tipo POINT
    Vector3D direction;       // Dirección de la luz, aplicable a luz tipo DIRECTIONAL
};

#endif // LIGHTSOURCE_H
