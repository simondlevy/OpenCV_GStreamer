#
# Makefile for Linux version of OpenCV_GStreamer project
#
# Copyright (C) 2019 Simon D. Levy
# 
# MIT License
# 

CFLAGS = -Wall -std=c++11

ALL = Sender Receiver

all: $(ALL)

Sender: Sender.o 
	g++ -o Sender Sender.o -L/usr/local/lib \
          -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui

Sender.o: ../Sender/Sender/Sender.cpp
	g++ $(CFLAGS) -c ../Sender/Sender/Sender.cpp

send: Sender
	./Sender

Receiver: Receiver.o
	g++ -o Receiver Receiver.o -L/usr/local/lib \
          -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui

Receiver.o: Receiver.cpp
	g++ -c -std=c++11 -I/usr/local/include/opencv4 Receiver.cpp

receive: Receiver
	./Receiver 

clean:
	rm -rf $(ALL) *.o *~
