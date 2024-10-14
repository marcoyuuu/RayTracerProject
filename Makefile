# Variables
CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -Iinclude
SRCDIR = src
INCLUDEDIR = include
BUILDDIR = build
BINDIR = bin
TARGET = $(BINDIR)/main

# Lista de archivos fuente y sus correspondientes archivos objeto
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Target por defecto
all: $(TARGET)

# Enlace
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) -mconsole

# Compilar cada archivo fuente en un archivo objeto
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar el directorio de compilación y el ejecutable
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# Especificar .PHONY para evitar conflictos con nombres de archivos
.PHONY: all clean
