#include <stdlib.h>
#include <inttypes.h>
#include <jni.h>
#include <android/log.h>
#include <cstdlib>
#define LOG_TAG "depthaiAndroid"
#define log(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)

extern "C"
    JNIEXPORT void JNICALL
Java_com_chaquo_python_console_MainActivity_init_1android_1libusb(JNIEnv *env, jclass self) {
    // Send JavaVM pointer to underlying libraries
    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    char javavmSerialized[64] = {0};
    uintptr_t ptr_val = reinterpret_cast<uintptr_t>(jvm);
    sprintf(javavmSerialized, "%" PRIuPTR, ptr_val);
    setenv("DEPTHAI_LIBUSB_ANDROID_JAVAVM", javavmSerialized, true);
    log("Applied Android Libusb JavaVM pointer: %s", javavmSerialized);
}


