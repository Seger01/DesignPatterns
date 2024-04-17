MAKEFLAGS := --jobs=16

TARGET := executable

all: build_dir build

# Compiler
CXX := g++
SRC_EXTENSION := .cpp

# Directories
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := obj

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*$(SRC_EXTENSION))
HDR_FILES := $(wildcard $(INC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%$(SRC_EXTENSION),$(BUILD_DIR)/%.o,$(SRC_FILES))

INC_DIRS := $(addprefix -I,$(INC_DIR))

# Rule to create the build directory
build_dir:
	# rm -r $(BUILD_DIR)
	mkdir -p $(BUILD_DIR) 

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXTENSION) $(HDR_FILES) | build_dir
	$(CXX) $(INC_DIRS) -c $< -o $@

# Main target
build: $(OBJ_FILES) | build_dir
	$(CXX) -o $(TARGET) $(OBJ_FILES)

.PHONY: all clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
