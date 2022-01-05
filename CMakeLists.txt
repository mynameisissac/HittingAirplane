cmake_minimum_required(VERSION 3.20)
project(STG)

set(CMAKE_CXX_STANDARD 20)

add_executable(STG src/main.cpp src/STGEngine.cpp include/STGEngine.h src/handleInput.cpp src/Bullet.cpp include/Bullet.h src/Shooter.cpp include/Shooter.h include/UI_common.h)

include_directories(include "C:/Program Files/SFML-2.5.1/include")

# connect the SFML thing
set(SFML_DIR "C:/Program Files/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS window graphics audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
endif()

# assets files
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build for windows
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Program Files/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()