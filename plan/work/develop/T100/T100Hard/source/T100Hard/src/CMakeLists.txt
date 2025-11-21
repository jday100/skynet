cmake_minimum_required(VERSION 4.0)

include_directories(include)

set(SOURCES display.c)

add_library(T100Hard ${SOURCES})
