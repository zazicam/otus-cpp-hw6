cmake_minimum_required(VERSION 3.2)

#project(matrix VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
project(matrix VERSION 0.0.1)
include_directories(${PROJECT_BINARY_DIR})

add_executable(matrix main.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_matrix tests/test.cpp)

set_target_properties(matrix test_matrix PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_matrix
	${GTEST_BOTH_LIBRARIES}
   	pthread 
)

install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)

enable_testing()

add_test(test_matrix test_matrix)

