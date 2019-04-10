cmake_minimum_required(VERSION 3.13)
project(CourseraWorks)

set(CMAKE_CXX_STANDARD 17)

add_executable(CourseraWorks main.cpp "Format samples.cpp" "Testing Framework/Testing Framework.h" "Class Rational/Class Rational.h" "Class Person/Class Person.h" "Class Matrix/Class Matrix.h" "Testing Framework/Testing Framework.cpp" "Class Rational/Class Rational.cpp" "Class Matrix/Class Matrix.cpp" Database/condition_parser.cpp Database/condition_parser.h Database/database.cpp Database/database.h Database/date.cpp Database/date.h Database/main_DB.cpp Database/node.cpp Database/node.h Database/token.cpp Database/token.h DELETE.cpp)