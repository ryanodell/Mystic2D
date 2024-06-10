# Define directories
INCLUDES = 	-Ivendor/GLFW/include \
			-Ivendor/GLAD/include \
			-Ivendor/GLM \
			-Ivendor/STB_IMAGE \
			-Ivendor/SPDLOG

LIB_DIRS = -Lvendor/GLFW/lib

LIBS = -lglfw3 -lgdi32 -lopengl32

# Define compiler and flags
DEFINES = 
CXX = g++
CXXFLAGS = -std=c++11 -g -DDEBUG -m64 $(DEFINES)

# Define source files and target executable
SRC = 	vendor/GLAD/include/glad.cpp \
		src/core/logger.cpp \
		src/core/render/buffer.cpp \
		src/core/render/renderer.cpp \
		src/core/render/spriteBatch.cpp \
		src/core/gameWindow.cpp \
		src/core/game.cpp \
		src/main.cpp 

OBJS = $(SRC:.cpp=.o)
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

# Rule to compile the object files with the precompiled header
%.o: %.cpp $(PCH)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -include src/pch.h -c $< -o $@

# Rule to link the target executable
$(TARGET): $(PCH) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_DIRS) $(LIBS)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS) $(PCH)



# # Define directories
# INCLUDES = -Ivendor/GLFW/include -Ivendor/GLAD/include -Ivendor/GLM -Ivendor/STB_IMAGE -Ivendor/SPDLOG #-IC:\MinGW-64\include
# # LIB_DIRS = -Lvendor/GLFW/lib -LC:\MinGW\lib
# LIB_DIRS = -Lvendor/GLFW/lib -LC:\MinGW-64\lib

# LIBS = -lglfw3 -lgdi32 -lopengl32

# # Define compiler and flags
# DEFINES = #-D_M_IX86
# CXX = g++
# #CXX = x86_64-w64-mingw32-g++
# #CXX = x86_64-w64-mingw32-g++
# # CXXFLAGS = -Wall -std=c++11 -g -DDEBUG
# CXXFLAGS = -std=c++11 -g -DDEBUG $(DEFINES)

# # Define source files and target executable
# SRC = vendor/GLAD/include/glad.cpp src/core/game.cpp src/main.cpp
# TARGET = bin/main

# # Define precompiled header
# PCH_SRC = src/pch.h
# PCH = src/pch.h.gch
# # PCH_SRC = src/pch.h
# # PCH = src/pch.h


# # Default target
# all: debug

# # Debug target
# debug: $(TARGET)

# pch: $(PCH)

# # Rule to create the precompiled header
# $(PCH): $(PCH_SRC)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(PCH) -x c++-header $(PCH_SRC) -v

# # Rule to compile the target executable
# # $(TARGET): $(PCH) $(SRC)
# $(TARGET): -include $(PCH_SRC) $(SRC)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIB_DIRS) $(LIBS) -v
# # $(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIB_DIRS) $(LIBS) -include $(PCH_SRC)

# # Clean rule to remove generated files
# clean:
# 	rm -f $(TARGET) $(PCH)