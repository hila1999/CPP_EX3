CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I include
SRC_FILES = Demo.cpp Board.cpp city.cpp developmentCard.cpp player.cpp road.cpp settlement.cpp structure.cpp catan.cpp Tile.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = catan

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
