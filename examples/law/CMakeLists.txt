add_library(GravityLaw SHARED lib.cpp)
set_target_properties(GravityLaw PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(GravityLaw PRIVATE ${PROJECT_SOURCE_DIR}/src/PhySim_LIB/)
target_link_libraries(GravityLaw PRIVATE PhySim_LIB)