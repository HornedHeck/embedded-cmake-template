set(NETWORK_INC
    ${CMAKE_SOURCE_DIR}/BSP/network/inc/
)

file(GLOB NETWORK_SRC
    ${CMAKE_SOURCE_DIR}/BSP/network/src/*.c
)

add_library(NETWORK STATIC
    ${NETWORK_SRC}
)

target_include_directories(NETWORK PUBLIC ${NETWORK_INC})

target_compile_options(NETWORK PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(NETWORK PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(NETWORK PRIVATE ${LINK_OPTIONS})

target_link_libraries(NETWORK PRIVATE BOARD)

set_target_properties(
    NETWORK
    PROPERTIES
    C_CLANG_TIDY "clang-tidy"
)