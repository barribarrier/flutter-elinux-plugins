// Copyright 2021 Sony Group Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PACKAGES_VIDEO_PLAYER_VIDEO_PLAYER_ELINUX_VIDEO_PLAYER_STREAM_HANDLER_H_
#define PACKAGES_VIDEO_PLAYER_VIDEO_PLAYER_ELINUX_VIDEO_PLAYER_STREAM_HANDLER_H_

class VideoPlayerStreamHandler {
 public:
  VideoPlayerStreamHandler() = default;
  virtual ~VideoPlayerStreamHandler() = default;

  // Prevent copying.
  VideoPlayerStreamHandler(VideoPlayerStreamHandler const&) = delete;
  VideoPlayerStreamHandler& operator=(VideoPlayerStreamHandler const&) = delete;

  // Notifies the completion of initializing the video player.
  void OnNotifyInitialized() { OnNotifyInitializedInternal(); }

  // Notifies an error occurred during initializing the video player or an error
  // occurred during playback.
  void OnNotifyError(const std::string& code,
                     const std::string& message = std::string(),
                     const std::string& details = std::string()) {
    OnNotifyErrorInternal(code, message, details);
  }

  // Notifies the completion of decoding a video frame.
  void OnNotifyFrameDecoded() { OnNotifyFrameDecodedInternal(); }

  // Notifies the completion of playing a video.
  void OnNotifyCompleted() { OnNotifyCompletedInternal(); }

  // Notifies update of playing or pausing a video.
  void OnNotifyPlaying(bool is_playing) { OnNotifyPlayingInternal(is_playing); }

 protected:
  virtual void OnNotifyInitializedInternal() = 0;
  virtual void OnNotifyErrorInternal(const std::string& code,
                                     const std::string& message,
                                     const std::string& details) = 0;
  virtual void OnNotifyFrameDecodedInternal() = 0;
  virtual void OnNotifyCompletedInternal() = 0;
  virtual void OnNotifyPlayingInternal(bool is_playing) = 0;
};

#endif  // PACKAGES_VIDEO_PLAYER_VIDEO_PLAYER_ELINUX_VIDEO_PLAYER_STREAM_HANDLER_H_
