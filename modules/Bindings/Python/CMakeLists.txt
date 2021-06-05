
set(src_files "sinatra_py.c")

# get_public_headers(
#   public_header_files
#   ${PUBLIC_HEADER_DIRECTORY}
#   "sinatra_py.h"
# )

find_package(Python3 COMPONENTS Development NumPy) #Possibly add Interpreter later

add_library(sinatra_py
  SHARED
  ${src_files})
  #${public_headder_files} ${private_headder_files})

if (PYTHON_EXTENSION)
  set_target_properties(sinatra_py PROPERTIES SUFFIX ${PYTHON_EXTENSION})
endif()

# target_include_directories(datamodule 
#   PUBLIC 
#   ${Python_INCLUDE_DIRS}
#   ${Python_NumPy_INCLUDE_DIRS}
#   ${PUBLIC_HEADDER_DIRS})

target_compile_definitions(sinatra_py PUBLIC 
  MODULE_ARRAY_API_NAME=datamodule_ARRAY_API)

target_link_libraries(sinatra_py ${Python_LIBRARIES})
