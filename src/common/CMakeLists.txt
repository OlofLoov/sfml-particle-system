set(CMAKE_OSX_ARCHITECTURES "x86_64")
add_library(common "")

target_sources(common
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Random.cpp
    
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Random.hpp
  )
target_include_directories(common
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(common
    PRIVATE
    sfml-graphics
  )