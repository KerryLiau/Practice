cmake_minimum_required(VERSION 3.17)
project(Demo)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME Demo)
set(SOURCE_FILE main.cpp)

add_executable(
        ${PROJECT_NAME}
        ${SOURCE_FILE}
        third_party_lib/json/CJsonObject/CJsonObject.cpp
        third_party_lib/json/CJsonObject/cJSON.c
)

if(WIN32)
    message("detect win32, try linking mingw32...")
    target_link_libraries(${PROJECT_NAME} -lmingw32)
elseif(UNIX)
    message("detect unix like system")
endif ()
