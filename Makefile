# Define directories
INCLUDES =  -Ivendor/GLFW/include \
            -Ivendor/GLAD/include \
            -Ivendor/GLM \
            -Ivendor/STB_IMAGE

LIB_DIRS = 	-Lvendor/GLFW/lib \
			-Lvendor/SPDLOG/lib

LIBS = -lglfw3 -lgdi32 -lopengl32

# Define compiler and flags
DEFINES = 
CXX = ccache g++
CXXFLAGS = -std=c++11 -g -DDEBUG -m64 -mconsole $(DEFINES) -flto
LDFLAGS = -mconsole -flto

# Define source files and target executable
SRC =   vendor/GLAD/include/glad.cpp \
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
	$(CXX) $(LDFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_DIRS) $(LIBS)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS) $(PCH)

# Include the .d files for dependency tracking
-include $(OBJS:.o=.d)

# Generate .d files for dependency tracking
%.d: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -M $< > $@



# CC = g++
# CFLAGS = -Wall -std=c++11
# DEBUG_FLAGS = -g -DDEBUG
# RELEASE_FLAGS = -O2

# SRC_FILES = src/main.cpp
# DEPS = 

# INCLUDE_PATHS = -Ivendor/GLFW/include \
#                 -Ivendor/GLAD/include \
#                 -Ivendor/GLM \
#                 -Ivendor/STB_IMAGE

# LIBRARY_PATHS = -Lvendor/GLFW/lib

# LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

# all: debug release

# debug: CFLAGS += $(DEBUG_FLAGS)
# debug: build

# release: CFLAGS += $(RELEASE_FLAGS)
# release: build

# OBJ_NAME = bin\main

# build: $(SRC_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS)

# clean:
# 	rm -f bin\main.exe

# Dependencies
# $(SRC_FILES): $(DEPS)


# Define directories
# INCLUDES =  -Ivendor/GLFW/include \
#             -Ivendor/GLAD/include \
#             -Ivendor/GLM \
#             -Ivendor/STB_IMAGE \
#             -Ivendor/SPDLOG

# LIB_DIRS = -Lvendor/GLFW/lib

# LIBS = -lglfw3 -lgdi32 -lopengl32

# # Define compiler and flags
# DEFINES = 
# CXX = g++
# CXXFLAGS = -std=c++11 -g -DDEBUG -m64 -mconsole -Wl,--incremental $(DEFINES)
# LDFLAGS = -mconsole

# # Define source files and target executable
# SRC =   vendor/GLAD/include/glad.cpp \
#         src/core/logger.cpp \
#         src/core/render/buffer.cpp \
#         src/core/render/renderer.cpp \
#         src/core/render/spriteBatch.cpp \
#         src/core/gameWindow.cpp \
#         src/core/game.cpp \
#         src/main.cpp 

# OBJS = $(SRC:.cpp=.o)
# TARGET = bin/main

# # Define precompiled header
# PCH_SRC = src/pch.h
# PCH = src/pch.h.gch

# # Default target
# all: debug

# # Debug target
# debug: $(TARGET)

# # Rule to create the precompiled header
# $(PCH): $(PCH_SRC)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(PCH) -x c++-header $(PCH_SRC)

# # Rule to compile the object files with the precompiled header
# %.o: %.cpp $(PCH)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -include src/pch.h -c $< -o $@

# # Rule to link the target executable
# $(TARGET): $(PCH) $(OBJS)
# 	$(CXX) $(LDFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_DIRS) $(LIBS)

# # Clean rule to remove generated files
# clean:
# 	rm -f $(TARGET) $(OBJS) $(PCH)

# # Include the .d files for dependency tracking
# -include $(OBJS:.o=.d)

# # Generate .d files for dependency tracking
# %.d: %.cpp
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -M $< > $@



#original:
# Define directories
# INCLUDES = 	-Ivendor/GLFW/include \
# 			-Ivendor/GLAD/include \
# 			-Ivendor/GLM \
# 			-Ivendor/STB_IMAGE \
# 			-Ivendor/SPDLOG

# LIB_DIRS = -Lvendor/GLFW/lib

# LIBS = -lglfw3 -lgdi32 -lopengl32

# # Define compiler and flags
# DEFINES = 
# CXX = g++
# CXXFLAGS = -std=c++11 -g -DDEBUG -m64 -mconsole $(DEFINES)

# # Define source files and target executable
# SRC = 	vendor/GLAD/include/glad.cpp \
# 		src/core/logger.cpp \
# 		src/core/render/buffer.cpp \
# 		src/core/render/renderer.cpp \
# 		src/core/render/spriteBatch.cpp \
# 		src/core/gameWindow.cpp \
# 		src/core/game.cpp \
# 		src/main.cpp 

# OBJS = $(SRC:.cpp=.o)
# TARGET = bin/main

# # Define precompiled header
# PCH_SRC = src/pch.h
# PCH = src/pch.h.gch

# # Default target
# all: debug

# # Debug target
# debug: $(TARGET)

# # Rule to create the precompiled header
# $(PCH): $(PCH_SRC)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(PCH) -x c++-header $(PCH_SRC)

# # Rule to compile the object files with the precompiled header
# %.o: %.cpp $(PCH)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -include src/pch.h -c $< -o $@

# # Rule to link the target executable
# $(TARGET): $(PCH) $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_DIRS) $(LIBS)

# # Clean rule to remove generated files
# clean:
# 	rm -f $(TARGET) $(OBJS) $(PCH)
