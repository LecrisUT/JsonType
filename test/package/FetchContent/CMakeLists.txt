cmake_minimum_required(VERSION 3.25...3.29)
project(Example_JsonType LANGUAGES CXX)

include(FetchContent)

if (DEFINED ENV{PACKIT_SOURCE_URL})
	set(git_repo $ENV{PACKIT_SOURCE_URL})
else ()
	set(git_repo https://github.com/LecrisUT/JsonType)
endif ()
if (DEFINED ENV{PACKIT_SOURCE_SHA})
	set(git_tag $ENV{PACKIT_SOURCE_SHA})
elseif (DEFINED ENV{PACKIT_COMMIT_SHA})
	set(git_tag $ENV{PACKIT_COMMIT_SHA})
else ()
	set(git_tag main)
endif ()

FetchContent_Declare(JsonType
		GIT_REPOSITORY ${git_repo}
		GIT_TAG ${git_tag}
)
FetchContent_MakeAvailable(JsonType)

include(${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake)
