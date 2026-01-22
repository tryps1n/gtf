cmake_minimum_required(VERSION 3.10)  
project(gtf-translator)              

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(CURL REQUIRED)


add_executable(gtf           
    src/main.cpp                  
)

target_link_libraries(gtf PRIVATE CURL::libcurl)

target_include_directories(gtf PRIVATE include)