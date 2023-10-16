cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE
    ${CMAKE_SOURCE_DIR}/cmake/arm_none_eabi_toolchain.cmake)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
message("Build type: " ${CMAKE_BUILD_TYPE})

project(
  "o-kawai-koto"
  LANGUAGES C ASM
  VERSION 0.1.0)

set(CMAKE_C_CPPLINT "cpplint")

set(COMPILE_OPTIONS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    -Wall
    $<$<CONFIG:Debug>:-Og>)

set(COMPILE_DEFINITIONS STM32L432xx USE_HAL_DRIVER)

set(LINK_OPTIONS
    -T${CMAKE_SOURCE_DIR}/drivers/STM32L432KCUx_FLASH.ld
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    # -specs=nano.specs -lc -lm -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    # -Wl,--gc-sections
)

add_subdirectory(${CMAKE_SOURCE_DIR}/drivers)

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

add_custom_command(
  TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET_NAME}>
          ${TARGET_NAME}.bin
  BYPRODUCTS ${TARGET_NAME}.bin)
