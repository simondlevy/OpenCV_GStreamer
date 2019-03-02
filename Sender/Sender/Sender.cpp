/*
* Sender.cpp: Sender for OpenCV_GStreamer example
*
* Copyright (C) 2019 Simon D. Levy
*
* MIT License
*/

#ifdef _WIN32
#include "pch.h"
#endif

#include <opencv2/opencv.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main()
{
    VideoCapture cap(0);
	
    VideoWriter out("appsrc ! videoconvert ! video/x-raw,format=YUY2,width=640,height=480,framerate=30/1 ! jpegenc ! rtpjpegpay ! udpsink host=127.0.0.1 port=5000",CAP_GSTREAMER,0,30,Size(640,480),true);

	
    if (!cap.isOpened() | !out.isOpened()) {
        cerr <<"VideoCapture or VideoWriter not opened"<<endl;
        exit(-1);
    }

    while (true) {

        Mat frame;

        cap.read(frame);

        out.write(frame);

        imshow("sender", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}


