set(CMAKE_OSX_ARCHITECTURES "x86_64")
add_executable(particlesystem Main.cpp)
#include_directories(${CMAKE_CURRENT_LIST_DIR}/external/sfml/include)

#add_subdirectory(external)

add_subdirectory(common)
add_subdirectory(particle)
add_subdirectory(views)

add_subdirectory(app)

# Provide the full path to the library, so CMake knows where to find it.
target_link_libraries(particlesystem
  PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    particle
    ImGui-SFML::ImGui-SFML
    views
    app
    


    #${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-graphics.dylib
    #${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-window.dylib
    #${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-system.dylib
  )