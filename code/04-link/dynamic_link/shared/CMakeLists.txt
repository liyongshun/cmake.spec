cmake_minimum_required(VERSION 3.14)

project(04-link-shared-linking)

add_library(foo SHARED foo.c)

add_executable(main main.c)

target_link_libraries(main PRIVATE foo)