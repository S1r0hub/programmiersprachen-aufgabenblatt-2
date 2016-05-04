# Build example
add_executable(example window.cpp glew.c example.cpp)
target_link_libraries(example glfw ${GLFW_LIBRARIES} m)
add_dependencies(example glfw ${COPY_BINARY})

# Build tests
add_executable(tests vec2.cpp mat2.cpp tests.cpp)
target_link_libraries(tests ${GLFW_LIBRARIES})

# Build vector
add_executable(vec2 tests.cpp mat2.cpp vec2.cpp)
add_dependencies(example tests)

# Build matrix
add_executable(mat2 tests.cpp vec2.cpp mat2.cpp)