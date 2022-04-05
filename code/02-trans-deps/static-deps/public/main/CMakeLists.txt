add_executable(main)

target_sources(main
  PRIVATE main.c
)

target_link_libraries(main
  PRIVATE foo
)