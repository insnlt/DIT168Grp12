cmake_minimum_required(VERSION 3.2)
project(DIT168)
set(CMAKE_CXX_STANDARD 14)

find_package(libcluon REQUIRED)
include_directories(SYSTEM ${CLUON_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Prime.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PrimeChecker.cpp)
target_link_libraries(${PROJECT_NAME} ${CLUON_LIBRARIES})

#enable_testing()
#add_executable(${PROJECT_NAME}-Runner TestPrimeChecker.cpp ${CMAKE_CURRENT_SOURCE_DIR}/PrimeChecker.cpp)
#target_link_libraries(${PROJECT_NAME}-Runner ${CLUON_LIBRARIES})
#add_test(NAME ${PROJECT_NAME}-Runner COMMAND ${PROJECT_NAME}-Runner)
