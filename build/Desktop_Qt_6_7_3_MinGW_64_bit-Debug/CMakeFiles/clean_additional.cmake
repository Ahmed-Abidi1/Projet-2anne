# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\proji_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\proji_autogen.dir\\ParseCache.txt"
  "proji_autogen"
  )
endif()
