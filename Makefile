CC = g++
CFLAGS = -Wall -std=c++20
DEBUG_FLAGS = -g -DDEBUG -w
RELEASE_FLAGS = -O2
DEPFLAGS = -MMD -MP

SRC_FILES = vendor/GLAD/include/glad.cpp \
            src/core/Log.cpp \
            src/core/Utils.cpp \
            src/core/OrthographicCamera.cpp \
            src/core/Input.cpp \
            src/core/content/Shader.cpp \
            src/core/content/Texture.cpp \
            src/core/render/IndexBuffer.cpp \
            src/core/render/VertexBuffer.cpp \
            src/core/render/VertexArray.cpp \
            src/core/render/Renderer.cpp \
            src/core/render/TextRenderer.cpp \
            src/core/GameWindow.cpp \
            src/core/Game.cpp \
            src/sandbox/TestGame.cpp \
            src/Program.cpp 

OBJ_FILES = $(SRC_FILES:.cpp=.o)
DEP_FILES = $(OBJ_FILES:.o=.d)

INCLUDE_PATHS = -Ivendor/GLFW/include \
                -Ivendor/GLAD/include \
                -Ivendor/GLM \
                -Ivendor/STB_IMAGE \
                -Ivendor/GLTEXT \
                -Ivendor/FREETYPE

LIBRARY_PATHS = -Lvendor/GLFW/lib

LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32 -llibfreetype

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
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -f $(OBJ_FILES) $(DEP_FILES) $(OBJ_NAME)_debug $(OBJ_NAME)_release

details: 
	$(info $(SHELL))



# CC = g++
# CFLAGS = -Wall
# DEBUG_FLAGS = -g -DDEBUG -w
# RELEASE_FLAGS = -O2

# SRC_FILES = vendor/GLAD/include/glad.cpp \
#             src/core/Utils.cpp \
#             src/core/Input.cpp \
#             src/core/content/Shader.cpp \
#             src/core/content/Texture.cpp \
#             src/core/render/IndexBuffer.cpp \
#             src/core/render/VertexBuffer.cpp \
#             src/core/render/VertexArray.cpp \
#             src/core/render/Renderer.cpp \
#             src/core/render/SpriteBatch.cpp \
#             src/core/GameWindow.cpp \
#             src/core/Game.cpp \
#             src/sandbox/TestGame.cpp \
#             src/Program.cpp 

# OBJ_FILES = $(SRC_FILES:.cpp=.o)

# INCLUDE_PATHS = -Ivendor/GLFW/include \
#                 -Ivendor/GLAD/include \
#                 -Ivendor/GLM \
#                 -Ivendor/STB_IMAGE

# LIBRARY_PATHS = -Lvendor/GLFW/lib

# LINKER_FLAGS = -lglfw3 -lgdi32 -lopengl32

# OBJ_NAME = bin/main

# all: debug release

# debug: CFLAGS += $(DEBUG_FLAGS)
# debug: $(OBJ_NAME)_debug

# release: CFLAGS += $(RELEASE_FLAGS)
# release: $(OBJ_NAME)_release

# $(OBJ_NAME)_debug: $(OBJ_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $@ $(LIBRARY_PATHS) $(LINKER_FLAGS)

# $(OBJ_NAME)_release: $(OBJ_FILES)
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) $^ -o $@ $(LIBRARY_PATHS) $(LINKER_FLAGS)

# # Pattern rule to compile .cpp files to .o files
# %.o: %.cpp
# 	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c $< -o $@

# clean:
# 	rm $(OBJ_FILES) $(OBJ_NAME)_debug $(OBJ_NAME)_release

# details: 
# 	$(info $(SHELL))
