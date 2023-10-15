file(GLOB BOARD_SRC
    ${CMAKE_CURRENT_LIST_DIR}/stm32l4xx/src/*.c
)

set(BOARD_INC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

set(BOARD_PRIVATE_INC
    ${CMAKE_CURRENT_LIST_DIR}/stm32l4xx/include
)

add_library(BOARD STATIC
    ${BOARD_SRC}
)

target_include_directories(BOARD 
    PUBLIC ${BOARD_INC}
    PRIVATE ${BOARD_PRIVATE_INC}
)

target_link_libraries(BOARD HAL_CMSIS)

target_compile_options(BOARD PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(BOARD PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(BOARD PRIVATE ${LINK_OPTIONS})
