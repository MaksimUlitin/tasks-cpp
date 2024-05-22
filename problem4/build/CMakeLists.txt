cmake_minimum_required(VERSION 3.10)
project(problem4)

set(CMAKE_CXX_STANDARD 11)

add_library(film STATIC
    Film.cpp
)

add_executable(problem4
    main.cpp
)

target_link_libraries(problem4
    film
)