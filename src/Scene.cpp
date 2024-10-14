#include "Scene.h"
#include "Triangle.h"
#include "Plane.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Sphere.h"
#include "utils.h"
#include <limits> // Para std::numeric_limits
#include <cmath> // Para std::pow

// Método para agregar un triángulo a la escena
void Scene::addTriangle(const Triangle& triangle) {
    triangles.push_back(triangle);
}

// Método para agregar un plano a la escena
void Scene::addPlane(const Plane& plane) {
    planes.push_back(plane);
}

// Método para agregar una fuente de luz a la escena
void Scene::addLight(const LightSource& light) {
    lights.push_back(light);
}

// Método para agregar una esfera a la escena
void Scene::addSphere(const Sphere& sphere) {
    spheres.push_back(sphere);
}

/**
 * @brief Método para determinar si un rayo intersecta algún objeto en la escena.
 * 
 * Este método evalúa si un rayo intersecta con cualquiera de los objetos en la escena
 * (triángulos, planos o esferas) y determina el punto de intersección más cercano.
 * 
 * @param ray Rayo que se está evaluando.
 * @param hitPoint Punto donde el rayo intersecta el objeto más cercano.
 * @param normal Normal en el punto de intersección.
 * @return true si hay una intersección, false si no.
 */
bool Scene::intersects(const Ray& ray, Vector3D& hitPoint, Vector3D& normal) const {
    double closest_t = std::numeric_limits<double>::infinity();
    bool hit = false;

    // Verificar intersección con todos los triángulos
    for (const auto& triangle : triangles) {
        double t;
        Vector3D intersectionPoint;
        if (triangle.intersects(ray, t, intersectionPoint) && t < closest_t) {
            closest_t = t;
            hitPoint = intersectionPoint;
            normal = triangle.getNormal();
            hit = true;
        }
    }

    // Verificar intersección con todos los planos
    for (const auto& plane : planes) {
        double t;
        Vector3D intersectionPoint;
        if (plane.intersects(ray, t, intersectionPoint) && t < closest_t) {
            closest_t = t;
            hitPoint = intersectionPoint;
            normal = plane.getNormal();
            hit = true;
        }
    }

    // Verificar intersección con todas las esferas
    for (const auto& sphere : spheres) {
        double t;
        if (sphere.intersects(ray, t) && t < closest_t) {
            closest_t = t;
            hitPoint = ray.getOrigin() + ray.getDirection() * t;  // Calcular el punto de intersección
            normal = sphere.getNormal(hitPoint);  // Calcular la normal en el punto de intersección
            hit = true;
        }
    }

    return hit;
}

/**
 * @brief Traza un rayo en la escena para determinar el color resultante de un píxel.
 * 
 * Este método sigue el rayo hasta que encuentra un objeto o se escapa de la escena.
 * Si el rayo golpea un objeto, se calculan las contribuciones de iluminación y reflexión,
 * incluyendo las reflexiones múltiples hasta un límite determinado.
 * 
 * @param ray Rayo que se está trazando.
 * @param depth Profundidad de reflexión máxima permitida.
 * @return Color calculado del píxel (Vector3D).
 */
Vector3D Scene::traceRay(const Ray& ray, int depth) const {
    Vector3D closestPoint, normal;
    double closestT = std::numeric_limits<double>::infinity();
    const Triangle* closestTriangle = nullptr;
    const Plane* closestPlane = nullptr;
    const Sphere* closestSphere = nullptr;

    // Buscar la intersección más cercana con los triángulos
    for (const auto& triangle : triangles) {
        double t;
        Vector3D intersectionPoint;
        if (triangle.intersects(ray, t, intersectionPoint) && t < closestT) {
            closestT = t;
            closestPoint = intersectionPoint;
            normal = triangle.getNormal();
            closestTriangle = &triangle;
            closestPlane = nullptr;
            closestSphere = nullptr;
        }
    }

    // Buscar la intersección más cercana con los planos
    for (const auto& plane : planes) {
        double t;
        Vector3D intersectionPoint;
        if (plane.intersects(ray, t, intersectionPoint) && t < closestT) {
            closestT = t;
            closestPoint = intersectionPoint;
            normal = plane.getNormal();
            closestPlane = &plane;
            closestTriangle = nullptr;
            closestSphere = nullptr;
        }
    }

    // Buscar la intersección más cercana con las esferas
    for (const auto& sphere : spheres) {
        double t;
        if (sphere.intersects(ray, t) && t < closestT) {
            closestT = t;
            closestPoint = ray.getOrigin() + ray.getDirection() * t;  // Calcular el punto de intersección
            normal = sphere.getNormal(closestPoint);  // Calcular la normal en el punto de intersección
            closestSphere = &sphere;
            closestTriangle = nullptr;
            closestPlane = nullptr;
        }
    }

    // Si no hay ninguna intersección, devolvemos el color de fondo (negro)
    if (!closestTriangle && !closestPlane && !closestSphere) {
        return Vector3D(0, 0, 0);
    }

    // Determinar cuál fue el objeto intersectado y calcular el color local
    Vector3D viewDirection = ray.getDirection() * -1;
    double intensity;
    Vector3D localColor;

    if (closestTriangle) {
        intensity = computeLighting(closestPoint, normal, viewDirection, closestTriangle->getSpecular());
        localColor = closestTriangle->getColor() * intensity;
    } else if (closestPlane) {
        intensity = computeLighting(closestPoint, normal, viewDirection, closestPlane->getSpecular());
        localColor = closestPlane->getColor() * intensity;
    } else if (closestSphere) {
        intensity = computeLighting(closestPoint, normal, viewDirection, closestSphere->getSpecular());
        localColor = closestSphere->getColor() * intensity;
    }

    // Manejar la reflexión
    double reflectivity = closestTriangle ? closestTriangle->getReflectivity() :
                          closestPlane ? closestPlane->getReflectivity() : closestSphere->getReflectivity();

    if (depth <= 0 || reflectivity <= 0) {
        return localColor;
    }

    // Calcular el rayo reflejado
    Vector3D reflectionDirection = reflectRay(viewDirection, normal);
    Ray reflectedRay(closestPoint + normal * 1e-4, reflectionDirection); // Pequeño desplazamiento para evitar la auto-intersección

    Vector3D reflectedColor = traceRay(reflectedRay, depth - 1);
    Vector3D finalColor = localColor * (1 - reflectivity) + reflectedColor * reflectivity;

    return finalColor;
}

