set_property(DIRECTORY APPEND
		PROPERTY LABELS package
)

set(test_list
		FetchContent
		find_package
)

foreach (test IN LISTS test_list)
	JsonType_add_test(${test} TEST_NAME test-${test})
endforeach ()
