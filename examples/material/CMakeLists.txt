add_library(WaterMaterial SHARED lib.cpp)
set_target_properties(WaterMaterial PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(WaterMaterial PRIVATE ${PROJECT_SOURCE_DIR}/src/PhySim_LIB/)