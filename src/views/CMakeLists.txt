add_library(views "")

target_sources(views
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ParticleSystemView.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleSystemMenuView.cpp
    
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/IView.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleSystemView.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleSystemView.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Views.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleSystemMenuView.hpp
    ${CMAKE_CURRENT_LIST_DIR}/WidgetHelper.hpp
    
  )
target_include_directories(views
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(views
    PRIVATE
    ImGui-SFML::ImGui-SFML
    sfml-graphics
    particle
    common
  )