# Define which compiler to use
CXX    := g++
OUTPUT := sfmlgame

# if you need to specify SFML dir then notate here:
SFML_DIR  := .

# compiler linker flags
CXX_FLAGS  := -O3 -std=c++20 -Wno-unused-result
INCLUDES   := -I./src -I ./src/imgui -I$(SFML_DIR)/include
LDFLAGS    := -O3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -L$(SFML_DIR)/lib

# the source files for the ecs game 
SRC_FILES := $(wildcard src/*.cpp src/imgui/*.cpp) 
OBJ_FILES := $(SRC_FILES:.cpp=.o)

# all the targets will be made if you just type make
all:$(OUTPUT)

# define the main executable requirements
$(OUTPUT):$(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@

# specifies how the object files are compiled
.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES) ./bin/sfmlgame

run: $(OUTPUT)
	cd bin && ./sfmlgame && cd ..