CXX      = g++
CC       = gcc
CXXFLAGS = -Iinclude
CFLAGS   = -Iinclude
LIBS     = -lglfw3 -lopengl32 -lgdi32 -luser32

TARGET = sim

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) src/main.cpp src/glad.c $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET).exe