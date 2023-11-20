# Definir la versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.10)

# Definir el nombre del proyecto
project(zooapp)

# Especificar el estándar de C++ requerido
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recopilar automáticamente todos los archivos fuente .cpp en la carpeta lib y subcarpetas
file(GLOB_RECURSE LIB_SOURCES "lib/*.cpp")

# Incluir el archivo fuente principal
set(SOURCES main.cpp ${LIB_SOURCES})

# Definir el ejecutable con los archivos fuente
add_executable(${PROJECT_NAME} ${SOURCES})

# Incluir los directorios de cabecera, si es necesario
include_directories(lib)
