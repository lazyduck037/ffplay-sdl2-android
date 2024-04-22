cmake_minimum_required(VERSION 3.6)

project(main)

find_library(SDL2 SDL2)

# swresample
add_library(swresample SHARED IMPORTED)
set_target_properties(swresample PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libswresample.so")

# avfilter
add_library(avfilter SHARED IMPORTED)
set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libavfilter.so")

# avdevice
add_library(avdevice SHARED IMPORTED)
set_target_properties(avdevice PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libavdevice.so")

# avcodec
add_library(avcodec SHARED IMPORTED)
set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libavcodec.so")

# swscale
add_library(swscale SHARED IMPORTED)
set_target_properties(swscale PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libswscale.so")

# avformat
add_library(avformat SHARED IMPORTED)
set_target_properties(avformat PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libavformat.so")

#avutil
add_library(avutil SHARED IMPORTED)
set_target_properties(avutil PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/${ANDROID_ABI}/libavutil.so")

include_directories(ffmpeg/${ANDROID_ABI}/include renderer.h cmdutils.h ffplay.h)
add_library(main SHARED renderer.c cmdutils.c ffplay.c)

install(TARGETS main
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

target_link_libraries(main PRIVATE SDL2 GLESv1_CM GLESv2 OpenSLES avutil swscale avformat avcodec avdevice avfilter swresample log android)
