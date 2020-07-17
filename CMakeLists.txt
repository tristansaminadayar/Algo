cmake_minimum_required(VERSION 3.16)
project(Algo C)

set(CMAKE_C_STANDARD 11)

add_library(Algo Sources/Sort.c Headers/Sort.h Sources/Structure.c Headers/Structure.h)