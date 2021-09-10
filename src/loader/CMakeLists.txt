cmake_minimum_required(VERSION 3.16)

include_directories(
    include
    ${SRC_DIR}/fightable/dragon/include
    ${SRC_DIR}/object/key/include
    ${SRC_DIR}/object/sword/include
    ${SRC_DIR}/object/shield/include
    ${SRC_DIR}/passage/include
    ${SRC_DIR}/room/include
)


add_library(Loader
    map_loader.cpp
    dragon_loader.cpp
    dragon_parser.cpp
    object_loader.cpp
    object_parser.cpp
    passage_loader.cpp
    passage_parser.cpp
    room_loader.cpp
    room_parser.cpp
)

target_link_libraries(Loader
    Dragon
    Object
    Passage
    Room
    Key
    Shield
    Sword
)