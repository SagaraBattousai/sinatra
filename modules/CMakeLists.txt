
# ----------------------------------------------------------
# Variables
# ----------------------------------------------------------
get_filename_component(PUBLIC_INCLUDE_DIRECTORY "../include" ABSOLUTE)
set(PUBLIC_HEADER_DIRECTORY "${PUBLIC_INCLUDE_DIRECTORY}/sinatra")

# ----------------------------------------------------------
# Include modules to build
# ----------------------------------------------------------


# Core modules to build
# ----------------------------------------------------------
add_subdirectory(Core)

# Optional modules to build
# ----------------------------------------------------------
add_optional_directory("Clustering" ${BUILD_CLUSTERING_MODULE})

# Language bindings to generate
# ----------------------------------------------------------
add_optional_directory("Bindings/Python" ${GENERATE_PYTHON_BINDINGS})

