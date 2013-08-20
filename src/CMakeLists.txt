include_directories (.)
include_directories (../include)

add_library(funcpp array.cpp string.cpp)

#find_library(PCRE_LIBRARY pcre)
#find_library(PCRECPP_LIBRARY pcrecpp)
#target_link_libraries(funcpp ${PCRE_LIBRARY})
#target_link_libraries(funcpp ${PCRECPP_LIBRARY})
