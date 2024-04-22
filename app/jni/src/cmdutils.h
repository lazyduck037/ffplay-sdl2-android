#ifndef CMDUTIL_H
#define CMDUTIL_H
#include "config.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"

extern AVDictionary *format_opts, *codec_opts;
extern AVDictionary *sws_dict;
extern AVDictionary *swr_opts;
/**
 * Check if the given stream matches a stream specifier.
 *
 * @param s  Corresponding format context.
 * @param st Stream from s to be checked.
 * @param spec A stream specifier of the [v|a|s|d]:[\<stream index\>] form.
 *
 * @return 1 if the stream matches, 0 if it doesn't, <0 on error
 */
int setup_find_stream_info_opts(AVFormatContext *s,
                                AVDictionary *codec_opts,
                                AVDictionary ***dst);

/**
 * Filter out options for given codec.
 *
 * Create a new options dictionary containing only the options from
 * opts which apply to the codec with ID codec_id.
 *
 * @param opts     dictionary to place options in
 * @param codec_id ID of the codec that should be filtered for
 * @param s Corresponding format context.
 * @param st A stream from s for which the options should be filtered.
 * @param codec The particular codec for which the options should be filtered.
 *              If null, the default one is looked up according to the codec id.
 * @param dst a pointer to the created dictionary
 * @return a non-negative number on success, a negative error code on failure
 */
int filter_codec_opts(const AVDictionary *opts, enum AVCodecID codec_id,
                      AVFormatContext *s, AVStream *st, const AVCodec *codec,
                      AVDictionary **dst);
#endif
