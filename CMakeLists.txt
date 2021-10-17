project(keem)
cmake_minimum_required(VERSION 3.14)

include(cmake/Dependencies.cmake)

add_executable(keem src/keem.cc)

target_link_libraries(keem workflow nlohmann_json::nlohmann_json)
