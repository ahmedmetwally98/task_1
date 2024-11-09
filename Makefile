# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

# Directories
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Output executable
TARGET = $(BIN_DIR)/task1App

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Ensure the bin directory exists
$(shell mkdir -p $(BIN_DIR))

# Rule to build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove built files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: clean
