cmake_minimum_required(VERSION 3.26)
project(Lab1_TEP)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lab1_TEP main.cpp
        Zad4/CTable.h
        Zad4/CTable.cpp
        Zad4/CTable_const.h
        Zad1/allocateFillTable.cpp
        Zad1/allocateFillTable_const.h
        Zad1/allocateFillTable.h
        Zad2/allocateTable2Dim.h
        Zad2/allocateTable2Dim.cpp
        Zad3/deallocateTable2Dim.cpp
        Zad3/deallocateTable2Dim.h
)
