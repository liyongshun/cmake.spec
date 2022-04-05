# Properties

## Usage Requirements

```
target_include_directories(name
  INTERFACE
)

target_compile_definitions(name
  INTERFACE
)

target_compile_options(name
  INTERFACE  
)

target_compile_features(name
  INTERFACE  
)

target_link_directories(name
  INTERFACE  
)

target_sources(name
  INTERFACE  
)
```

```
INTERFACE_INCLUDE_DIRECTORIES

INTERFACE_COMPILE_DEFINITIONS
INTERFACE_COMPILE_OPTIONS
INTERFACE_COMPILE_FEATURES

INTERFACE_LINK_DIRECTORIES
INTERFACE_LINK_LIBRARIES

INTERFACE_POSITION_INDEPENDENT_CODE
INTERFACE_SOURCES
```

## Build Specification

```
target_include_directories(name
  PRIVATE
)

target_compile_definitions(name
  PRIVATE
)

target_compile_options(name
  PRIVATE  
)

target_compile_features(name
  PRIVATE  
)

target_link_directories(name
  PRIVATE  
)

target_sources(name
  PRIVATE  
)
```

```
INCLUDE_DIRECTORIES

COMPILE_DEFINITIONS
COMPILE_OPTIONS
COMPILE_FEATURES

LINK_DIRECTORIES
LINK_LIBRARIES

POSITION_INDEPENDENT_CODE
SOURCES
```

## Usage Requirements & Build Specification


```
target_include_directories(name
  PUBLIC
)

target_compile_definitions(name
  PUBLIC
)

target_compile_options(name
  PUBLIC  
)

target_compile_features(name
  PUBLIC  
)

target_link_directories(name
  PUBLIC  
)

target_sources(name
  PUBLIC  
)
```

```
INTERFACE_INCLUDE_DIRECTORIES
INCLUDE_DIRECTORIES

INTERFACE_COMPILE_DEFINITIONS
COMPILE_DEFINITIONS

INTERFACE_COMPILE_OPTIONS
COMPILE_OPTIONS

INTERFACE_COMPILE_FEATURES
COMPILE_FEATURES

INTERFACE_LINK_DIRECTORIES
LINK_DIRECTORIES

INTERFACE_LINK_LIBRARIES
LINK_LIBRARIES

INTERFACE_POSITION_INDEPENDENT_CODE
POSITION_INDEPENDENT_CODE

INTERFACE_SOURCES
SOURCES
```

## Transitive Usage Requirements

Usage requirements are propagated by reading the `INTERFACE_` variants of target properties from dependencies and appending the values to the `non-INTERFACE_` variants of the operand

```
# dependency::INTERFACE_ -> library::INTERFACE_ & library::non-INTERFACE_
target_link_library(library
  PUBLIC dependency
)
```

```
# dependency::INTERFACE_ -> library::non-INTERFACE_
target_link_library(library
  PRIVATE dependency
)
```

```
# dependency::INTERFACE_ -> library::INTERFACE_
target_link_library(library
  INTERFACE dependency
)
```

Generally, A dependency should be specified in a use of target_link_libraries() with the PRIVATE keyword if it is used by only the implementation of a library, and not in the header files. 

```
target_link_library(library
  PRIVATE dependency
)
```

A dependency is additionally used in the header files of a library (e.g. for class inheritance), then it should be specified as a PUBLIC dependency. 

```
target_link_library(library
  PUBLIC dependency
)
```

A dependency which is not used by the implementation of a library, but only by its headers should be specified as an INTERFACE dependency.

```
target_link_library(library
  INTERFACE dependency
)
```

## Global Properties

```cmake
include(CMakePrintHelpers)

get_property(cmake_c_known_features GLOBAL PROPERTY CMAKE_C_KNOWN_FEATURES)

cmake_print_variables(cmake_c_known_features)

get_property(cmake_cxx_known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)

cmake_print_variables(cmake_cxx_known_features)
```

输出：

