include_directories (.)
include_directories (../include)

add_definitions(-std=gnu++0x)

find_library(PCRE_LIBRARY pcre)

add_library(funcpp array.cpp string.cpp)

target_link_libraries(funcpp ${PCRE_LIBRARY})
