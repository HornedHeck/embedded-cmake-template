set(BOARD_FLAVOR
    "stm32l4xx"
    CACHE STRING "Board used")
set_property(CACHE BOARD_FLAVOR PROPERTY STRINGS "stm32l4xx")

file(GLOB BOARD_SRC ${CMAKE_CURRENT_LIST_DIR}/${BOARD_FLAVOR}/src/*.c)

set(BOARD_INC ${CMAKE_CURRENT_LIST_DIR}/include)

set(BOARD_PRIVATE_INC ${CMAKE_CURRENT_LIST_DIR}/${BOARD_FLAVOR}/include)

set(STARTUP_SRC ${CMAKE_CURRENT_LIST_DIR}/startup_stm32l432xx.s)

add_library(BOARD STATIC)

target_sources(
  BOARD
  PUBLIC ${BOARD_SRC}
  PRIVATE ${STARTUP_SRC})

target_include_directories(BOARD PUBLIC ${BOARD_INC} ${BOARD_PRIVATE_INC})

add_subdirectory(${BOARD_FLAVOR})

target_compile_options(BOARD PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(BOARD PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(BOARD PRIVATE ${LINK_OPTIONS})

set_target_properties(BOARD PROPERTIES C_CLANG_TIDY "clang-tidy")
