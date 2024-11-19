cmake_minimum_required(VERSION 3.10)
project(GOL_background)

# Find the Cairo package
find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)

# Add executable
add_executable(GOL_background main.cpp)

# Include Cairo directories
include_directories(${CAIRO_INCLUDE_DIRS})

# Link Cairo library
target_link_libraries(GOL_background ${CAIRO_LIBRARIES})

# Add additional flags if needed
target_compile_options(GOL_background PRIVATE ${CAIRO_CFLAGS_OTHER})
find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)
pkg_check_modules(X11 REQUIRED x11)

target_link_libraries(GOL_background
        ${CAIRO_LIBRARIES}
        ${X11_LIBRARIES}
)

target_include_directories(GOL_background PRIVATE
        ${CAIRO_INCLUDE_DIRS}
        ${X11_INCLUDE_DIRS}
)

# Avoid warnings for unused variables
add_definitions(${CAIRO_CFLAGS_OTHER})
add_definitions(${X11_CFLAGS_OTHER})
