# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/cursachDasha_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cursachDasha_autogen.dir/ParseCache.txt"
  "cursachDasha_autogen"
  )
endif()
