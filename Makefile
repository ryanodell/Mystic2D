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

all: debug release

debug: CFLAGS += $(DEBUG_FLAGS)
debug: build

release: CFLAGS += $(RELEASE_FLAGS)
release: build

OBJ_NAME = bin\main

build: $(SRC_FILES)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $(OBJ_NAME) $(LIBRARY_PATHS) $(LINKER_FLAGS)

clean:
	rm -f bin\main.exe

# Dependencies
$(SRC_FILES): $(DEPS)


#original
# # OBJS specifies which files to compile as part of the project
# OBJS = src\main.cpp

# # DEPS specifies the header files
# DEPS = src\backend.h src\core\logger.h src\core\ecs.h src\core\macros.h src\math\vecs.h src\systems.h src\core\event.h src\pch.h

# # CC specifies which compiler we're using
# CC = g++

# # INCLUDE_PATHS specifies the additional include paths we'll need
# INCLUDE_PATHS = -IC:\ExternalLibs\SDL2-2.29.3\i686-w64-mingw32\include\SDL2 \
#                 -IC:\ExternalLibs\SDL2_image\SDL2_image-2.8.2\i686-w64-mingw32\include\SDL2 \
#                 -IC:\ExternalLibs\SDL2_ttf\SDL2_ttf-2.22.0\i686-w64-mingw32\include\SDL2

# # LIBRARY_PATHS specifies the additional library paths we'll need
# LIBRARY_PATHS = -LC:\ExternalLibs\SDL2-2.29.3\i686-w64-mingw32\lib \
#                 -LC:\ExternalLibs\SDL2_image\SDL2_image-2.8.2\i686-w64-mingw32\lib \
#                 -LC:\ExternalLibs\SDL2_ttf\SDL2_ttf-2.22.0\i686-w64-mingw32\lib

# # COMPILER_FLAGS specifies the additional compilation options we're using
# # -w suppresses all warnings
# # -g enables debugging information
# COMPILER_FLAGS = -w -g

# # LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

# # OBJ_NAME specifies the name of our executable
# OBJ_NAME = bin\main

# # This is the target that compiles our executable
# all: $(OBJS)
# 	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# # Dependencies
# $(OBJS): $(DEPS)

