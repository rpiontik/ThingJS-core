# Project body
message(">>>>>>>>>>>>>>> ThingJS core included <<<<<<<<<<<<<<<<<<<")

idf_component_register(
        INCLUDE_DIRS  "./"
        REQUIRES spiffs nvs_flash mdns spi_flash partition_table bootloader_support app_update esp_adc_cal thingjs_front
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${target}")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/${target}")

add_library(thing_core_lib STATIC IMPORTED)
set_property(TARGET thing_core_lib PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a")
target_link_libraries(${COMPONENT_LIB} INTERFACE thing_core_lib)
target_link_libraries(thing_core_lib INTERFACE __idf_cxx)
target_link_libraries(thing_core_lib INTERFACE __idf_thingjs_front)
target_link_libraries(thing_core_lib INTERFACE __idf_spiffs)
target_link_libraries(thing_core_lib INTERFACE __idf_mdns)

execute_process(COMMAND  git rev-parse HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE VERSION_COMMIT)
idf_build_set_property(COMPILE_OPTIONS "-DVERSION_COMMIT=\"${VERSION_COMMIT}\"" APPEND)

execute_process(COMMAND  date "+%D %X"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE VERSION_MOMENT)
idf_build_set_property(COMPILE_OPTIONS "-DVERSION_MOMENT=\"${VERSION_MOMENT}\"" APPEND)

idf_build_set_property(COMPILE_OPTIONS "-DMG_ENABLE_FILESYSTEM=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_ENABLE_HTTP_STREAMING_MULTIPART=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DCS_PLATFORM=15" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_DISABLE_DIRECTORY_LISTING=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_DISABLE_DAV=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_DISABLE_CGI=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_ENABLE_DNS_SERVER=1" APPEND)

idf_build_set_property(COMPILE_OPTIONS "-DMG_NET_IF_SOCKET=1" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_NET_IF_SIMPLELINK=2" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_NET_IF_LWIP_LOW_LEVEL=3" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_SSL_IF_SIMPLELINK=3" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DMG_ENABLE_HTTP_STREAMING_MULTIPART=1" APPEND)