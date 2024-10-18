#include "createPPM.h"
#include "Vector3D.h"  // Para manejar los colores usando Vector3D
#include <iostream>    // Para std::cerr
#include <fstream>     // Para std::ofstream
#include <vector>      // Para std::vector
#include <algorithm>   // Para std::clamp
#include <filesystem>  // Para std::filesystem::create_directories (C++17)

namespace fs = std::filesystem;

/**
 * Aplica corrección gamma a un color dado.
 *
 * @param color: Color como un Vector3D con valores de los componentes R, G, B.
 * @param gamma: Valor gamma (por defecto 2.2) para la corrección.
 * @return Vector3D: Color corregido con gamma.
 */
Vector3D applyGammaCorrection(const Vector3D& color, double gamma = 2.2) {
    return Vector3D(
        pow(color.getX() / 255.0, 1.0 / gamma) * 255,
        pow(color.getY() / 255.0, 1.0 / gamma) * 255,
        pow(color.getZ() / 255.0, 1.0 / gamma) * 255
    );
}

/**
 * Limita un valor a un rango entre 0 y 255.
 *
 * @param value: Valor que se va a limitar.
 * @return int: Valor limitado entre 0 y 255.
 */
int clamp(double value) {
    return static_cast<int>(std::clamp(value, 0.0, 255.0));
}

/**
 * Crea un archivo de imagen en formato PPM a partir de un framebuffer.
 *
 * @param framebuffer: Vector de píxeles representados como objetos Vector3D (RGB).
 * @param width: Ancho de la imagen.
 * @param height: Alto de la imagen.
 */
void createPPM(const std::vector<Vector3D>& framebuffer, int width, int height) {
    std::cout << "Intentando crear el archivo PPM en la ruta especificada...\n";
    std::ofstream file("./output/output.ppm");
    
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }

    std::cout << "Archivo PPM creado correctamente. Escribiendo datos...\n";

    file << "P3\n" << width << " " << height << "\n255\n";

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Vector3D color = applyGammaCorrection(framebuffer[i * width + j]);
            file << clamp(color.getX()) << " "
                 << clamp(color.getY()) << " "
                 << clamp(color.getZ()) << " ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Datos escritos correctamente. Archivo cerrado.\n";
}
