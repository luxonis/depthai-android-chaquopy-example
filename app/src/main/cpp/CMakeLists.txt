cmake_minimum_required(VERSION 3.22.1)

project("depthai-libusb-jni")

add_library(${CMAKE_PROJECT_NAME} SHARED depthai-libusb-jni.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    android
    log
)
