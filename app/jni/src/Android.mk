LOCAL_PATH := $(call my-dir)


# swscale
include $(CLEAR_VARS)
LOCAL_MODULE := swscale-4
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libswscale.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# avformat
include $(CLEAR_VARS)
LOCAL_MODULE := avformat-57
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libavformat.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# avcodec
include $(CLEAR_VARS)
LOCAL_MODULE := avcodec-57
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libavcodec.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# swresample-2
include $(CLEAR_VARS)
LOCAL_MODULE := swresample-2
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libswresample.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# avcodec
include $(CLEAR_VARS)
LOCAL_MODULE := avutil-55
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libavutil.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# avdevice
include $(CLEAR_VARS)
LOCAL_MODULE := avdevice-57
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libavdevice.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# avfilter
include $(CLEAR_VARS)
LOCAL_MODULE := avfilter-6
LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libavfilter.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
include $(PREBUILT_SHARED_LIBRARY)

# postproc-54
#include $(CLEAR_VARS)
#LOCAL_MODULE := postproc-54
#LOCAL_SRC_FILES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/libpostproc-54.so
#LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
#include $(PREBUILT_SHARED_LIBRARY)

###########################
#
# SDL shared main
#
###########################
include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ffmpeg/$(TARGET_ARCH_ABI)/include
LOCAL_C_INCLUDES += cmdutils.h ffplay.h ffplay_renderer.h
#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
# Add your application source files hexxre...
#LOCAL_SRC_FILES := test.c\
# 				ffplay.c

#LOCAL_SRC_FILES := simpleraw.c
#LOCAL_SRC_FILES := simpleh265.c

LOCAL_SRC_FILES :=cmdutils.c simpleffplay.c ffplay_renderer.c
LOCAL_SHARED_LIBRARIES := SDL2 avutil-55 avcodec-57 swresample-2 avformat-57 swscale-4 avdevice-57 avfilter-6
LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)
