project(Properties)

add_executable(properties
        properties.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fdump-vtable-layouts")
# gcc -fdump-class-hierarchy