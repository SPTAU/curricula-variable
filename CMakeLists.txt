cmake_minimum_required(VERSION 3.17)
project(SystemDesign)

set(CMAKE_CXX_STANDARD 20)

add_executable(SystemDesign main.cpp Student.h Course.cpp Course.h Student.cpp StudentData_Struct.h CourseData_Struct.h Operator.h StudentManagement.cpp StudentManagement.h CourseManagement.cpp CourseManagement.h)