cmake_minimum_required(VERSION 3.16)

configure_file(objects.cfg /tmp COPYONLY)
configure_file(passages.cfg /tmp COPYONLY)
configure_file(rooms.cfg /tmp COPYONLY)
configure_file(dragons.cfg /tmp COPYONLY)

add_executable(Game
    main.cpp
    game.cpp
    player_handler.cpp
)

include_directories(
    include
    ${SRC_DIR}/loader/include
    ${SRC_DIR}/network/include
    ${SRC_DIR}/object/key/include
    ${SRC_DIR}/fightable/player/include
)

target_link_libraries(Game
    Fightable
    Dragon
    Player
    Object
    Key
    Shield
    Sword
    Passage
    Room
    Network
    Loader
)
