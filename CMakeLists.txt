project(PhySim CXX)
include(CTest)

cmake_minimum_required(VERSION 3.12)

# Macro for listing subdirs
MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()
# End

if (WIN32)
    list(APPEND EXTRA_LIBS vcruntime user32 gdi32 winmm imm32 ole32 oleaut32 version uuid advapi32 shell32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()
add_subdirectory(src)
add_subdirectory(examples)

