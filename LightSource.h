#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <vector>
#include "Vector3D.h"

class LightSource {
public:
    enum Type { AMBIENT, POINT, DIRECTIONAL };
    
    LightSource(Type type, double intensity, const Vector3D& position = Vector3D(), const Vector3D& direction = Vector3D());

    Type getType() const;
    double getIntensity() const;
    Vector3D getPosition() const;
    Vector3D getDirection() const;

private:
    Type type;
    double intensity;
    Vector3D position;
    Vector3D direction;
};

#endif // LIGHTSOURCE_H
