# Script de PowerShell para compilar, ejecutar y visualizar la imagen renderizada

# Limpiar compilación anterior
make clean

# Compilar el proyecto
make

# Ejecutar el programa principal
./bin/main

# Visualizar la imagen generada
python view_ppm.py
