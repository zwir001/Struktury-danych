set(MODULE_NAME drzewoCzerwonoCzarne)

message("compile ${MODULE_NAME}")

set(INTERNAL_FILES
    DrzewoCzerwonoCzarne.cpp
)

set(PUBLIC_HEADERS
    DrzewoCzerwonoCzarne.hpp
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