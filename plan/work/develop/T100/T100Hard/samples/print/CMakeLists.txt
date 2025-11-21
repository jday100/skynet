cmake_minimum_required(VERSION 4.0)

project(T100HardPrint)

include_directories(../../source/T100Hard/include)

link_directories(../../source/T100Hard)

add_definitions("-e start_entry")

set(LINK_SCRIPTS "-fno-builtin -ffreestanding -nostdlib -e start_entry")

set(SOURCES main.c)

add_executable(T100HardPrint ${SOURCES})

target_link_libraries(T100HardPrint T100Hard)

if(!WIN32)
    set_target_properties(
        T100HardPrint
        PROPERTIES LINK_FLAGS
        "/ENTRY:start_entry"
    )
endif()


