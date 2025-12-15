cmake_minimum_required(VERSION 4.0)
project(get_next_line_v2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(get_next_line_v2
        get_next_line.c
        get_next_line.h
        get_next_line_bonus.c
        get_next_line_bonus.h
        get_next_line_utils.c
        get_next_line_utils_bonus.c
        main.c)
