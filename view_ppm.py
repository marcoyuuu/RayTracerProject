"""
@file view_ppm.py
@brief Script para visualizar archivos PPM generados por la aplicación de renderizado.

Este script utiliza la biblioteca Pillow para abrir y mostrar el archivo PPM generado.
También guarda una versión temporal de la imagen en el directorio de salida especificado.
Es una herramienta rápida y útil para visualizar el resultado sin salir del entorno del proyecto.
"""

from PIL import Image
import sys
import os

def main(ppm_file_path='output/output.ppm'):
    """
    Abre y muestra la imagen PPM generada y la guarda en un directorio especificado.

    @param ppm_file_path: Ruta al archivo PPM generado. Valor por defecto: 'output/output.ppm'
    """
    try:
        # Verificar si el archivo existe
        if not os.path.exists(ppm_file_path):
            raise FileNotFoundError(f"El archivo {ppm_file_path} no fue encontrado.")
        # Abrir el archivo PPM usando PIL
        img = Image.open(ppm_file_path)
        # Mostrar la imagen
        img.show()
        # Guardar la imagen en el directorio de salida con un nombre adecuado
        output_directory = "C:/Users/yumar/OneDrive/Desktop/COMP 4046/Examen/output"
        output_file_path = os.path.join(output_directory, "render_output.png")
        img.save(output_file_path)
        print(f"Imagen guardada como {output_file_path}")
    except FileNotFoundError:
        print(f"Error: No se encontró el archivo {ppm_file_path}. Asegúrate de que el archivo se haya generado correctamente.")
    except Exception as e:
        print(f"Error: No se pudo abrir el archivo {ppm_file_path}. Detalles: {e}")

if __name__ == '__main__':
    # Permitir que el archivo PPM sea especificado como argumento
    ppm_path = sys.argv[1] if len(sys.argv) > 1 else 'output/output.ppm'
    main(ppm_path)
