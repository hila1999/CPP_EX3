CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I include -I /usr/local/include
SRC_FILES = Demo.cpp Tile.cpp structure.cpp Board.cpp city.cpp developmentCard.cpp player.cpp road.cpp settlement.cpp catan.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = catan

TEST_SRC_FILES = test_catan.cpp
TEST_OBJ_FILES = $(TEST_SRC_FILES:.cpp=.o)
TEST_EXECUTABLE = test_catan



test_catan: $(TEST_EXECUTABLE)
# catan: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(filter-out Demo.o, $(OBJ_FILES)) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@  -lgtest -lgtest_main -pthread

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_OBJ_FILES) $(TEST_EXECUTABLE)

tidy:
	clang-tidy $(SRC_FILES) -- -std=c++11 -I include

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)
