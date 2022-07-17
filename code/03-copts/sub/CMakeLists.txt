add_executable(03-copts main.cc)

target_compile_options(03-copts
  PRIVATE
    -Wconversion-null
    -Wformat-security
)

set_source_files_properties(main.cc PROPERTIES
  COMPILE_OPTIONS -Woverlength-strings
)

set_property(SOURCE main.cc APPEND PROPERTY
  COMPILE_OPTIONS -Wunused-result
)