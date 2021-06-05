
function(get_public_headers varname public_header_directory)
  set(public_headers ${ARGN})
  list(TRANSFORM public_headers PREPEND "${public_header_directory}/")
  set(${varname} ${public_headers} PARENT_SCOPE)
endfunction()
