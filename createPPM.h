#ifndef CREATEPPM_H
#define CREATEPPM_H

#include <vector>
#include "Vector3D.h" // Incluir la clase Vector3D para que pueda ser usada en la función

void createPPM(const std::vector<Vector3D>& framebuffer, int width, int height);

#endif // CREATEPPM_H
