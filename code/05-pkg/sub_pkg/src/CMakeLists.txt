add_executable(main)

target_sources(main
  PRIVATE
    main.cc
)

target_link_libraries(main
  PRIVATE
    infra::foo
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME main COMMAND main)