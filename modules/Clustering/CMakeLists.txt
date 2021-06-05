
set(src_files "clustering.c")

get_public_headers(
  public_header_files
  ${PUBLIC_HEADER_DIRECTORY}
  "clustering.h" "vector.h"
)

add_library(clustering SHARED ${src_files} ${public_header_files})

target_include_directories(clustering PUBLIC ../../include/sinatra)
set_target_properties(clustering PROPERTIES PUBLIC_HEADER "${public_header_files}")

install(TARGETS clustering
        RUNTIME
        PUBLIC_HEADER
        LIBRARY)
