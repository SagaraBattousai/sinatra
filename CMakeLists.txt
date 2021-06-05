# ----------------------------------------------------------
# Root CMake file for Sinatra
# ----------------------------------------------------------

cmake_minimum_required(VERSION 3.15)

project(Sinatra
        VERSION 0.0.1
        DESCRIPTION "Sinatra ML Library"
        LANGUAGES C CXX)

# ----------------------------------------------------------
# Include modules
# ----------------------------------------------------------
include(GNUInstallDirs)
include(cmake/sinatra_options.cmake)
include(cmake/sinatra_utils.cmake)
include(cmake/sinatra_python.cmake)


# ----------------------------------------------------------
# Install options
# ----------------------------------------------------------
set(SINATRA_INSTALL_PRE_PREFIX 
  "${CMAKE_CURRENT_BINARY_DIR}/install/${CMAKE_BUILD_TYPE}")

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  if (CMAKE_SIZEOF_VOID_P GREATER_EQUAL 8)
    set(CMAKE_INSTALL_PREFIX 
      # "${SINATRA_INSTALL_PRE_PREFIX}/x64/${PROJECT_NAME}"
      "${SINATRA_INSTALL_PRE_PREFIX}/${PROJECT_NAME}"
      CACHE PATH "Project Install directory" FORCE)
  else()
    set(CMAKE_INSTALL_PREFIX 
      "${SINATRA_INSTALL_PRE_PREFIX}/x86_64/${PROJECT_NAME}"
      CACHE PATH "Project Install directory" FORCE)
  endif()
endif()

# ======================================================== #
# ============== Module Building Variables =============== #
# ======================================================== #
set(BUILD_CLUSTERING_MODULE ON CACHE BOOL 
  "Build Clustering module that includes ML Algorithms such as K-Means etc")

# ======================================================== #
# ============== Language Binding Variables ============== #
# ======================================================== #
set(GENERATE_PYTHON_BINDINGS OFF CACHE BOOL 
  "Whether or not to generate Python Language Bindings")

add_subdirectory("modules")
