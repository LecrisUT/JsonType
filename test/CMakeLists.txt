cmake_minimum_required(VERSION 3.25...3.29)

#[=============================================================================[
#                           Basic project definition                           #
]=============================================================================]

list(APPEND CMAKE_MESSAGE_CONTEXT Test)
project(JsonType_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#[=============================================================================[
#                                   Options                                   #
]=============================================================================]

include(CMakeDependentOption)

cmake_dependent_option(JSONTYPE_TEST_COVERAGE "JsonType: Test with coverage" OFF "JsonType_IS_TOP_LEVEL" OFF)
mark_as_advanced(JSONTYPE_TEST_COVERAGE)

#[==============================================================================================[
#                                     Project configuration                                     #
]==============================================================================================]

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake)

include(FetchContent)
include(JsonType_test)

#[=============================================================================[
#                              External packages                              #
]=============================================================================]

if (NOT TARGET JsonType::JsonType)
	find_package(JsonType REQUIRED CONFIG)
endif ()
FetchContent_Declare(Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2
		GIT_TAG v3.7.0
		FIND_PACKAGE_ARGS CONFIG
)

FetchContent_MakeAvailable(Catch2)

if (JSONTYPE_TEST_COVERAGE)
	target_compile_options(JsonType_Lib PRIVATE --coverage)
	target_link_options(JsonType_Lib PUBLIC --coverage)
endif ()

#[=============================================================================[
#                               Main definition                               #
]=============================================================================]

enable_testing()
include(Catch)

if (WIN32 AND CMAKE_VERSION VERSION_LESS 3.27)
	message(FATAL_ERROR "Cannot reliably test for windows with CMake < 3.27")
endif ()

add_executable(test-suite)
target_link_libraries(test-suite PRIVATE Catch2::Catch2WithMain JsonType::JsonType)

foreach (test_type IN ITEMS
		unit
		package
)
	add_subdirectory(${test_type})
endforeach ()

set(extra_args)
set(test_properties
		# Manually hard-coding labels until upstream support is included
		# https://github.com/catchorg/Catch2/pull/2690
		LABELS "unit"
)
if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.27)
	# Patch DLL path for windows
	# https://stackoverflow.com/a/77990416
	list(APPEND test_properties
			ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:$<JOIN:$<TARGET_RUNTIME_DLL_DIRS:test-suite>,\;>"
	)
	list(APPEND extra_args
			DL_PATHS "$<TARGET_RUNTIME_DLL_DIRS:test-suite>"
	)
endif ()
catch_discover_tests(test-suite
		PROPERTIES ${test_properties}
		${extra_args}
)
