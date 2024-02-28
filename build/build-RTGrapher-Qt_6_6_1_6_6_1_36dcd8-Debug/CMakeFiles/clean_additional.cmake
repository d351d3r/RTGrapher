# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/RTGrapher_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/RTGrapher_autogen.dir/ParseCache.txt"
  "RTGrapher_autogen"
  )
endif()
