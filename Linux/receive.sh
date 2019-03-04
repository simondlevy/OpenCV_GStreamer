gst-launch-1.0 -v udpsrc port=5000 ! application/x-rtp,media=video,payload=26,clock-rate=90000,encoding-name=JPEG,framerate=30/1 ! rtpjpegdepay ! jpegdec ! videoconvert ! fpsdisplaysink video-sink=autovideosink sync=0 silent=true

