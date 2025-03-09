/*extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libswscale/swscale.h>
    #include <libavutil/imgutils.h>
}
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "cinematic.hpp"

void cine_pic(SDL_Renderer* renderer, const std::string& imagePath, int displayTimeMs) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, imagePath.c_str());
    if (!texture) {
        std::cerr << "Failed to load image: " << imagePath << "\n";
        return;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(displayTimeMs); // Keep the image on screen for the specified time

    SDL_DestroyTexture(texture);
}
/*
void cine_vid(SDL_Renderer* renderer, const std::string& videoPath) {
    av_register_all();

    AVFormatContext* formatContext = nullptr;
    if (avformat_open_input(&formatContext, videoPath.c_str(), nullptr, nullptr) != 0) {
        std::cerr << "Could not open video file: " << videoPath << "\n";
        return;
    }

    // Find video stream
    int videoStreamIndex = -1;
    for (unsigned int i = 0; i < formatContext->nb_streams; ++i) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }
    if (videoStreamIndex == -1) {
        std::cerr << "No video stream found in file: " << videoPath << "\n";
        avformat_close_input(&formatContext);
        return;
    }

    AVCodecParameters* codecParameters = formatContext->streams[videoStreamIndex]->codecpar;
    AVCodec* codec = avcodec_find_decoder(codecParameters->codec_id);
    if (!codec) {
        std::cerr << "Unsupported codec!\n";
        avformat_close_input(&formatContext);
        return;
    }

    AVCodecContext* codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, codecParameters);

    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        std::cerr << "Could not open codec.\n";
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return;
    }

    // Prepare SDL texture for video rendering
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING,
                                             codecContext->width, codecContext->height);

    SwsContext* swsContext = sws_getContext(codecContext->width, codecContext->height, codecContext->pix_fmt,
                                            codecContext->width, codecContext->height, AV_PIX_FMT_YUV420P,
                                            SWS_BILINEAR, nullptr, nullptr, nullptr);

    AVFrame* frame = av_frame_alloc();
    AVFrame* frameYUV = av_frame_alloc();
    uint8_t* buffer = (uint8_t*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_YUV420P, codecContext->width, codecContext->height, 1));
    av_image_fill_arrays(frameYUV->data, frameYUV->linesize, buffer, AV_PIX_FMT_YUV420P, codecContext->width, codecContext->height, 1);

    AVPacket packet;

    while (av_read_frame(formatContext, &packet) >= 0) {
        if (packet.stream_index == videoStreamIndex) {
            if (avcodec_send_packet(codecContext, &packet) == 0) {
                while (avcodec_receive_frame(codecContext, frame) == 0) {
                    sws_scale(swsContext, frame->data, frame->linesize, 0, codecContext->height,
                              frameYUV->data, frameYUV->linesize);

                    SDL_UpdateYUVTexture(texture, nullptr,
                                         frameYUV->data[0], frameYUV->linesize[0],
                                         frameYUV->data[1], frameYUV->linesize[1],
                                         frameYUV->data[2], frameYUV->linesize[2]);

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
                    SDL_RenderPresent(renderer);

                    SDL_Delay(1000 / 30); // Simulate 30 FPS
                }
            }
        }
        av_packet_unref(&packet);
    }

    // Cleanup
    av_free(buffer);
    av_frame_free(&frame);
    av_frame_free(&frameYUV);
    sws_freeContext(swsContext);
    SDL_DestroyTexture(texture);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);
}
*/