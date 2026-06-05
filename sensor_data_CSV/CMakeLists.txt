cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sensor_data_csv)

target_sources(app PRIVATE src/main.c)

target_include_directories(app PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

file(READ
    ${CMAKE_CURRENT_SOURCE_DIR}/data/analogtest_data_Abel.csv
    CSV_CONTENT
)

string(REPLACE "\\" "\\\\" CSV_CONTENT "${CSV_CONTENT}")
string(REPLACE "\"" "\\\"" CSV_CONTENT "${CSV_CONTENT}")
string(REPLACE "\n" "\\n\"\n\"" CSV_CONTENT "${CSV_CONTENT}")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/csv_data.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/csv_data.h
    @ONLY
)