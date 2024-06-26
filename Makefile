MAKEFLAGS := --jobs=16

TARGET := executable

all: $(TARGET)

# Compiler
CXX := g++
SRC_EXTENSION := .cpp
HEAD_EXTENSION := .h
HPP_EXTENSION := .hpp
OBJ_EXTENSION := .o

# Directories
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := obj

# Source and Header Files
SRC_FILES := $(shell find $(SRC_DIR) -name '*$(SRC_EXTENSION)')
HDR_FILES := $(shell find $(INC_DIR) -name '*$(HEAD_EXTENSION)')
HPP_FILES := $(shell find $(INC_DIR) -name '*$(HPP_EXTENSION)')
OBJ_FILES := $(patsubst $(SRC_DIR)/%$(SRC_EXTENSION),$(BUILD_DIR)/%$(OBJ_EXTENSION),$(SRC_FILES))

INC_DIRS := $(addsuffix /,$(addprefix -I,$(shell find $(INC_DIR) -type d))) 

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXTENSION)
	@mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -g $(INC_DIRS) $(INCLUDE_PATHS) -c $< -o $@

# Main target
$(TARGET): $(OBJ_FILES)
	$(CXX)  -o $@ $(OBJ_FILES) -g  

.PHONY: all clean

clean: doxygen_clean
	rm -rf $(BUILD_DIR) $(TARGET)

doxygen_clean: 
	rm -rf doc/*

doxygen: doxygen_clean
	doxygen
