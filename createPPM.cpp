#include "createPPM.h"
#include "Vector3D.h"  // Para manejar colores como Vector3D
#include <iostream>    // Para std::cerr
#include <fstream>     // Para std::ofstream
#include <vector>      // Para std::vector

void createPPM(const std::vector<Vector3D>& framebuffer, int width, int height) {
    std::ofstream file("output.ppm"); // Cambiar a std::ofstream para ser explícito
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }
    
    file << "P3\n" << width << " " << height << "\n255\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Vector3D color = framebuffer[i * width + j];
            file << static_cast<int>(color.getX()) << " "
                 << static_cast<int>(color.getY()) << " "
                 << static_cast<int>(color.getZ()) << " ";
        }
        file << "\n";
    }
    file.close();
}
