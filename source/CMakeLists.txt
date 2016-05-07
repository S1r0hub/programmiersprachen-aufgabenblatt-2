# Build example
add_executable( example
				window.cpp
				glew.c
				vec2.cpp
				circle.cpp
				rectangle.cpp
				example.cpp )
target_link_libraries(example glfw ${GLFW_LIBRARIES} m)
add_dependencies(example glfw ${COPY_BINARY})

# Build tests
add_executable( tests
				window.cpp	# fuer aufgabe 2.11 und 2.12
				glew.c 		# fuer aufgabe 2.11 und 2.12
				vec2.cpp
				mat2.cpp
				circle.cpp
				rectangle.cpp
				tests.cpp )
target_link_libraries(tests glfw ${GLFW_LIBRARIES})