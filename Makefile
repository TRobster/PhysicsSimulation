CXX      = g++
CC       = gcc
CXXFLAGS = -Iinclude $(shell pkg-config --cflags glfw3)
CFLAGS   = -Iinclude
LIBS     = $(shell pkg-config --libs glfw3) -lopengl32 -lgdi32 -luser32

TARGET = sim

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) src/main.cpp src/glad.c -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET).exe