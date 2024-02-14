if(NOT TARGET hermes-engine::libhermes)
add_library(hermes-engine::libhermes SHARED IMPORTED)
set_target_properties(hermes-engine::libhermes PROPERTIES
    IMPORTED_LOCATION "/home/martin/.gradle/caches/transforms-3/a5d1380f097d180958ddc42b2632b92d/transformed/jetified-hermes-android-0.72.4-debug/prefab/modules/libhermes/libs/android.arm64-v8a/libhermes.so"
    INTERFACE_INCLUDE_DIRECTORIES "/home/martin/.gradle/caches/transforms-3/a5d1380f097d180958ddc42b2632b92d/transformed/jetified-hermes-android-0.72.4-debug/prefab/modules/libhermes/include"
    INTERFACE_LINK_LIBRARIES ""
)
endif()

