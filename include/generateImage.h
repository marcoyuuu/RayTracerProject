#ifndef GENERATE_IMAGE_H
#define GENERATE_IMAGE_H

#include <vector>
#include "Scene.h"
#include "Camera.h"
#include "Vector3D.h"

/**
 * Genera una imagen a partir de una escena y una cámara dadas.
 *
 * @param scene: Escena que contiene los objetos y las luces.
 * @param cam: Cámara que genera los rayos para renderizar la imagen.
 * @param framebuffer: Vector que almacena los colores de cada píxel de la imagen.
 * @param width: Ancho de la imagen en píxeles.
 * @param height: Alto de la imagen en píxeles.
 * @param maxDepth: Profundidad máxima de las reflexiones de los rayos.
 * @param viewportWidth: Ancho del viewport en unidades del mundo.
 * @param viewportHeight: Alto del viewport en unidades del mundo.
 * @param distanceToViewport: Distancia entre la cámara y el viewport.
 */
void generateImage(const Scene& scene, const Camera& cam, std::vector<Vector3D>& framebuffer, int width, int height, int maxDepth, double viewportWidth, double viewportHeight, double distanceToViewport);

#endif // GENERATE_IMAGE_H
