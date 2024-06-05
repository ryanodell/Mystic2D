#experimenting still :(
# CC = g++
# CFLAGS = -Wall -std=c++11
# DEBUG_FLAGS = -g -DDEBUG
# RELEASE_FLAGS = -O2

# SRC_FILES = src/main.cpp vendor/GLAD/include/glad.cpp
# DEPS = src/pch.h $(wildcard src/*.h)

# INCLUDE_PATHS = -Ivendor/GLFW/include \
#                 -Ivendor/GLAD/include \
#                 -Ivendor/GLM \
#                 -Ivendor/STB_IMAGE

# LIBRARY_PATHS = -Lvendor/GLFW/lib \
#                 -LC:\MinGW\lib

# LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

# PCH_FILE = src/pch.h
# PCH_GCH = $(PCH_FILE).gch

# OBJ_NAME = bin\main

# .PHONY: all debug release clean pch build_no_pch

# all: debug release

# debug: CFLAGS += $(DEBUG_FLAGS)
# debug: build

# release: CFLAGS += $(RELEASE_FLAGS)
# release: build

# pch: $(PCH_GCH)

# $(PCH_GCH): $(PCH_FILE)
# 	$(CC) $(CFLAGS) $(INCLUDE_PATHS) -x c++-header $(PCH_FILE) -o $(PCH_GCH)

# build: $(PCH_GCH) $(SRC_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $(SRC_FILES) $(PCH_GCH) -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS)

# build_no_pch: $(SRC_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $(SRC_FILES) -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS)

# clean:
# 	rm -f $(PCH_GCH) bin\main.exe

# # Dependencies
# $(SRC_FILES): $(DEPS)





# CC = g++
# CFLAGS = -Wall -std=c++11 -H
# DEBUG_FLAGS = -g -DDEBUG
# RELEASE_FLAGS = -O2

# SRC_FILES = src/main.cpp vendor/GLAD/include/glad.cpp
# DEPS = src/pch.h $(wildcard src/*.h)

# INCLUDE_PATHS = -Ivendor/GLFW/include \
#                 -Ivendor/GLAD/include \
#                 -Ivendor/GLM \
#                 -Ivendor/STB_IMAGE

# LIBRARY_PATHS = -Lvendor/GLFW/lib \
#                 -LC:\MinGW\lib

# LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

# PCH_FILE = src/pch.h
# PCH_GCH = $(PCH_FILE).gch

# OBJ_NAME = bin\main

# .PHONY: all debug release clean pch

# all: debug release

# debug: CFLAGS += $(DEBUG_FLAGS)
# debug: build

# release: CFLAGS += $(RELEASE_FLAGS)
# release: build

# pch: $(PCH_GCH)

# $(PCH_GCH): $(PCH_FILE)
# 	$(CC) $(CFLAGS) -x c++-header $(PCH_FILE) -o $(PCH_GCH)

# build: $(SRC_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $(SRC_FILES) -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS)

# clean:
# 	rm -f $(PCH_GCH) bin\main.exe

# # Dependencies
# $(SRC_FILES): $(DEPS)

#!IMPORTANT! Run this manually first: g++ -std=c++11 src/pch.h -H
CC = g++
CFLAGS = -Wall -std=c++11
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2

SRC_FILES = src/main.cpp vendor/GLAD/include/glad.cpp
DEPS = 

INCLUDE_PATHS = -Ivendor/GLFW/include \
                -Ivendor/GLAD/include \
                -Ivendor/GLM \
                -Ivendor/STB_IMAGE

LIBRARY_PATHS = -Lvendor/GLFW/lib \
                -LC:\MinGW\lib

LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

pch: g++ -x c++-header -o src/pch.cpp src/pch.h

all: debug release

debug: CFLAGS += $(DEBUG_FLAGS)
debug: build

release: CFLAGS += $(RELEASE_FLAGS)
release: build

OBJ_NAME = bin\main

build: $(SRC_FILES)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS) -H

clean:
	rm -f bin\main.exe

# Dependencies
$(SRC_FILES): $(DEPS)