# Compilers
CXX := g++
CC  := gcc

# Flags
CXXFLAGS := -Wall -Werror -std=c++23 -Iinclude
CFLAGS   := -Wall -Werror -std=c23 -Iinclude

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Executable name
TARGET := $(BIN_DIR)/spark-build

# Find all source files recursively
CPP_SRC := $(shell find $(SRC_DIR) -name '*.cpp')
C_SRC   := $(shell find $(SRC_DIR) -name '*.c')

# Convert src/.../*.cpp → obj/.../*.o
CPP_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_SRC))
C_OBJ   := $(patsubst $(SRC_DIR)/%.c,   $(OBJ_DIR)/%.o, $(C_SRC))

OBJ_FILES := $(CPP_OBJ) $(C_OBJ)

# Default rule
all: $(TARGET)

# Link object files into final binary
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Compile C++ sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile C sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
clean-all: clean
	rm -rf $(BIN_DIR)

# Build and run
run: all
	./$(TARGET)

# Build and debug
debug: all
	gdb ./$(TARGET)

# Build and run with valgrind
memcheck: all
	valgrind ./$(TARGET)