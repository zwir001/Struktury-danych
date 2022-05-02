set(MODULE_NAME kopiec)

message("compile ${MODULE_NAME}")

set(INTERNAL_FILES
    Kopiec.cpp
)

set(PUBLIC_HEADERS
    Kopiec.hpp
)

add_library(
  ${MODULE_NAME}
  ${INTERNAL_FILES}
  ${PUBLIC_HEADERS}
)

target_include_directories(
  ${MODULE_NAME}
  PRIVATE 
    ${MODULE_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${MODULE_NAME}
)

add_library(lib::${MODULE_NAME} ALIAS ${MODULE_NAME})