add_library(
    board 
    board/board.h 
    board/board.c
)

target_include_directories(board PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_definitions(board PRIVATE BOARD_VERSION=1.0)