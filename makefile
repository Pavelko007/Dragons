# This is the makefile for CSE1CPP Assignment 1 2014 

LIBS = -g -Wall -std=c++11 
CC = g++4.7 
LDFLAGS = -rdynamic -static-libstdc++ -static-libgcc 

# To use this makefile type
#
# make all
#
# at your latcs6 command prompt
#
# when everything compiles successfully, to run the progam, type
#
# dop
#
# at your latcs6 command prompt
#
# Note that this makefile is designed to run only on Unix/Linux
# OS
#
# It can be adapted for use with Windows C++ IDE's such as
# WxDev-C++, CodeBlocks and others.
#
# if you use the toolkit.h and toolkit.cpp files add them into the
# first lines of the makefile, for example, toolkit.o
#
# Then add a compilation target below pernThread.o: pernThread.cpp
#                                     	$(CC) $(LIBS) -c pernThread.cpp
#
# DO NOT remove the -lm from the end of the third line, this is required
# to correctly compile functions from the <cmath> header


dop: dragon.o util.o pernThread.o driver.o
	$(CC) $(LDFLAGS) $(LIBS) -o dop dragon.o util.o driver.o  \
	                                pernThread.o -lm 

dragon.o: dragon.cpp
	$(CC) $(LIBS) -c dragon.cpp

driver.o: driver.cpp
	$(CC) $(LIBS) -c driver.cpp

util.o: util.cpp
	$(CC) $(LIBS) -c util.cpp

pernThread.o: pernThread.cpp
	$(CC) $(LIBS) -c pernThread.cpp

all: dop clean

clean: 
	rm *.o
