cmake_minimum_required(VERSION 3.16)

include_directories(
    include
    ${SRC_DIR}/object/key/include
    ${SRC_DIR}/object/sword/include
)

add_library(Player player.cpp)

target_link_libraries(Player Fightable)