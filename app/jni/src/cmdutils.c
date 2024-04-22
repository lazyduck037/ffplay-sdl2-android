#include "cmdutils.h"

AVDictionary *swr_opts;
AVDictionary *format_opts, *codec_opts;
enum show_muxdemuxers {
    SHOW_DEFAULT,
    SHOW_DEMUXERS,
    SHOW_MUXERS,
};

int check_stream_specifier(AVFormatContext *s, AVStream *st, const char *spec) {
    int ret = avformat_match_stream_specifier(s, st, spec);
    if (ret < 0)
        av_log(s, AV_LOG_ERROR, "Invalid stream specifier: %s.\n", spec);
    return ret;
}

int filter_codec_opts(const AVDictionary *opts, enum AVCodecID codec_id,
                      AVFormatContext *s, AVStream *st, const AVCodec *codec,
                      AVDictionary **dst)
{
    AVDictionary    *ret = NULL;
    const AVDictionaryEntry *t = NULL;
    int            flags = s->oformat ? AV_OPT_FLAG_ENCODING_PARAM
                                      : AV_OPT_FLAG_DECODING_PARAM;
    char          prefix = 0;
    const AVClass    *cc = avcodec_get_class();

    if (!codec)
        codec            = s->oformat ? avcodec_find_encoder(codec_id)
                                      : avcodec_find_decoder(codec_id);

    switch (st->codecpar->codec_type) {
        case AVMEDIA_TYPE_VIDEO:
            prefix  = 'v';
            flags  |= AV_OPT_FLAG_VIDEO_PARAM;
            break;
        case AVMEDIA_TYPE_AUDIO:
            prefix  = 'a';
            flags  |= AV_OPT_FLAG_AUDIO_PARAM;
            break;
        case AVMEDIA_TYPE_SUBTITLE:
            prefix  = 's';
            flags  |= AV_OPT_FLAG_SUBTITLE_PARAM;
            break;
    }

    while (t = av_dict_iterate(opts, t)) {
        const AVClass *priv_class;
        char *p = strchr(t->key, ':');

        /* check stream specification in opt name */
        if (p) {
            int err = check_stream_specifier(s, st, p + 1);
            if (err < 0) {
                av_dict_free(&ret);
                return err;
            } else if (!err)
                continue;

            *p = 0;
        }

        if (av_opt_find(&cc, t->key, NULL, flags, AV_OPT_SEARCH_FAKE_OBJ) ||
            !codec ||
            ((priv_class = codec->priv_class) &&
             av_opt_find(&priv_class, t->key, NULL, flags,
                         AV_OPT_SEARCH_FAKE_OBJ)))
            av_dict_set(&ret, t->key, t->value, 0);
        else if (t->key[0] == prefix &&
                 av_opt_find(&cc, t->key + 1, NULL, flags,
                             AV_OPT_SEARCH_FAKE_OBJ))
            av_dict_set(&ret, t->key + 1, t->value, 0);

        if (p)
            *p = ':';
    }

    *dst = ret;
    return 0;
}

int setup_find_stream_info_opts(AVFormatContext *s,
                                AVDictionary *codec_opts,
                                AVDictionary ***dst)
{
    int ret;
    AVDictionary **opts;

    *dst = NULL;

    if (!s->nb_streams)
        return 0;

    opts = av_calloc(s->nb_streams, sizeof(*opts));
    if (!opts)
        return AVERROR(ENOMEM);

    for (int i = 0; i < s->nb_streams; i++) {
        ret = filter_codec_opts(codec_opts, s->streams[i]->codecpar->codec_id,
                                s, s->streams[i], NULL, &opts[i]);
        if (ret < 0)
            goto fail;
    }
    *dst = opts;
    return 0;
    fail:
    for (int i = 0; i < s->nb_streams; i++)
        av_dict_free(&opts[i]);
    av_freep(&opts);
    return ret;
}

