## 编译选项



```c
# Case 1, list used instead of a string 
set(CMAKE_CXX_FLAGS -Wall -Werror)

# Case 2, but loss the value of Cache Variable 
set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Correct：Preserves the cache variable contents, appends new flags safely
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") 
string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")
```

# Case 1: Only has an effect if the variable isn't already in the cache 
set(CMAKE_CXX_FLAGS "-Wall -Werror" CACHE STRING "C++ flags")

# Case 2: Using FORCE to always update the cache variable, but this overwrites any changes a developer might make to the cache 
set(CMAKE_CXX_FLAGS "-Wall -Werror" CACHE STRING "C++ flags" FORCE)

# Case 3: FORCE + append = recipe for disaster
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" CACHE STRING "C++ flags" FORCE)

# WARNING: '${CMAKE_CXX_FLAGS} -Wall -Werror' will append to CFLAGS or CXXFLAGS for gcc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") 
add_library(strictReq STATIC ...)
add_library(relaxedReq STATIC ...)

# Save the original set of flags so we can restore them later 
set(oldCxxFlags "${CMAKE_CXX_FLAGS}")

# This library has strong build requirements, so enforce them just for it alone 
# WARNING: This doesn't do what it may appear to do! 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror") 
add_library(strictReq STATIC ...)

# Less strict requirements from here, so restore the original set of compiler flags
set(CMAKE_CXX_FLAGS "${oldCxxFlags}")
add_library(relaxedReq STATIC ...)

# Correct: Preserves the cache variable contents, appends new flags safely 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")