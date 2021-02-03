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
    message("detect win32")
    message("try linking mingw32...")
    target_link_libraries(${PROJECT_NAME} -lmingw32)
elseif(UNIX)
    message("detect unix like system")
    # in unix like system, pthread need additional link
    message("try link pthread")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
else()
    message("other system")
endif ()
