# Build example
add_executable(example vec2.cpp window.cpp glew.c example.cpp)
target_link_libraries(example glfw ${GLFW_LIBRARIES} m)
add_dependencies(example tests glfw ${COPY_BINARY})

# Build tests
add_executable( tests
				vec2.cpp
				mat2.cpp
				circle.cpp
				rectangle.cpp
				tests.cpp )
target_link_libraries(tests ${GLFW_LIBRARIES})