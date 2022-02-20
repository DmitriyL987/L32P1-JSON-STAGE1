cmake_minimum_required(VERSION 3.15)
project(L32P1_JSON_STAGE1)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(L32P1_JSON_STAGE1 main.cpp)

target_link_libraries(L32P1_JSON_STAGE1 PRIVATE nlohmann_json::nlohmann_json)