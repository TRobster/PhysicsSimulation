CXX      = g++
CC       = gcc
CXXFLAGS = -Iinclude
CFLAGS   = -Iinclude
LIBS     = /mingw64/lib/libglfw3.dll.a -lopengl32 -lgdi32 -luser32

TARGET = sim

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) src/main.cpp src/glad.c -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET).exe