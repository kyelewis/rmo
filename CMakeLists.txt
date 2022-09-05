cmake_minimum_required(VERSION 3.10)
project(rmo)
set(RMO_SRC "${PROJECT_SOURCE_DIR}/src")

include_directories(RMO_SRC)

add_executable(rmo ${RMO_SRC}/main.c ${RMO_SRC}/http_client.c)
