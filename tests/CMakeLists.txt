include(CTest)

set(counter 1)
configure_file(${CMAKE_CURRENT_BINARY_DIR}/../DartConfiguration.tcl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
SUBDIRLIST(tests ${CMAKE_CURRENT_LIST_DIR})

foreach(testdir IN LISTS ${tests})
    add_executable(${counter} ${testdir}/test.cpp)
    add_test(${counter})
    math(expr counter "${counter}+1")
endforeach()