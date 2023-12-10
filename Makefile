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

run: $(TARGET)
	./$(TARGET) -i 4000 -c 60 -r 4000 -v 38 -a 4 -l 3 -s 10 -d 1

clean:
	rm -rf $(TMP_DIR) $(TARGET)


.PHONY: all clean
