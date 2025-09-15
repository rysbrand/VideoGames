# CMakeList.txt : CMake project for VideoGames, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("VideoGames")

# Add source to this project's executable.
add_executable (VideoGames "VideoGames.cpp" "VideoGames.h"   )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VideoGames PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

target_link_libraries(VideoGames PRIVATE sfml-graphics sfml-window sfml-system)
#target_link_libraries(main PRIVATE SFML::Graphics)
