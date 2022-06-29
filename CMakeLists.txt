cmake_minimum_required(VERSION 3.18)
project(programm C)

set(CMAKE_C_STANDARD 99)

add_executable(programm vector.h vector.c trajectory.h trajectory.c point.h point.c object.h object.c main.c list.c list.h cell.c cell.h constant.h json.c json.h)

target_link_libraries(programm m)