```
-- cmake_c_known_features="c_std_90;c_std_99;c_std_11;c_std_17;c_std_23;c_function_prototypes;c_restrict;c_variadic_macros;c_static_assert"
-- cmake_cxx_known_features="cxx_std_98;cxx_std_11;cxx_std_14;cxx_std_17;cxx_std_20;cxx_std_23;cxx_template_template_parameters;cxx_alias_templates;cxx_alignas;cxx_alignof;cxx_attributes;cxx_auto_type;cxx_constexpr;cxx_decltype;cxx_decltype_incomplete_return_types;cxx_default_function_template_args;cxx_defaulted_functions;cxx_defaulted_move_initializers;cxx_delegating_constructors;cxx_deleted_functions;cxx_enum_forward_declarations;cxx_explicit_conversions;cxx_extended_friend_declarations;cxx_extern_templates;cxx_final;cxx_func_identifier;cxx_generalized_initializers;cxx_inheriting_constructors;cxx_inline_namespaces;cxx_lambdas;cxx_local_type_template_args;cxx_long_long_type;cxx_noexcept;cxx_nonstatic_member_init;cxx_nullptr;cxx_override;cxx_range_for;cxx_raw_string_literals;cxx_reference_qualified_functions;cxx_right_angle_brackets;cxx_rvalue_references;cxx_sizeof_member;cxx_static_assert;cxx_strong_enums;cxx_thread_local;cxx_trailing_return_types;cxx_unicode_literals;cxx_uniform_initialization;cxx_unrestricted_unions;cxx_user_literals;cxx_variadic_macros;cxx_variadic_templates;cxx_aggregate_default_initializers;cxx_attribute_deprecated;cxx_binary_literals;cxx_contextual_conversions;cxx_decltype_auto;cxx_digit_separators;cxx_generic_lambdas;cxx_lambda_init_captures;cxx_relaxed_constexpr;cxx_return_type_deduction;cxx_variable_templates"
```

## Directory Properties

```
- COMPILE_DEFINITIONS
- COMPILE_OPTIONS
- INCLUDE_DIRECTORIES
- LINK_DIRECTORIES
- LINK_OPTIONS
```

## Target Properties

- Name

```
PREFIX: lib
SUFFIX: a, so, exe
```

- 语言标准

```
C_EXTENSIONS
C_STANDARD
C_STANDARD_REQUIRED

CXX_EXTENSIONS
CXX_STANDARD
CXX_STANDARD_REQUIRED
```

- Usage Requirements

```
INTERFACE_SOURCES
INTERFACE_INCLUDE_DIRECTORIES
INTERFACE_COMPILE_DEFINITIONS
INTERFACE_COMPILE_OPTIONS
INTERFACE_COMPILE_FEATURES
INTERFACE_LINK_DIRECTORIES
INTERFACE_LINK_LIBRARIES
INTERFACE_POSITION_INDEPENDENT_CODE
```

- Build Specification

```
SOURCES
INCLUDE_DIRECTORIES
COMPILE_DEFINITIONS
COMPILE_FEATURES
COMPILE_OPTIONS
LINK_DIRECTORIES
LINK_LIBRARIES
POSITION_INDEPENDENT_CODE
```

- 可执行程序输出目录与名称

```
RUNTIME_OUTPUT_DIRECTORY
RUNTIME_OUTPUT_NAME
```

- Shared Library输出目录与名称

```
LIBRARY_OUTPUT_DIRECTORY
LIBRARY_OUTPUT_NAME 
```

- Static Library输出目录与名称

```
ARCHIVE_OUTPUT_DIRECTORY 
ARCHIVE_OUTPUT_NAME
```

- 符号隐藏

```
C_VISIBILITY_PRESET
CXX_VISIBILITY_PRESET
```

- -fvisibility=default
- -fvisibility=hide

This property is initialized by the value of the `CMAKE_<LANG>_VISIBILITY_PRESET` variable if it is set when a target is created.

- 内联函数符号隐藏

```
VISIBILITY_INLINES_HIDDEN
```

- -fvisibility-inlines-hidden

This property is initialized by the value of the `CMAKE_VISIBILITY_INLINES_HIDDEN` variable if it is set when a target is created.

- 位置无关代码

This property is True by default for SHARED and MODULE library targets and False otherwise. 

This property is initialized by the value of the `CMAKE_POSITION_INDEPENDENT_CODE` variable if it is set when a target is created.

```
POSITION_INDEPENDENT_CODE
```

- -fPIC


