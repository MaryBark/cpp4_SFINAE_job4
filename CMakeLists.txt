cmake_minimum_required(VERSION 3.2)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(cpp4_SFINAE_job4 VERSION ${PROJECT_VESRION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(sfinae_print main.cpp)
#add_executable(sfinae_test sfinae_test.cpp)
add_library(liba libSfinae.cpp libSfinae.h)

#set_target_properties(sfinae_print sfinae_test PROPERTIES
#        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
#        CMAKE_CXX_STANDARD 17
#        CMAKE_CXX_STANDARD_REQUIRED ON
#)

set(CMAKE_CXX_FLAGS "-std=c++1z")

target_link_libraries(sfinae_print
        cpp4_SFINAE_job4
)

# настраиваем boost для тестировки
#set_target_properties(sfinae_test PROPERTIES
#        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

#target_link_libraries(sfinae_test
#        ${Boost_LIBRARIES}
#        cpp4_SFINAE_job4
#)

install(TARGETS sfinae_print RUNTIME DESTINATION bin)

# создаем дебиан-пакет
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include(CPack)

# запускаем тесты
enable_testing()

#add_test(sfinae_test sfinae_test)
