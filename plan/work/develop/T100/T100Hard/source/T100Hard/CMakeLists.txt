cmake_minimum_required(VERSION 4.0)

project(T100Hard)

include_directories(include)

set(SOURCES include/display.h src/display.c)

add_library(T100Hard ${SOURCES})









#set(LIBT100HARD_SRC include/display.h src/display.c)
#add_library(T100Hard SHARED ${LIBT100HARD_SRC})
#add_library(T100Hard static ${LIBT100HARD_SRC})


#add_subdirectory(src)
