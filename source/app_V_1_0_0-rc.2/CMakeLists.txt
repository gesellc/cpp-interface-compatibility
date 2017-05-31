project(ClientApplication)

add_executable(application_V_1_0_0-rc.2
        app.cpp)

include_directories(../inventory_V_2_0_0)

target_link_libraries(application_V_1_0_0-rc.2 inventory_V_2_0_0)


