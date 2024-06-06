# Define directories
INCLUDES = -Ivendor/GLFW/include -Ivendor/GLAD/include -Ivendor/GLM -Ivendor/STB_IMAGE
LIB_DIRS = -Lvendor/GLFW/lib -LC:\MinGW\lib
LIBS = -lglfw3 -lgdi32 -lopengl32

# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g -DDEBUG

# Define source files and target executable
SRC = vendor/GLAD/include/glad.cpp src/core/game.cpp src/main.cpp
TARGET = bin/main

# Define precompiled header
PCH_SRC = src/pch.h
PCH = src/pch.h.gch

# Default target
all: debug

# Debug target
debug: $(TARGET)

# Rule to create the precompiled header
$(PCH): $(PCH_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(PCH) -x c++-header $(PCH_SRC)

# Rule to compile the target executable
$(TARGET): $(PCH) $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIB_DIRS) $(LIBS) -include $(PCH_SRC)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(PCH)