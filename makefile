# Compiler
CC := g++
# Compiler flags
CFLAGS := -std=c++11 -Wall
# SDL flags
SDL_CFLAGS := $(shell pkg-config --cflags sdl2)
SDL_LIBS := $(shell pkg-config --libs sdl2)
# SDL2_image flags
SDL_IMAGE_CFLAGS := $(shell pkg-config --cflags SDL2_image)
SDL_IMAGE_LIBS := $(shell pkg-config --libs SDL2_image)

# Directories
SRC_DIR := src
BIN_DIR := bin

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Target binary
TARGET := $(BIN_DIR)/pacman.out

# Default target
all: $(TARGET)

# Rule to make the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(SDL_IMAGE_CFLAGS) $^ -o $@ $(SDL_LIBS) $(SDL_IMAGE_LIBS)

# Rule to compile source files to object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(SDL_IMAGE_CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target to avoid conflicts with file named 'all'
.PHONY: all clean

