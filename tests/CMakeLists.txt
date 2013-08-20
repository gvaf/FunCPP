include_directories(../include)

link_directories(${PROJECT_BINARY_DIR}) 

add_definitions(-std=gnu++0x)

add_executable(test main.cpp) 

target_link_libraries(test funcpp) 
