LOCAL_PATH := $(call my-dir)
# 遍历目录及子目录的函数
define walk
$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef
include $(CLEAR_VARS)

LOCAL_MODULE    := Dog

#LOCAL_SRC_FILES := Dog.cpp
#LOCAL_SRC_FILES += Binary.cpp
#LOCAL_C_INCLUDES := Binary.h
#LOCAL_C_INCLUDES += adsStd.h

ALLFILES_CPP := $(call walk, $(LOCAL_PATH)/test)
ALLFILES_CPP += $(call walk, $(LOCAL_PATH)/7z)


FILE_LIST_CPP := $(filter %.cpp,$(ALLFILES_CPP))
LOCAL_SRC_FILES := $(FILE_LIST_CPP:$(LOCAL_PATH)/%=%)

FILE_LIST_H := $(filter-out %.cpp,$(ALLFILES_CPP))
LOCAL_C_INCLUDES := 7z
LOCAL_C_INCLUDES += test


LOCAL_LDLIBS += -llog 
LOCAL_LDLIBS += -landroid
include $(BUILD_SHARED_LIBRARY)

#将该模块编译成静态库
#include $(BUILD_STATIC_LIBRARY)
