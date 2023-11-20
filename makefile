# Definir el compilador
CXX = g++

# Definir las banderas de compilación
CXXFLAGS = -Wall -Wextra -std=c++17

# Directorio de las librerías
LIB_DIR = lib

# Buscar recursivamente todos los archivos .cpp en LIB_DIR
SRC := $(shell find $(LIB_DIR) -name '*.cpp')

# Añadir el archivo principal
SRC += main.cpp

# Definir el nombre del ejecutable
TARGET = zooapp

# Regla predeterminada
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Regla para limpiar los archivos compilados
clean:
	rm -f $(TARGET)
