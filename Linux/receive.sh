#!/bin/bash
gst-launch-1.0 -v udpsrc port=5000 ! application/x-rtp, media=video, clock-rate=90000, encoding-name=YUY2, payload=96 ! rtph264depay ! decodebin ! videoconvert ! fpsdisplaysink video-sink=autovideosink sync=0 silent=true
