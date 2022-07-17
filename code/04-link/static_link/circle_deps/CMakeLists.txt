cmake_minimum_required(VERSION 3.14)

project(04-circle_deps VERSION 1.0 LANGUAGES C)

## target: foo
add_library(foo STATIC)

target_sources(foo
  PRIVATE
    foo1.c
    foo2.c
)

target_link_libraries(foo PRIVATE bar)

## target: bar
add_library(bar STATIC)

target_sources(bar
  PRIVATE
    bar.c
)

target_link_libraries(bar PRIVATE foo)

## target: bar
add_executable(main)

target_sources(main
  PRIVATE
    main.c
)

target_link_libraries(main PRIVATE foo)