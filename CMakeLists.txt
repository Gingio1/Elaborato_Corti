cmake_minimum_required(VERSION 3.16)
project(Elaborato_Corti LANGUAGES CXX)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Core library ----
add_library(note_core
        src/Folder.cpp
        src/note.cpp
        src/ConcreteObserver.cpp
)

target_include_directories(note_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ---- App executable (NO tests here) ----
add_executable(Elaborato_Corti
        src/main.cpp
)

target_link_libraries(Elaborato_Corti PRIVATE note_core)

# ---- Tests (GoogleTest) ----
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(note_tests
        tst/test_note.cpp
        tst/test_folder.cpp
)

target_link_libraries(note_tests PRIVATE note_core gtest_main)

include(GoogleTest)
gtest_discover_tests(note_tests)
