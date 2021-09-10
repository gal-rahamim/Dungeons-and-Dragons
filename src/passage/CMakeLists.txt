cmake_minimum_required(VERSION 3.16)

include_directories(
    include
    ${SRC_DIR}/object/key/include
    )

add_library(Passage passage.cpp)