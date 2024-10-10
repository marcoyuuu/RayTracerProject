#include "utils.h"

Vector3D reflectRay(const Vector3D& incident, const Vector3D& normal) {
    return normal * 2 * (normal.dot(incident)) - incident;
}
