cmake_minimum_required(VERSION 3.16)
project(main)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:QT_DEBUG>)