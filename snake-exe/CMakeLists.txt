
add_executable(snake main.c)

target_link_libraries(snake PRIVATE board)
target_link_libraries(snake PRIVATE port)