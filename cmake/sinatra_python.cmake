
set(PYTHON_EXTENSION_DOC_STRING
"Do not manually change this variable unless you are sure you need/want to. \
Using setup.py with CMake_Extensions will set this automatically and running \
CMake with variables left as default will set the correct extension for \
libraries without the python version information that setup.py includes.")

if (NOT PYTHON_EXTENSION)
  if (${WIN32})
    set(PYTHON_EXTENSION ".pyd" CACHE STRING ${PYTHON_EXTENSION_DOC_STRING})
  else()
    set(PYTHON_EXTENSION ".so"  CACHE STRING ${PYTHON_EXTENSION_DOC_STRING})
  endif()
endif()

