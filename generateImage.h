#ifndef GENERATE_IMAGE_H
#define GENERATE_IMAGE_H

#include <vector>
#include "Scene.h"
#include "Camera.h"
#include "Vector3D.h"

void generateImage(const Scene& scene, const Camera& cam, std::vector<Vector3D>& framebuffer, int width, int height);

#endif // GENERATE_IMAGE_H
