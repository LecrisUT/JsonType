# Minimum version follows the current Ubuntu LTS and RHEL version
cmake_minimum_required(VERSION 3.25...3.29)

#[=============================================================================[
#                           Basic project definition                           #
]=============================================================================]

list(APPEND CMAKE_MESSAGE_CONTEXT JsonType)
# Define basic parameters
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()
project(JsonType
        VERSION 0.1.0
        DESCRIPTION "CMake project template"
        HOMEPAGE_URL https://github.com/LecrisUT/JsonType
        LANGUAGES CXX
)

# Specify C++ standard used in the project.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#[=============================================================================[
#                                   Options                                   #
]=============================================================================]

include(CMakeDependentOption)
include(FeatureSummary)

option(JSONTYPE_TEST "JsonType: Build test-suite" ${PROJECT_IS_TOP_LEVEL})
option(JSONTYPE_SHARED_LIBS "JsonType: Build as a shared library" ${PROJECT_IS_TOP_LEVEL})
option(JSONTYPE_INSTALL "JsonType: Install project" ${PROJECT_IS_TOP_LEVEL})


#[=============================================================================[
#                            Project configuration                            #
]=============================================================================]

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Include basic tools
include(FetchContent)
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(BUILD_SHARED_LIBS ${JSONTYPE_SHARED_LIBS})

#[=============================================================================[
#                              External packages                              #
]=============================================================================]

#[=============================================================================[
#                               Main definition                               #
]=============================================================================]

# Main project
add_library(JsonType_Lib)
set_target_properties(JsonType_Lib PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        EXPORT_NAME JsonType
        OUTPUT_NAME json_type
)
add_library(JsonType::JsonType ALIAS JsonType_Lib)
# Main definitions inside src
add_subdirectory(src)

# Testing
if (JSONTYPE_TEST)
    enable_testing()
    add_subdirectory(test)
endif ()

#[=============================================================================[
#                              Install or Export                              #
]=============================================================================]

# Installation
if (JSONTYPE_INSTALL)
    # cmake export files
    write_basic_package_version_file(
            ${CMAKE_CURRENT_BINARY_DIR}/JsonTypeConfigVersion.cmake
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY SameMajorVersion
    )
    configure_package_config_file(
            cmake/JsonTypeConfig.cmake.in
            ${CMAKE_CURRENT_BINARY_DIR}/JsonTypeConfig.cmake
            INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/JsonType
    )
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/JsonTypeConfigVersion.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/JsonTypeConfig.cmake
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/JsonType
    )

    export(EXPORT JsonTypeTargets
            FILE JsonTypeTargets.cmake
            NAMESPACE JsonType::
    )
    install(EXPORT JsonTypeTargets
            FILE JsonTypeTargets.cmake
            NAMESPACE JsonType::
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/JsonType
    )
endif ()

# Make project available for FetchContent
if(NOT PROJECT_IS_TOP_LEVEL)
    # Propagate variables
    return(PROPAGATE
            JsonType_VERSION
            JsonType_VERSION_MAJOR
            JsonType_VERSION_MINOR
            JsonType_VERSION_PATCH
            JsonType_VERSION_TWEAK
    )
endif ()
