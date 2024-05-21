# MAKEFLAGS := --jobs=16

TARGET := executable

all: $(TARGET)

# Compiler
CXX := g++
SRC_EXTENSION := .cpp

# Directories
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := obj


SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
HDR_FILES := $(shell find $(INC_DIR) -name '*.h')
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

INC_DIRS := $(addsuffix /,$(addprefix -I,$(shell find $(INC_DIR) -type d))) 

COMPILED_OBJS :=  $(foreach file,$(OBJ_FILES),obj/$(shell basename $(file)))

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp # $(HDR_FILES)
	$(CXX) $(CFLAGS) -g $(INC_DIRS) $(INCLUDE_PATHS) -c $< -o obj/$(shell basename $@)

# Main target
$(TARGET): $(OBJ_FILES)
	$(CXX)  -o $@ $(COMPILED_OBJS) -g  

.PHONY: all clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
