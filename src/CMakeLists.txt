target_sources(JsonType_Lib PRIVATE
        json_type.cpp
)
target_sources(JsonType_Lib PUBLIC
        FILE_SET json_type_header TYPE HEADERS FILES
        json_type.hpp
)



if (JSONTYPE_INSTALL)
    install(TARGETS JsonType_Lib
            EXPORT JsonTypeTargets
            FILE_SET json_type_header
    )
endif ()
