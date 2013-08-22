cmake_minimum_required (VERSION 2.6) 

add_definitions(-std=c++11)

# run: cmake -Dtest=ON
option(test "Build all tests." OFF) # makes boolean 'test' available

# Modules: 
# cmake --help-module Find
# /usr/share/cmake-2.8/Modules/

set(CMAKE_FIND_LIBRARY_PREFIXES lib)
set(Boost_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)

set(BOOST_INCLUDEDIR /usr/include/)
set(BOOST_LIBRARYDIR /usr/lib)

find_package( Boost REQUIRED COMPONENTS filesystem regex )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

project(funcpp)
add_subdirectory(src)
add_subdirectory(tests)

if (test)
        # This adds another subdirectory, which has project(gtest)
        add_subdirectory(lib/gtest-1.6.0)

        enable_testing()

        # Include the gtest library
        # gtest_SOURCE_DIR is available due to project(gtest) above
        include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

        include_directories(include)

        ##############
        # Unit Tests
        ##############
        add_executable(runUnitTests tests/stringTest.cpp tests/regexTest.cpp)

        # standard linking to gtest stuff
        target_link_libraries(runUnitTests gtest gtest_main)

        # extra linking for the project
        target_link_libraries(runUnitTests funcpp)

        target_link_libraries(runUnitTests ${Boost_LIBRARIES})

        # This is so you can do 'make test' to see all your tests run, instead of manua$
        add_test(NAME that-test-I-made COMMAND runUnitTests)
        # can also omit NAME and COMMAND
        add_test(that-other-test-I-made runUnitTests) # the second argument could be so$
endif()


