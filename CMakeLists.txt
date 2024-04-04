project ("AISD-TREE")

add_executable (AISD-TREE "src/main.cpp"  "algorithm/algorithm.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AISD-TREE PROPERTY CXX_STANDARD 20)
endif()