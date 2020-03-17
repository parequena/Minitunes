# CMakeList.txt: proyecto de CMake para Minitunes, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

project ("Minitunes")
set (CMAKE__CXX_STANDARD 17)

# Agregue un origen al ejecutable de este proyecto.
add_executable (Minitunes "Minitunes.cpp")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
