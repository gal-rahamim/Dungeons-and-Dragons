cmake_minimum_required(VERSION 3.16)

add_library(Fightable
    i_fightable.cpp
    )

add_subdirectory(dragon)
add_subdirectory(player)
