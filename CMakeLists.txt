cmake_minimum_required(VERSION 3.28)
project (moderna_variant_error)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED true)
set (CMAKE_CXX_SCAN_FOR_MODULES true)

if (NOT TARGET ${PROJECT_NAME})
  file(GLOB ${PROJECT_NAME}_src ${CMAKE_CURRENT_LIST_DIR}/src/*.ccm)
  add_library(${PROJECT_NAME})
  target_sources(${PROJECT_NAME}
    PUBLIC
      FILE_SET CXX_MODULES FILES ${${PROJECT_NAME}_src}
  )
endif()

if (
  EXISTS ${CMAKE_CURRENT_LIST_DIR}/../test-lib
  AND PROJECT_IS_TOP_LEVEL
)
  include(CTest)
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../test-lib test-lib)
  moderna_add_test(
    ${PROJECT_NAME}_tests
    ${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp
    LIBRARIES ${PROJECT_NAME} moderna_test_lib
  )
else()
  message (${PROJECT_NAME} : "Clone Moderna Library to Test")
endif()