add_library(
    board 
    board/board.h 
    board/board.c
)

add_library(
    port 
    port/port.h 
    port/port.c
)

target_include_directories(board PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(port PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_definitions(board PRIVATE BOARD_VERSION=1.0)
target_compile_definitions(port PRIVATE PORT_VERSION=1.5)