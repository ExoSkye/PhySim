

add_library(PhySim_LIB SHARED PhySim_LIB/physim.hpp PhySim_LIB/graph_class.cpp PhySim_LIB/graph_class.h)
link_libraries(PhySim_LIB)
include_directories(PhySim_LIB)
add_executable(PhySim_Test PhySim_Test/main.cpp)
set_target_properties(PhySim_LIB PROPERTIES LINKER_LANGUAGE CXX)