include(CTest)

set(counter 1)
configure_file(${CMAKE_CURRENT_BINARY_DIR}/../DartConfiguration.tcl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
SUBDIRLIST(tests ${CMAKE_CURRENT_LIST_DIR})

add_test(${counter} ${CMAKE_CURRENT_BINARY_DIR}/../src/PhySim_RUN)
set_tests_properties(${counter} PROPERTIES PASS_REGULAR_EXPRESSION "TestPassed;All ok")
math(EXPR counter "${counter}+1")

foreach(testdir IN LISTS tests)
    add_executable(${counter} ${testdir}/test.cpp)
    add_test(${counter} ${counter})
    target_include_directories(${counter} PRIVATE ../src/)
    target_compile_definitions(${counter} PRIVATE CMAKE_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")
    set_tests_properties(${counter} PROPERTIES PASS_REGULAR_EXPRESSION "TestPassed;All ok")
    math(EXPR counter "${counter}+1")
endforeach()