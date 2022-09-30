cmake_minimum_required(VERSION 3.23)
project(CMythe C)

set(CMAKE_C_STANDARD 99)

include_directories(..)

#add_executable(CMythe TP1.c)
# add_executable(CMythe TP2.c)
# add_executable(CMythe TP3.c)
add_executable(CMythe TP4.c circular_buffer.h circular_buffer.c)
