cmake_minimum_required(VERSION 3.10)

project(Tetris)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/sdl2-cmake-scripts")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
add_executable(Tetris
        src/main.c  src/point.h src/defs.h src/block.c src/block.h src/grid.c src/grid.h src/block.c src/tetromino.c src/tetromino.h src/score.c src/score.h src/sound.c src/sound.h)

include_directories("/usr/include/SDL2")
#should really be using ${SDL2_INCLUDE_DIR}
#        ${SDL2_IMAGE_INCLUDE_DIR}
#        ${SDL2_TTF_INCLUDE_DIR}
#        ${SDL2_MIXER_INCLUDE_DIR} but the script won't find SDL2 MIXER
target_link_libraries(Tetris ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        "/usr/lib64/libSDL2_mixer.so") # same as above

target_link_libraries(Tetris ${SDL2_LIBRARIES})
