cmake_minimum_required(VERSION 3.19)
project(libft C)

set(CMAKE_C_STANDARD 99)

add_library(mlx STATIC
        _README_
        font.xcf
        mlx.h
        mlx_int.h
        mlx_new_image.m
        mlx_new_window.m
        mlx_shaders.c
        font.c
        mlx_init_loop.m
        mlx_int_str_to_wordtab.c
        mlx_new_window.h
        mlx_rgb.c
        mlx_xpm.c
        )