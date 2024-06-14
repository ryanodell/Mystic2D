CC = g++
CFLAGS = -Wall
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2

SRC_FILES = vendor/GLAD/include/glad.cpp \
            src/core/render/Buffer.cpp \
            src/core/render/Renderer.cpp \
            src/core/render/SpriteBatch.cpp \
            src/core/GameWindow.cpp \
            src/core/Game.cpp \
            src/sandbox/TestGame.cpp \
            src/Program.cpp 

OBJ_FILES = $(SRC_FILES:.cpp=.o)

INCLUDE_PATHS = -Ivendor/GLFW/include \
                -Ivendor/GLAD/include \
                -Ivendor/GLM \
                -Ivendor/STB_IMAGE

LIBRARY_PATHS = -Lvendor/GLFW/lib

LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

OBJ_NAME = bin/main

all: debug release

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(OBJ_NAME)_debug

release: CFLAGS += $(RELEASE_FLAGS)
release: $(OBJ_NAME)_release

$(OBJ_NAME)_debug: $(OBJ_FILES)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $@ $(LIBRARY_PATHS) $(LINKER_FLAGS)

$(OBJ_NAME)_release: $(OBJ_FILES)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $@ $(LIBRARY_PATHS) $(LINKER_FLAGS)

# Pattern rule to compile .cpp files to .o files
%.o: %.cpp
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ_FILES) $(OBJ_NAME)_debug $(OBJ_NAME)_release
#rm -f $(OBJ_FILES) $(OBJ_NAME)_debug $(OBJ_NAME)_release

details: 
	$(info $(SHELL))

# CC = g++
# CFLAGS = -Wall
# DEBUG_FLAGS = -g -DDEBUG
# RELEASE_FLAGS = -O2

# SRC_FILES =     vendor/GLAD/include/glad.cpp \
# 		src/core/render/buffer.cpp \
# 		src/core/render/renderer.cpp \
# 		src/core/render/spriteBatch.cpp \
# 		src/core/gameWindow.cpp \
# 		src/core/game.cpp \
# 		src/main.cpp 

# DEPS =          vendor/GLAD/include/glad.h \
# 		src/core/render/buffer.h \
# 		src/core/render/renderer.h \
# 		src/core/render/spriteBatch.h \
# 		src/core/gameWindow.h \
# 		src/core/gametime.h \
# 		src/core/game.h

# INCLUDE_PATHS = -Ivendor/GLFW/include \
# 		-Ivendor/GLAD/include \
# 		-Ivendor/GLMC/cglm \
# 		-Ivendor/STB_IMAGE

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

# clean: rm bin/main


# # Dependencies
# $(SRC_FILES): $(DEPS)


# Define directories
# INCLUDES =  -Ivendor/GLFW/include \
#             -Ivendor/GLAD/include \
#             -Ivendor/GLM \
#             -Ivendor/STB_IMAGE

# LIB_DIRS = 	-Lvendor/GLFW/lib

# LIBS = -lglfw3 -lgdi32 -lopengl32

# # Define compiler and flags
# DEFINES = 
# CXX = g++
# CXXFLAGS = -std=c++11 -g -mconsole -m64 $(DEFINES) -flto
# LDFLAGS = -mconsole -flto

# # Define source files and target executable
# SRC =   vendor/GLAD/include/glad.cpp \
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
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -o

# # Rule to compile the object files with the precompiled header
# %.o: %.cpp $(PCH)
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -include src/pch.h -c $< -o $@

# # Rule to link the target executable
# $(TARGET): $(PCH) $(OBJS)
# 	$(CXX) $(LDFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_DIRS) $(LIBS)

# # Clean rule to remove generated files
# clean:
# 	rm -f $(TARGET) $(OBJS)

# # Include the .d files for dependency tracking
# -include $(OBJS:.o=.d)

# # Generate .d files for dependency tracking
# %.d: %.cpp
# 	$(CXX) $(CXXFLAGS) $(INCLUDES) -M $< > $@



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
