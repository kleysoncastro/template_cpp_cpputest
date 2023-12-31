# # @uthor kleyson castro
# https://www.linkedin.com/in/kleyson-castro/

cmake_minimum_required(VERSION 3.20)

project(CPPRAII)



# Configurações de testes
option(TESTS "RUN test host compiler" OFF)
if(TESTS)
    message("building tests cpputest")
# config code coverage
set(CMAKE_CXX_FLAGS "-g -O0 -coverage")
set(CMAKE_BUILD_TYPE "Debug")
find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)
  add_custom_target(coverage
  # gather data
  COMMAND ${LCOV} --directory . --capture --output-file coverage.info 
  # generate report
  COMMAND ${GENHTML} --demangle-cpp -o coverage coverage.info
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    add_subdirectory(tests)
else()
    message("building executable")
endif()

add_subdirectory(src)