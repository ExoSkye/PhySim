project(PhySim CXX)
include(CTest)

cmake_minimum_required(VERSION 3.7)

if (WIN32)
    list(APPEND EXTRA_LIBS vcruntime user32 gdi32 winmm imm32 ole32 oleaut32 version uuid advapi32 shell32)
endif()

add_subdirectory(src)

