cmake_minimum_required(VERSION 3.24)
project(STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(STL Vector.cpp Source.cpp Vector.h List.cpp List.h Set.h Set.cpp Map.cpp Map.h UnorderedMap.cpp UnorderedMap.h LinkedList.cpp LinkedList.h)
