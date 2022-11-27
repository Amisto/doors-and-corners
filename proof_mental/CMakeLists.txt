cmake_minimum_required(VERSION 3.16)
project(proof_mental)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_executable(proof_mental
        main.cpp
        Psyche.cpp
        Button.cpp
        )


set(SFML_DIR ../../SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

target_link_libraries(proof_mental sfml-graphics sfml-window sfml-system sfml-audio)