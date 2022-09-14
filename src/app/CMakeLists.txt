add_library(app "")

target_sources(app
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/App.cpp
    
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/App.hpp
  )
target_include_directories(app
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(app
    PRIVATE
    ImGui-SFML::ImGui-SFML
    sfml-graphics
    particle
    views 
    common
  )