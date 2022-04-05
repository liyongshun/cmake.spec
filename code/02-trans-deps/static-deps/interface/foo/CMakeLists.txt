add_library(foo STATIC)

target_sources(foo
  PRIVATE src/foo.c
)

target_include_directories(foo
  PUBLIC  include
  PRIVATE src
)

target_link_libraries(foo
  INTERFACE bar
)