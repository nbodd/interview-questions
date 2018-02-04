
add_executable(tree-flattener.tsk solution.m.cpp)

install(TARGETS tree-flattener.tsk DESTINATION ${CMAKE_BINARY_DIR})