package org.libsdl.app;

import android.content.Context;
import android.content.res.AssetManager;
import android.os.Looper;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Handler;

public class Utils {
    public static final String H264_HTTPS = "https://commondatastorage.googleapis.com/gtv-videos-bucket/sample/ElephantsDream.mp4";
    public static final String H264_ASSET = "/h264.mp4";
    public static final boolean USE_FILE = true;

    public static String firstArgument(Context context) {
        if (USE_FILE) {
            String cache = context.getExternalCacheDir().getAbsolutePath().toString();
            return cache + H264_ASSET;
        }else {
            return H264_HTTPS;
        }
    }

    public static void runCopyFromAssetToCache(Context context, String fileNameAsset) {
        String cache = context.getExternalCacheDir().getAbsolutePath().toString();
        File existFile = new File(cache + "/" + fileNameAsset);
        if (existFile.exists()) {
            return;
        }

        try {
            copyFile(context, fileNameAsset);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void copyFile(Context context, String fileNameAsset) throws IOException {
        String cacheDir = context.getExternalCacheDir().getAbsolutePath().toString();
        AssetManager assetManager = context.getAssets();

        File file = new File(cacheDir + "/" + fileNameAsset);

        if (!file.exists()) {
            new File(cacheDir).mkdirs();

            InputStream input = null;
            OutputStream output = null;
            try {
                input = assetManager.open(fileNameAsset);
                output = new FileOutputStream(file);
                byte[] buffer = new byte[input.available()];
                int length;
                while ((length = input.read(buffer)) != -1) {
                    output.write(buffer, 0, length);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (input != null) {
                    input.close();
                }
                if (output != null) {
                    output.close();
                }

            }
        }
    }
}
