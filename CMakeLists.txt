project(PhySim CXX)
enable_testing()

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
endif()
if (UNIX)
    list(APPEND EXTRA_LIBS dl)
endif()
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)
