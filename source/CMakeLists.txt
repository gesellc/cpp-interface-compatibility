add_subdirectory(inventory_V_1_0_0) # concrete interface class
add_subdirectory(app_V_1_0_0-rc.1)  # uses id() getter of public class


add_subdirectory(inventory_V_2_0_0) # abstract interface class
                                    # (API incompatible)
add_subdirectory(app_V_1_0_0-rc.2)  # must change code and recompile


add_subdirectory(inventory_V_3_0_0) # add name() getter to interface
                                    # (ABI potentially incompatible)
add_subdirectory(app_V_1_0_0-rc.3)  # must recompile


add_subdirectory(app_V_1_1_0-rc.1)  #  starts using name()


add_subdirectory(inventory_V_4_0_0) # add setter as new abstract interface class
                                    # inheriting from the existing one

add_subdirectory(app_V_1_2_0-rc.1)  #  starts using setter methods


add_subdirectory(properties)
