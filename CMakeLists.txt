# Project body
message(">>>>>>>>>>>>>>> ThingJS core included <<<<<<<<<<<<<<<<<<<")

idf_component_register(
        INCLUDE_DIRS  "./"
        REQUIRES spiffs nvs_flash mdns spi_flash partition_table bootloader_support app_update esp_adc_cal thingjs_front
)

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

#component_compile_options(INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a")

#set(project_elf ${CMAKE_PROJECT_NAME}.elf)
#add_library(${COMPONENT_LIB}_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a)

set(lib_a "${COMPONENT_LIB}_a")
add_library(${lib_a} STATIC IMPORTED)
set_property(TARGET ${lib_a} PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a")

#add_library(${lib_a} STATIC "${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a")
__component_set_property(${lib_a} COMPONENT_TYPE LIBRARY)
target_include_directories(${lib_a} INTERFACE "./")
#target_include_directories(${component_lib} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/${target}")
#target_include_directories(${component_lib} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${target}")
set_target_properties(${lib_a} PROPERTIES OUTPUT_NAME thingjs_core)
#__ldgen_add_component(${lib_a})
idf_build_set_property(__LDGEN_DEPENDS ${lib_a} APPEND)

#target_link_libraries(${COMPONENT_LIB} INTERFACE ${lib_a})

#target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a")
#idf_build_set_property(CXX_COMPILE_OPTIONS "-l${CMAKE_CURRENT_SOURCE_DIR}/${target}libthingjs_core.a" APPEND)