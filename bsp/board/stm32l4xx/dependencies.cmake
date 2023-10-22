add_subdirectory(${CMAKE_SOURCE_DIR}/drivers src/drivers)

target_link_libraries(BOARD HAL_CMSIS)
