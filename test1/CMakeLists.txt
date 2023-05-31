cmake_minimum_required(VERSION 3.0)
project ("vulkan t1")

find_package(Vulkan REQUIRED)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thridparty ${CMAKE_CURRENT_BINARY_DIR}/thridparty)

# Add source to this project's executable.
add_executable (chapter_0 
  main.cpp
  vk_engine.cpp
  vk_engine.h
  vk_types.h
  vk_initializers.cpp
  vk_initializers.h)


set_property(TARGET chapter_0 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:chapter_0>)

target_include_directories(chapter_0 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(chapter_0 vkbootstrap vma glm tinyobjloader imgui stb_image)

target_link_libraries(chapter_0 Vulkan::Vulkan sdl2)
