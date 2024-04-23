# Ffplay SDL2 For Android Platform
This repo port ffplay program to android appliaction. FFplay is a tool in ffmpeg-7.0. The repo also uses SDL2 to render texture. The repo ingores parse command params, it passes params from Java Class.
# Supported Android ABIs
+ `armeabi` (Android 21+)
+ `armeabi-v7a` (Android 21+)
+ `x86`  (Android 21+)
+ `arm64-v8a`  (Android 21+)
+ `x86_64` (Android 21+)
# Prebuild Version 
 * **FFmeg 7.0** [Download](https://ffmpeg.org/releases/ffmpeg-7.0.tar.xz)
 * **SDL2 2.28.5** [Download](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5)

 If you want to build ffmpeg-7.0 prebuild by your self, you can reference to my repo [fmpeg-openssl-android](https://github.com/lazyduck037/ffmpeg-openssl-android)
# Build Info
 My build with:
  * Android NDK: [r25c(25.2.9519653)](https://github.com/android/ndk/wiki/Unsupported-Downloads)
  * HOST: MAC/OSX, Linux (Not Test), Window 11
  * Gradle version: 8.3.2
  * Android Studio: Android Studio Iguana | 2023.2.1 Patch 2
  * CMake: 3.10.2.4988404 / 3.22.1 in Android SDK
# How to build
  * Change ndk.dir=path/to/android-ndk, sdk.dir=path/to/android-sdk in local.properties file to yours
    
  My case:
  ```
  ndk.dir=/Users/lap15292-local/Android/Sdk/ndk/25.1.8937393
  sdk.dir=/Users/lap15292-local/Android/Sdk
  ```
 * To run with mp4 file in Sdcard, change USE_FILE variable in Utils.java file
  ```java
  public static final boolean USE_FILE = true;
  ```
 * To run with Url, change the variables in Utils.java
  ```java
  public static final boolean USE_FILE = false;
  public static final String H264_HTTPS = "Your-URL";
  ```
  My case:
   ```java
  public static final String H264_HTTPS = "https://commondatastorage.googleapis.com/gtv-videos-bucket/sample/ElephantsDream.mp4";
  ```
