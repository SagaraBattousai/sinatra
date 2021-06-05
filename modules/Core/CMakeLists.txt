
set(src_files "vector.c")

get_public_headers(
  public_header_files
  ${PUBLIC_HEADER_DIRECTORY}
  "vector.h"
)

add_library(sinatra_core SHARED ${src_files} ${public_header_files})

target_include_directories(sinatra_core PUBLIC ${PUBLIC_INCLUDE_DIRECTORY})
set_target_properties(sinatra_core PROPERTIES PUBLIC_HEADER "${public_header_files}")

target_compile_definitions(sinatra_core PUBLIC EXPORT_SINATRA_VECTOR)

install(TARGETS sinatra_core
        RUNTIME
        PUBLIC_HEADER
        LIBRARY)
