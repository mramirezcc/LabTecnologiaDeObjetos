cmake_minimum_required(VERSION 3.16)
project(SelectorColores)

# Configurar para usar MOC automáticamente
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_RELAXED_MODE ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/VentanaColores.cpp
)

# Archivos de cabecera (importante que estén aquí para MOC)
set(HEADERS
    include/VentanaColores.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)