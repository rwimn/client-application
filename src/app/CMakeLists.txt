add_executable(client-application main.cpp)
target_link_libraries(client-application PRIVATE gui_static)

target_include_directories(client-application PUBLIC "${CMAKE_SOURCE_DIR}/src/")

install(TARGETS client-application DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
