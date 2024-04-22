#ifndef FF_PLAY
#define FF_PLAY
#ifdef __cplusplus
extern "C" {
#endif
#include "config.h"

#include "libavcodec/avcodec.h"
#include "libavcodec/avfft.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/samplefmt.h"
#include "libavutil/frame.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/fifo.h"
#include "libavutil/parseutils.h"
#include "libavutil/time.h"
#include "libavutil/bprint.h"
#include "libavutil/tx.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavdevice/avdevice.h"
#include "libavfilter/buffersink.h"

#include "SDL.h"
#include "SDL_mutex.h"
#include "SDL_thread.h"
#include "SDL_render.h"
#include "SDL_audio.h"

#include <stdbool.h>
#include <android/log.h>

#include "renderer.h"

#ifdef __cplusplus
}
#endif


#endif