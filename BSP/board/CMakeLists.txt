add_subdirectory(${CMAKE_SOURCE_DIR}/BSP/board/generated)

set(BOARD_INC
    ${CMAKE_SOURCE_DIR}/BSP/board/inc/
    ${CMAKE_SOURCE_DIR}/BSP/board/stm32l4xx/inc/
)

file(GLOB BOARD_SRC
    ${CMAKE_SOURCE_DIR}/BSP/board/stm32l4xx/src/*.c
)

add_library(BOARD STATIC
    ${BOARD_SRC}
)

target_include_directories(BOARD PUBLIC
    ${BOARD_INC}
)

target_compile_options(BOARD PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(BOARD PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(BOARD PRIVATE ${LINK_OPTIONS})

target_link_libraries(BOARD HAL_CMSIS)

set_target_properties(
    BOARD
    PROPERTIES
    C_CLANG_TIDY "clang-tidy"
)