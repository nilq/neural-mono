MONO_PATH=/usr/lib/openmono
include $(MONO_PATH)/predefines.mk

TARGET=pong

OBJECTS = \
	$(patsubst %.cpp,%.o,$(wildcard lib/*.cpp)) \
	$(patsubst %.cpp,%.o,$(wildcard *.cpp))

include $(MONO_PATH)/mono.mk