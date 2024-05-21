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

# SRC_FILES := $(shell find $(SRC_DIR) -name "*"$(SRC_EXTENSION))
# HDR_FILES := $(shell find $(INC_DIR) -name '*.h')
# OBJ_FILES := $(patsubst $(SRC_DIR)/%$(SRC_EXTENSION),$(BUILD_DIR)/%.o,$(SRC_FILES))
#
# INC_DIRS := $(addprefix -I,$(INC_DIR))

# Rule to create the build directory
# build_dir:
# 	# rm -r $(BUILD_DIR)
# 	mkdir -p $(BUILD_DIR) 

# Rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp # $(HDR_FILES)
	$(CXX) $(CFLAGS) -g $(INC_DIRS) $(INCLUDE_PATHS) -c $< -o obj/$(shell basename $@)

# Main target
$(TARGET): $(OBJ_FILES)
	$(CXX)  -o $@ $(COMPILED_OBJS) -g  


# # Rule for object files
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXTENSION) $(HDR_FILES) | build_dir
# 	$(CXX) $(INC_DIRS) -c $< -o $@
#
# # Main target
# build: $(OBJ_FILES) | build_dir
# 	$(CXX) -o $(TARGET) $(OBJ_FILES)

.PHONY: all clean

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
