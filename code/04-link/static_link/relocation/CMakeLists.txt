cmake_minimum_required(VERSION 3.14)

project(04-relocation VERSION 1.0 LANGUAGES C)

add_executable(main)

target_sources(main
  PRIVATE
    main.c
    sum.c
)