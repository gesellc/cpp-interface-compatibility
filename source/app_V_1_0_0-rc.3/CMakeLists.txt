project(ClientApplication)

add_executable(application_V_1_0_0-rc.3
        app.cpp)

include_directories(../inventory_V_3_0_0)

target_link_libraries(application_V_1_0_0-rc.3 inventory_V_3_0_0)


