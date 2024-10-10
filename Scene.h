#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Triangle.h"
#include "LightSource.h"
#include "Ray.h"
#include "Vector3D.h"

class Scene {
public:
    void addTriangle(const Triangle& triangle);
    void addLight(const LightSource& light);
    Vector3D traceRay(const Ray& ray, int depth) const;
    double computeLighting(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDirection, int specular) const;
    bool intersects(const Ray& ray, Vector3D& hitPoint, Vector3D& normal) const;
    bool isInShadow(const Vector3D& point, const Vector3D& lightDirection, double t_max) const;

private:
    std::vector<Triangle> triangles;
    std::vector<LightSource> lights;
};

#endif // SCENE_H
