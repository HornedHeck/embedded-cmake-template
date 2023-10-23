cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

include(${CMAKE_SOURCE_DIR}/cmake/common.cmake)

include(${CMAKE_SOURCE_DIR}/cmake/configs/${BOARD_FLAVOR}.cmake OPTIONAL)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

message("Build type: " ${CMAKE_BUILD_TYPE})

project(
  "projectname"
  LANGUAGES C ASM
  VERSION 0.1.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/bsp)

set(TARGET_NAME ${CMAKE_PROJECT_NAME})

file(GLOB APP_SRC ${CMAKE_SOURCE_DIR}/app/*.c)

set(APP_INC ${CMAKE_SOURCE_DIR}/app)

add_executable(${TARGET_NAME} ${APP_SRC})

target_include_directories(${TARGET_NAME} PRIVATE ${APP_INC})

target_compile_options(${TARGET_NAME} PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(${TARGET_NAME} PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(${TARGET_NAME} PRIVATE ${LINK_OPTIONS})

target_link_libraries(${TARGET_NAME} BOARD)

target_enable_lint(${TARGET_NAME})

add_custom_command(
  TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET_NAME}>
          ${TARGET_NAME}.bin
  BYPRODUCTS ${TARGET_NAME}.bin)
