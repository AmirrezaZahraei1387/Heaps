cmake_minimum_required(VERSION 3.23)
project(PriorityHeap)

set(CMAKE_CXX_STANDARD 23)

add_executable(PriorityHeap
        main.cpp
        PriorityHeap/PriorityHeap.hpp
        PriorityHeap/PriorityHeapCore.inl
        PriorityHeap/PriorityHeapInter.inl)
