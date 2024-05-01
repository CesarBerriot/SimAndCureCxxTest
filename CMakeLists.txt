cmake_minimum_required(VERSION 3.27)
project(SimAndCureTest)

# Global Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)
include_directories(. src)

# Application Sources
set(APP_SOURCES
    src/Logic/Logic.cpp
    src/Utils/Utils.cpp
    src/Globals/Globals.cpp
    src/DataTypes/WordList.cpp)

# Application Executable
add_executable(SimAndCureTest ${APP_SOURCES} src/main.cpp)

# GoogleTest
enable_testing()
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Test Executables
macro(make_test_executable NAME)
    add_executable(${NAME}Test test/${NAME}.cpp ${APP_SOURCES})
    target_link_libraries(${NAME}Test GTest::gtest_main)
    gtest_discover_tests(${NAME}Test)
endmacro()
make_test_executable(ValidateArguments)
make_test_executable(ApplyUnicodeLocale)
make_test_executable(ObtainFilePathFromArguments)
make_test_executable(ObtainCountFilePathFromFilePath)
make_test_executable(SumWordScore)
make_test_executable(SumListScore)
make_test_executable(OutputListToFile)
make_test_executable(WordList)
make_test_executable(FailWithError)
