CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wpedantic #-fopenmp #-Werror

SRCDIR=src

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

EXEC = sym

LOGIN=xx

.PHONY: all release debug run debug-run clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(EXEC) $(ARGS)

debug-run: debug
	./$(EXEC) $(ARGS)

clean:
	rm -f $(EXEC) $(OBJS)
