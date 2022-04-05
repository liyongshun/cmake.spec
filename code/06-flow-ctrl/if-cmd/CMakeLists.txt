
macro(assert_true exp)
  if(NOT ${exp})
    message(FATAL_ERROR "expect ${exp} be true, but got false")
  endif()
endmacro()

macro(assert_false exp)
  if(${exp})
    message(FATAL_ERROR "expect ${exp} be false, but got true")
  endif()
endmacro()

## unquoted constant(1, TRUE, YES, Y, ON) => true
assert_true(1 AND 2)
assert_true(TRUE AND True AND true)
assert_true(YES AND Yes AND yes)
assert_true(Y AND y)
assert_true(ON AND on AND On)

## unquoted constant(0, FALSE, NO, N, OFF, IGNORE, NOTFOUND, "") => false
assert_false(0)
assert_false(false OR False OR FALSE)
assert_false(No OR no OR NO)
assert_false(N OR n)
assert_false(OFF OR off OR Off)

assert_false(IGNORE OR Ignore OR ignore)
assert_false(NOTFOUND OR NotFound OR notfound)

## unquoted variable: (N, false, off, "") => false
set(var N)
assert_false(var)

set(var false)
assert_false(var)

option(enable_xxx "enable xxx" OFF)
assert_false(enable_xxx)

set(var "")
assert_false(var)

# non_defined_var is ""
assert_false(non_defined_var)

set(var "xxx-NOTFOUND")
assert_false(var)

set(var "non-empty-value")
assert_true(var)

option(enable_yyy "enable yyy" ON)
assert_true(enable_yyy)

## quoted string => false, using STREQUAL and so on
assert_false("string")
assert_false("")

set(defined_var "non-empty-value")
assert_false("${defined_var}")

set(defined_var "")
assert_false("${defined_var}")

assert_false("${non_defined_var}")

set(defined_var "non-empty-value")
assert_false(${defined_var})