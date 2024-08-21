add_executable(main ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
target_link_libraries(main PRIVATE JsonType::JsonType)

enable_testing()
add_test(NAME smoke_test
        COMMAND $<TARGET_FILE:main>
)
if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.27)
    # https://stackoverflow.com/a/77990416
    set_property(TEST smoke_test APPEND PROPERTY
            ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:$<JOIN:$<TARGET_RUNTIME_DLL_DIRS:main>,\;>"
    )
endif ()
