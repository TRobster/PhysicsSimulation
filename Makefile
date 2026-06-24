CXX      = g++
CC       = gcc
CXXFLAGS = -Iinclude
CFLAGS   = -Iinclude
LIBS     = -L/mingw64/lib -lglfw3 -lopengl32 -lgdi32 -luser32

TARGET = sim

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) src/main.cpp src/glad.c -o $(TARGET) $(LIBS) -Wl,-subsystem,console

clean:
	rm -f $(TARGET).exe