cmake_minimum_required(VERSION 3.5)
project(academy_lib)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(angles REQUIRED)
find_package(OpenCV REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


add_library(${PROJECT_NAME}_colors  src/colors.cpp)

target_include_directories(${PROJECT_NAME}_colors
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  )

ament_target_dependencies(${PROJECT_NAME}_colors std_msgs OpenCV)
#ament_export_interfaces(export_${PROJECT_NAME}_colors HAS_LIBRARY_TARGET)
#ament_export_dependencies(OpenCV)

###bestpractices install rules
install(
  DIRECTORY include/
  DESTINATION include
)
###bestpractices
install(
  TARGETS ${PROJECT_NAME}_colors
  EXPORT export_${PROJECT_NAME}_colors
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME}_colors)

if(BUILD_TESTING)
  # Include linting and gtest
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_lint_cmake REQUIRED)
  ament_lint_auto_find_test_dependencies()
  # Add a gtest named ${PROJECT_NAME}_my_test
  ament_add_gtest(${PROJECT_NAME}_test_colors test/test_colors.cpp)

  if(TARGET ${PROJECT_NAME}_test_colors)
    target_link_libraries(${PROJECT_NAME}_test_colors ${PROJECT_NAME}_colors)
endif()
endif()

ament_package()
