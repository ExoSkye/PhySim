SUBDIRLIST(examples ${CMAKE_CURRENT_LIST_DIR})
foreach(example_dir IN LISTS examples)
    add_subdirectory(${example_dir})
endforeach()
