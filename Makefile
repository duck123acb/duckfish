# Compiler and settings
CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Iinclude -I$(HOME)/raylib/src -g

# Raylib and macOS frameworks
LDFLAGS := -L$(HOME)/raylib/src -lraylib \
           -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# File organization
SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/main

# All .cpp files in src/
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)
	@echo "✅ Build complete: $@"

# Compile each .cpp → .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	@./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
	@echo "🧹 Cleaned build directory."

.PHONY: all run clean
