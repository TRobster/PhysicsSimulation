CXX      = g++
CC       = gcc
CXXFLAGS = -Iinclude
CFLAGS   = -Iinclude
LIBS     = -L/mingw64/lib -lglfw3 -lopengl32 -lgdi32 -luser32 -mwindows -Wl,--entry=mainCRTStartup

TARGET = sim

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) src/main.cpp src/glad.c -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET).exe