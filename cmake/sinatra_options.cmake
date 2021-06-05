
macro(add_optional_directory directory cond)
  if (${cond})
    add_subdirectory(${directory})
  endif()
endmacro()
