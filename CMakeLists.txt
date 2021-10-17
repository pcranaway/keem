project(keem)
cmake_minimum_required(VERSION 3.14)

include(cmake/Dependencies.cmake)

add_executable(keem src/keem.cc)

# TODO: Put workflow on cmake/Dependencies.cmake so it's also downloaded automatically
target_link_libraries(keem workflow nlohmann_json::nlohmann_json)
