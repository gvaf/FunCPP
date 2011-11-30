include_directories (.)
include_directories (../include)

add_definitions(-std=gnu++0x)

find_library(PCRE_LIBRARY pcre)
find_library(PCRECPP_LIBRARY pcrecpp)

add_library(funcpp array.cpp string.cpp)

target_link_libraries(funcpp ${PCRE_LIBRARY})
target_link_libraries(funcpp ${PCRECPP_LIBRARY})
