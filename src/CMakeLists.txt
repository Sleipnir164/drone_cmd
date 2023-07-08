set(drone_sources
    drone_lib.cpp
    drone_lib.h)

set(control_sources
    drone_cmd.cpp
    drone_cmd.h)

add_library(drone_function OBJECT ${drone_sources})
add_library(control_function OBJECT ${control_sources})

add_executable(run-cmd main.cpp)
target_link_libraries(run-cmd PUBLIC drone_function control_function)
set_target_properties(run-cmd PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
