# Project body
message(">>>>>>>>>>>>>>> ThingJS core included <<<<<<<<<<<<<<<<<<<")

set(COMPONENT_LIB thingjs_core)

idf_component_register(
        INCLUDE_DIRS  "./"
        REQUIRES spiffs nvs_flash mdns spi_flash partition_table bootloader_support app_update esp_adc_cal
)

execute_process(COMMAND  git rev-parse HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE VERSION_COMMIT)
idf_build_set_property(COMPILE_OPTIONS "-DVERSION_COMMIT=\"${VERSION_COMMIT}\"" APPEND)

execute_process(COMMAND  date "+%D %X"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE VERSION_MOMENT)
idf_build_set_property(COMPILE_OPTIONS "-DVERSION_MOMENT=\"${VERSION_MOMENT}\"" APPEND)

idf_build_set_property(COMPILE_OPTIONS "-L${CMAKE_SOURCE_DIR}/components/thingjs_core/libthingjs_core.a" APPEND)



