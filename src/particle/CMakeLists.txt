add_library(particle "")

target_sources(particle
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ParticleEmitter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleColorUpdater.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleEmitPositionUpdater.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleVelocityUpdater.cpp
    

  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/ParticleEmitter.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleProperties.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleEmitterSettings.hpp
    ${CMAKE_CURRENT_LIST_DIR}/IParticleUpdater.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleColorUpdater.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleEmitPositionUpdater.hpp
    ${CMAKE_CURRENT_LIST_DIR}/ParticleVelocityUpdater.hpp
    
    
  )
  
target_include_directories(particle
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(particle    
    PRIVATE
    common
    sfml-graphics
  )