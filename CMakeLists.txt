cmake_minimum_required(VERSION 3.24)
project(SDiZO_1)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCE_FILES main.cpp)
add_executable(SDiZO_1 main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Array.cpp Array.h BinaryHeap.cpp BinaryHeap.h RedBlackTree.cpp RedBlackTree.h)
