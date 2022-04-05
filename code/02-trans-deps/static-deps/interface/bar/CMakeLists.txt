add_library(bar STATIC)

target_sources(bar
  PRIVATE src/bar.c
)

target_include_directories(bar
  PUBLIC  include
  PRIVATE src
)