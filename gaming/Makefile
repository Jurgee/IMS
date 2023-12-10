CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wpedantic #-fopenmp #-Werror

# Directories
SRC_DIR = src
TMP_DIR = tmp
BIN_DIR = .

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(TMP_DIR)/%.o,$(SRC_FILES))
TARGET = simulation


# Targets
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $^

$(TMP_DIR)/%.o: $(SRC_DIR)/%.cpp | $(TMP_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TMP_DIR):
	mkdir -p $@


clean:
	rm -rf $(TMP_DIR) $(TARGET)


.PHONY: all clean
