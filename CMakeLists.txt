cmake_minimum_required(VERSION 3.23)
project(ZOS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZOS main.cpp command.cpp command.h fat.cpp fat.h global.h)
