cmake_minimum_required(VERSION 1.0)

project( CornerDetection )

find_package(OpenCV REQUIRED)
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})
add_executable (CornerDetection CornerDetection.cpp)
target_link_libraries(CornerDetection 
  ${OpenCV_LIBRARIES}
  )
