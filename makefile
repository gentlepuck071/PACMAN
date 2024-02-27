# Compiler
CC := g++
# Compiler flags
CFLAGS := -std=c++11 -Wall
# SDL flags
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)

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
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $^ -o $@ $(SDL_LIBS)

# Rule to compile source files to object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target to avoid conflicts with file named 'all'
.PHONY: all clean

