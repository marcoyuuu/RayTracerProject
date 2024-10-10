#include "Scene.h"
#include "Triangle.h"
#include "Ray.h"
#include "Vector3D.h"
#include "utils.h"
#include <limits> // Para std::numeric_limits

// Método para añadir un triángulo a la escena
void Scene::addTriangle(const Triangle& triangle) {
    triangles.push_back(triangle);
}

// Método para añadir una fuente de luz a la escena
void Scene::addLight(const LightSource& light) {
    lights.push_back(light);
}

// Método para comprobar si un rayo intersecta con algún objeto en la escena
bool Scene::intersects(const Ray& ray, Vector3D& hitPoint, Vector3D& normal) const {
    double closest_t = std::numeric_limits<double>::infinity();
    bool hit = false;

    // Iterar sobre todos los triángulos de la escena
    for (const auto& triangle : triangles) {
        double t; // Variable para almacenar la distancia al punto de intersección
        if (triangle.intersects(ray, t)) {
            // Si hay una intersección y es la más cercana hasta ahora
            if (t < closest_t) {
                closest_t = t;
                hit = true;

                // Calcular el punto de intersección
                hitPoint = ray.getOrigin() + ray.getDirection() * t;

                // Obtener la normal del triángulo en el punto de intersección
                normal = triangle.getNormal();
            }
        }
    }

    return hit;
}

// Método para trazar el rayo y calcular el color del píxel
Vector3D Scene::traceRay(const Ray& ray, int depth) const {
    Vector3D closestPoint, normal;
    double closestT = std::numeric_limits<double>::infinity();
    const Triangle* closestTriangle = nullptr;

    // Encuentra la intersección más cercana
    for (auto& triangle : triangles) {
        double t;
        if (triangle.intersects(ray, t) && t < closestT) {
            closestT = t;
            closestPoint = ray.getOrigin() + ray.getDirection() * t;
            normal = triangle.getNormal();
            closestTriangle = &triangle;
        }
    }

    if (!closestTriangle) {
        return Vector3D(0, 0, 0); // Color de fondo (negro)
    }

    // Calcular el color local (difuso y especular)
    Vector3D viewDirection = ray.getDirection() * -1;
    double intensity = computeLighting(closestPoint, normal, viewDirection, closestTriangle->getSpecular());
    Vector3D localColor = closestTriangle->getColor() * intensity;

    // Reflexión recursiva
    double reflectivity = closestTriangle->getReflectivity();
    if (depth <= 0 || reflectivity <= 0) {
        return localColor;
    }

    Vector3D reflectionDirection = reflectRay(ray.getDirection() * -1, normal);
    Ray reflectedRay(closestPoint, reflectionDirection);
    Vector3D reflectedColor = traceRay(reflectedRay, depth - 1);

    // Combinar color local y reflejado
    return localColor * (1 - reflectivity) + reflectedColor * reflectivity;
}


double Scene::computeLighting(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDirection, int specular) const {
    double intensity = 0.0;
    for (const auto& light : lights) {
        if (light.getType() == LightSource::AMBIENT) {
            intensity += light.getIntensity();
        } else {
            Vector3D lightDirection;
            double t_max;
            if (light.getType() == LightSource::POINT) {
                lightDirection = light.getPosition() - point;
                t_max = 1.0;
            } else {
                lightDirection = light.getDirection();
                t_max = std::numeric_limits<double>::infinity();
            }
            
            // Sombra: verificar si algún objeto está bloqueando la luz
            if (isInShadow(point, lightDirection, t_max)) {
                continue;
            }
            
            // Componente difusa
            double n_dot_l = normal.dot(lightDirection);
            if (n_dot_l > 0) {
                intensity += light.getIntensity() * n_dot_l / (normal.norm() * lightDirection.norm());
            }
            
            // Componente especular
            if (specular != -1) {
                Vector3D reflection = reflectRay(lightDirection * -1, normal);
                double r_dot_v = reflection.dot(viewDirection);
                if (r_dot_v > 0) {
                    intensity += light.getIntensity() * pow(r_dot_v / (reflection.norm() * viewDirection.norm()), specular);
                }
            }
        }
    }
    return intensity;
}

bool Scene::isInShadow(const Vector3D& point, const Vector3D& lightDirection, double t_max) const {
    Ray shadowRay(point, lightDirection);
    for (const auto& triangle : triangles) {
        double t;
        if (triangle.intersects(shadowRay, t) && t > 1e-4 && t < t_max) {
            return true; // Si hay una intersección, el punto está en la sombra
        }
    }
    return false; // Si no hay intersección, no hay sombra
}
