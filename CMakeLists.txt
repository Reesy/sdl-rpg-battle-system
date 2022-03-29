cmake_minimum_required(VERSION 3.17.3) 

set(EXECUTABLE_NAME SDLRPGBATTLESYSTEM)

project(SDLRPGBATTLESYSTEM LANGUAGES CXX) #set the project name and to use C++

set(CMAKE_BUILD_TYPE Debug)

set(MY_SOURCES 
        src/main.cpp
        src/animator.cpp
        src/knight.cpp
        src/menu.cpp
        src/skeleton.cpp
        src/slime.cpp
        src/text.cpp
        include/IAnimatable.hpp
        include/ICollidable.hpp
        include/IMovable.hpp
        include/IVisible.hpp
        include/Animator.hpp
        include/Knight.hpp
        include/Menu.hpp
        include/Skeleton.hpp
        include/Slime.hpp
        include/IText.hpp
)

set(MY_RESOURCES resources)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    find_package(SDL2 REQUIRED)

    find_package(SDL2_image REQUIRED)

    find_package(SDL2_TTF REQUIRED)

    find_package(SDL2_mixer REQUIRED)
    
    include_directories(${SDL2_MIXER_INCLUDE_DIR})

    include_directories(${SDL2_TTF_INCLUDE_DIR})
    
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})

    include_directories(${SDL2_INCLUDE_DIR})
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${EXECUTABLE_NAME} ${MY_SOURCES})

file(COPY ${MY_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})



if (MSVC)
    message(STATUS "######------ MSVC Compiler detected ------######")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE_NAME})
    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy ${MY_RESOURCES} ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2-2.0.14/lib/x64/SDL2.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2-2.0.14/lib/x64/SDL2.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/SDL2_image.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libjpeg-9.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libpng16-16.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libtiff-5.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libwebp-7.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/zlib1.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_ttf-2.0.18/lib/x64/SDL2_ttf.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_mixer-2.0.4/lib/x64/SDL2_mixer.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_mixer-2.0.4/lib/x64/libvorbisfile-3.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_mixer-2.0.4/lib/x64/libvorbis-0.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_mixer-2.0.4/lib/x64/libogg-0.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_mixer-2.0.4/lib/x64/libFLAC-8.dll ${CMAKE_BINARY_DIR}/Debug
                                                            
    )
elseif (MINGW)
    message(STATUS "######------ MINGW Compiler detected ------######")
    add_custom_target(setup
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2-2.0.14/i686-w64-mingw32/bin/SDL2.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/SDL2_image.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libjpeg-9.dll  ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libpng16-16.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libtiff-5.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libwebp-7.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/zlib1.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_ttf-2.0.18/i686-w64-mingw32/bin/SDL2_ttf.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_mixer-2.0.4/i686-w64-mingw32/bin/SDL2_mixer.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_mixer-2.0.4/i686-w64-mingw32/bin/libvorbisfile-3.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_mixer-2.0.4/i686-w64-mingw32/bin/libvorbis-0.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_mixer-2.0.4/i686-w64-mingw32/bin/libogg-0.dll ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_mixer-2.0.4/i686-w64-mingw32/bin/libFLAC-8.dll ${CMAKE_BINARY_DIR}

    )
    add_dependencies(${EXECUTABLE_NAME} setup)
endif()



if (MSVC)
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS "-O3 -s USE_SDL=2 -s USE_SDL_TTF=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\",\"jpg\"]' -s USE_SDL_MIXER=2 -s USE_FREETYPE=1 -s ALLOW_MEMORY_GROWTH=1 --preload-file resources/")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    file(COPY "index.html" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "resources/icon.png" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "server.py" DESTINATION ${CMAKE_BINARY_DIR})
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    target_link_libraries(${EXECUTABLE_NAME})
else()
    target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})
endif()