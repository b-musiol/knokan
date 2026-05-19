cmake_minimum_required(VERSION 3.14)

project(KnoKan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0  # Or use a specific commit hash
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(RunTests_KnoKan tests/KnoKan_test.cpp)
target_link_libraries(RunTests_KnoKan GTest::gtest_main)
target_compile_features(RunTests_KnoKan PUBLIC cxx_std_20)


include(GoogleTest)
enable_testing()
gtest_discover_tests(RunTests_KnoKan)

