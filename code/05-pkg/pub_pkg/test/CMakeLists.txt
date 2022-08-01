add_executable(foo_test)

target_sources(foo_test
  PRIVATE
    foo_test.cc
)

target_link_libraries(foo_test
  PRIVATE
    infra::foo
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME foo_test COMMAND foo_test)