/**
 * @brief Calcula la iluminación en un punto específico de la escena.
 * 
 * Este método calcula la iluminación en un punto basado en la contribución de diferentes fuentes de luz,
 * considerando componentes difusas y especulares.
 * 
 * @param point Punto donde se calcula la iluminación.
 * @param normal Normal en el punto.
 * @param viewDirection Dirección hacia la cámara.
 * @param specular Valor especular del material.
 * @return Intensidad de la iluminación en el punto (0.0 a 1.0).
 */
double Scene::computeLighting(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDirection, int specular) const {
    double totalIntensity = 0.0;

    for (const auto& light : lights) {
        Vector3D lightDirection;
        double t_max;

        // Determinar dirección de la luz y la distancia máxima en función del tipo de luz
        if (light.getType() == LightSource::AMBIENT) {
            totalIntensity += light.getIntensity();
            continue;
        } else if (light.getType() == LightSource::POINT) {
            lightDirection = (light.getPosition() - point).normalize();
            t_max = 1.0;
        } else if (light.getType() == LightSource::DIRECTIONAL) {
            lightDirection = light.getDirection().normalize();
            t_max = std::numeric_limits<double>::infinity();
        }

        // Comprobar si el punto está en sombra
        if (isInShadow(point, lightDirection, t_max)) {
            continue;
        }

        // Componente difusa
        double n_dot_l = normal.dot(lightDirection);
        if (n_dot_l > 0) {
            totalIntensity += light.getIntensity() * n_dot_l;
        }

        // Componente especular
        if (specular != -1) {
            Vector3D reflectDir = reflectRay(lightDirection * -1, normal);
            double r_dot_v = reflectDir.dot(viewDirection);
            if (r_dot_v > 0) {
                totalIntensity += light.getIntensity() * std::pow(r_dot_v, specular);
            }
        }
    }

    return std::min(totalIntensity, 1.0); // Limitar la intensidad a un máximo de 1.0
}

/**
 * @brief Determina si un punto está en sombra.
 * 
 * Este método traza un rayo desde el punto hacia la fuente de luz para determinar si hay
 * algún objeto bloqueando la luz, en cuyo caso el punto estaría en sombra.
 * 
 * @param point Punto a evaluar.
 * @param lightDirection Dirección hacia la fuente de luz.
 * @param t_max Máxima distancia para buscar intersección.
 * @return true si el punto está en sombra, false si no lo está.
 */
bool Scene::isInShadow(const Vector3D& point, const Vector3D& lightDirection, double t_max) const {
    Vector3D offsetPoint = point + lightDirection * 1e-4; // Pequeño desplazamiento para evitar auto-sombreado
    Ray shadowRay(offsetPoint, lightDirection);

    // Verificar intersección con triángulos
    for (const auto& triangle : triangles) {
        double t;
        Vector3D intersectionPoint;
        if (triangle.intersects(shadowRay, t, intersectionPoint) && t > 1e-4 && t < t_max) {
            return true; // Si se encuentra una intersección, el punto está en sombra
        }
    }

    // Verificar intersección con planos
    for (const auto& plane : planes) {
        double t;
        Vector3D intersectionPoint;
        if (plane.intersects(shadowRay, t, intersectionPoint) && t > 1e-4 && t < t_max) {
            return true; // Si se encuentra una intersección, el punto está en sombra
        }
    }

    // Verificar intersección con esferas
    for (const auto& sphere : spheres) {
        double t;
        if (sphere.intersects(shadowRay, t) && t > 1e-4 && t < t_max) {
            return true; // Si se encuentra una intersección, el punto está en sombra
        }
    }

    return false; // No se encontraron intersecciones, el punto no está en sombra
}
