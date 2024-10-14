#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Triangle.h"
#include "Plane.h"
#include "LightSource.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Sphere.h"  // Incluir la clase Sphere

/**
 * @brief Clase que representa una escena compuesta por varios objetos y fuentes de luz.
 * 
 * La clase Scene permite agregar triángulos, planos, esferas y luces a la escena, y además proporciona
 * métodos para calcular la intersección de un rayo con los objetos de la escena y para calcular la iluminación.
 */
class Scene {
public:
    /**
     * @brief Agrega un triángulo a la escena.
     * @param triangle Triángulo a agregar.
     */
    void addTriangle(const Triangle& triangle);

    /**
     * @brief Agrega un plano a la escena.
     * @param plane Plano a agregar.
     */
    void addPlane(const Plane& plane);

    /**
     * @brief Agrega una fuente de luz a la escena.
     * @param light Fuente de luz a agregar.
     */
    void addLight(const LightSource& light);

    /**
     * @brief Agrega una esfera a la escena.
     * @param sphere Esfera a agregar.
     */
    void addSphere(const Sphere& sphere);

    /**
     * @brief Traza un rayo a través de la escena para determinar el color resultante.
     * @param ray Rayo a trazar.
     * @param depth Profundidad máxima de reflexión para el rayo.
     * @return Color (Vector3D) que representa el color calculado.
     */
    Vector3D traceRay(const Ray& ray, int depth) const;

    /**
     * @brief Calcula la iluminación en un punto específico de la escena.
     * @param point Punto donde se calcula la iluminación.
     * @param normal Normal en el punto.
     * @param viewDirection Dirección hacia la cámara.
     * @param specular Valor especular del material.
     * @return Intensidad de iluminación en el punto.
     */
    double computeLighting(const Vector3D& point, const Vector3D& normal, const Vector3D& viewDirection, int specular) const;

    /**
     * @brief Determina si un rayo intersecta con algún objeto en la escena.
     * @param ray Rayo a evaluar.
     * @param hitPoint Punto de intersección más cercano.
     * @param normal Normal en el punto de intersección.
     * @return true si hay una intersección, false de lo contrario.
     */
    bool intersects(const Ray& ray, Vector3D& hitPoint, Vector3D& normal) const;

    /**
     * @brief Determina si un punto está en la sombra.
     * @param point Punto a evaluar.
     * @param lightDirection Dirección de la luz.
     * @param t_max Máxima distancia de la sombra.
     * @return true si el punto está en la sombra, false de lo contrario.
     */
    bool isInShadow(const Vector3D& point, const Vector3D& lightDirection, double t_max) const;

    // Getters para obtener objetos en la escena
    const std::vector<Triangle>& getTriangles() const;
    const std::vector<Plane>& getPlanes() const;
    const std::vector<LightSource>& getLights() const;
    const std::vector<Sphere>& getSpheres() const;

private:
    std::vector<Triangle> triangles;  ///< Lista de triángulos en la escena.
    std::vector<Plane> planes;        ///< Lista de planos en la escena.
    std::vector<LightSource> lights;  ///< Lista de fuentes de luz en la escena.
    std::vector<Sphere> spheres;      ///< Lista de esferas en la escena.
};

#endif // SCENE_H
