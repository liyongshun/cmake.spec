add_library(bar OBJECT)

target_sources(bar
  PRIVATE src/bar.c
)

target_include_directories(bar
  PUBLIC  include
  PRIVATE src
)

target_compile_definitions(bar
  PUBLIC
    PUBLIC_BAR=1
  INTERFACE
    INTERFACE_BAR=2
  PRIVATE
    PRIVATE_BAR=3  
)