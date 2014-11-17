macro (copy_lib)
	foreach (_lib ${ARGN})
		add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${PROJECT_SOURCE_DIR}/lib/${_lib}"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>)

		add_custom_command(TARGET ${PROJECT_NAME}_tests POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${PROJECT_SOURCE_DIR}/lib/${_lib}"
			$<TARGET_FILE_DIR:${PROJECT_NAME}_tests>)
	endforeach()
endmacro()
