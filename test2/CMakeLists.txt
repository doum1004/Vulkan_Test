cmake_minimum_required(VERSION 3.0)
project ("vulkan test2")

find_package(Vulkan REQUIRED)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thridparty ${CMAKE_CURRENT_BINARY_DIR}/thridparty)

# Add source to this project's executable.
add_executable (apps 
  main.cpp
  vk_engine.cpp
  vk_engine.h
  vk_types.h
  vk_initializers.cpp
  vk_initializers.h)


set_property(TARGET apps PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:apps>)

target_include_directories(apps PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(apps vkbootstrap vma glm tinyobjloader imgui stb_image)

target_link_libraries(apps Vulkan::Vulkan sdl2)
