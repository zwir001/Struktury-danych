set(MODULE_NAME program)

message("compile ${MODULE_NAME}")

set(INTERNAL_FILES
  Program.cpp
)

set(PUBLIC_HEADERS
  Program.hpp
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
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(
  ${MODULE_NAME}
  PRIVATE
    lib::tablica
    lib::lista
    lib::kopiec
    lib::bst
    lib::drzewoCzerwonoCzarne
)

add_library(lib::${MODULE_NAME} ALIAS ${MODULE_NAME})