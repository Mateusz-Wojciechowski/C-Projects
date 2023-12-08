cmake_minimum_required(VERSION 3.26)
project(Lab3_TEP)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lab3_TEP main.cpp
        CNode.h
        CNode.cpp
        CTree.h
        CTree.cpp
        CUserInterface.cpp
        CUserInterface.h
        COperation.h
        COperation.cpp
        CConstantsTree.h
        CInterfaceConstants.h)
