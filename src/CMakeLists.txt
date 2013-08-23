include_directories (.)
include_directories (../include)

add_library(funcpp array.cpp string.cpp)

target_link_libraries(funcpp ${Boost_LIBRARIES} )

