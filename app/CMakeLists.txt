add_executable(app app.c)

target_include_directories(app PUBLIC ../include)
target_link_libraries(app sinatra_core)

copy_link_libraries_to_build(app)

install(TARGETS app
        RUNTIME
        LIBRARY)
