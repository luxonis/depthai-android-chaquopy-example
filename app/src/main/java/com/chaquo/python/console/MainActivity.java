package com.chaquo.python.console;

import android.app.*;
import android.util.Log;

import com.chaquo.python.utils.*;

public class MainActivity extends PythonConsoleActivity {

    /**
     * A native method that is implemented by the 'depthai_android_jni_example' native library,
     * which is packaged with this application.
     */
    public static native void init_android_libusb();

    // On API level 31 and higher, pressing Back in a launcher activity sends it to the back by
    // default, but that would make it difficult to restart the activity.
    @Override public void onBackPressed() {
        finish();
    }

    @Override protected Class<? extends Task> getTaskClass() {
        return Task.class;
    }

    static {
       System.loadLibrary("depthai-libusb-jni");
    }
    public static class Task extends PythonConsoleActivity.Task {
        public Task(Application app) {
            super(app);
        }

        @Override public void run() {
            // Init Android Java based libusb first
            init_android_libusb();
            py.getModule("main").callAttr("main");
        }
    }
}
