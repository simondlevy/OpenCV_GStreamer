/*
* Sender.cpp: Sender for OpenCV_GStreamer example
*
* Copyright (C) 2019 Simon D. Levy
*
* MIT License
*/

#include "pch.h"

#include <opencv2/opencv.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main()
{
    VideoCapture cap(0);
	
    if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }

    VideoWriter writer("appsrc ! videoconvert ! x264enc noise-reduction=10000 tune=zerolatency byte-stream=true bitrate=3000 threads=2 ! h264parse config-interval=1 ! rtph264pay ! udpsink host=127.0.0.1 port=5000", 
		0, (double)30, cv::Size(640, 480), true);

	
    if (!writer.isOpened()) {
        cerr <<"VideoWriter not opened"<<endl;
        exit(-1);
    }

    while (true) {

        Mat frame;

        cap.read(frame);

        writer.write(frame);

        imshow("sender", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}


