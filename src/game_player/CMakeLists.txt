cmake_minimum_required(VERSION 3.16)

add_executable(GamePlayer
    main.cpp
    game_player.cpp
)

include_directories(
    include
    ${SRC_DIR}/network/include
)

target_link_libraries(GamePlayer
    Network
)