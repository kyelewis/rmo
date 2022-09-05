cmake_minimum_required(VERSION 3.10)
project(rmo)
set(RMO_SRC ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_C_CPPLINT cpplint)

include_directories(RMO_SRC ${RMO_SRC}/http_request ${RMO_SRC}/dns_lookup)

add_executable(rmo ${RMO_SRC}/main.c ${RMO_SRC}/http_client.c ${RMO_SRC}/http_request/http_request.c ${RMO_SRC}/dns_lookup/dns_lookup.c)
