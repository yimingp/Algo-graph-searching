cmake_minimum_required(VERSION 3.15)
project(20S-3353-PA04)
set (EXE_NAME Graph-Searching-Algorithmns)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
add_executable(${EXE_NAME} main.cpp graphgenerator/GraphGenerator.h graphgenerator/GraphGenerator.cpp graphsearchsolutions/GraphSearcher_interface.h graphsearchsolutions/GraphSearcher_optimal.h graphsearchsolutions/GraphSearcher_trivial.cpp graphsearchsolutions/GraphSearcher_trivial.h graphsearchsolutions/GraphSearcher_optimal.cpp Utility Utility/GraphReader.cpp)