#ifndef CREATEPPM_H
#define CREATEPPM_H

#include <vector>
#include "Vector3D.h" // Incluir la clase Vector3D para representar los colores RGB

/**
 * Genera un archivo PPM a partir de un framebuffer.
 *
 * @param framebuffer: Un vector de objetos Vector3D que representan los colores de los píxeles.
 * @param width: Ancho de la imagen en píxeles.
 * @param height: Alto de la imagen en píxeles.
 */
void createPPM(const std::vector<Vector3D>& framebuffer, int width, int height);

#endif // CREATEPPM_H
