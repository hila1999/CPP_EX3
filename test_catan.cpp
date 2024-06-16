//hila.shamir99@gmail.com
//314906983
#include "gtest/gtest.h"
#include "catan.hpp"
#include "player.hpp"
#include "Board.hpp"
 using namespace ariel;
// Test Player Initialization
TEST(PlayerTest, Initialization) {
    Player p1("Amit");
    EXPECT_EQ(p1.getName(), "Amit");
    EXPECT_EQ(p1.getVictoryPoints(), 2);
    
}

// Test Adding and Retrieving Resources
TEST(PlayerTest, ResourceManagement) {
    Player p1("Amit");
    p1.addResources("wood", 3);
    EXPECT_EQ(p1.getResources("wood"), 3);
    p1.addResources("brick", 2);
    EXPECT_EQ(p1.getResources("brick"), 2);
}

// Test Structure Placement on Board
TEST(BoardTest, PlaceStructure) { //
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    Structure* s1 = new Settlement(&p1);
    Structure* s2 = new Settlement(&p1);
    EXPECT_NO_THROW(board.placeStructure(*s1, 21)); // Ensure no exception is thrown
    EXPECT_THROW(board.placeStructure(*s1, 21), std::invalid_argument); // Placing on the same spot should throw
    delete s1;
    delete s2;
}

// Test Road Placement on Board
TEST(BoardTest, PlaceRoad) {
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    Structure* s1 = new Settlement(&p1);
    board.placeStructure(*s1, 21);
    Structure* r1 = new Road(&p1);
    EXPECT_NO_THROW(board.placeRoad(*r1, 25)); // Ensure no exception is thrown
    EXPECT_THROW(board.placeRoad(*r1, 25), std::invalid_argument); // Placing on the same spot should throw
    delete r1;
}

// Test Dice Roll and Resource Distribution
TEST(GameMechanicsTest, RollDice) {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();
    board.addPlayer(p1);
    board.addPlayer(p2);
    board.addPlayer(p3);
    Structure* s1 = new Settlement(&p1);
    Structure* s2 = new Settlement(&p2);
    board.placeStructure(*s1, 21);
    board.placeStructure(*s2, 22);
    p1.addResources("wood", 3);
    catan.getCurrentPlayer().setTurn(true);
    catan.getCurrentPlayer().rollDice(board);
    
    // Add assertions based on the dice roll outcome and resource distribution logic
    delete s1;
    delete s2;
}

// Test Upgrading Settlement to City
TEST(GameMechanicsTest, UpgradeToCity) {
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    Structure* s1 = new Settlement(&p1);
    board.placeStructure(*s1, 21);
    p1.addResources("ore", 3);
    p1.addResources("wheat", 2);
    EXPECT_NO_THROW(s1=p1.upgradeToCity(board, 21)); // Ensure no exception is thrown
    EXPECT_EQ(p1.getVictoryPoints(), 3); // Assume upgrading to a city gives 2 victory points
    delete s1;
}
TEST(GameMechanicsTest, Trade) {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    Board& board = catan.getBoard();
    board.addPlayer(p1);
    board.addPlayer(p2);
    board.addPlayer(p3);
    p1.addResources("wood", 3);
    p2.addResources("ore", 3);
    p1.trade(p2, "wood", "ore", 1, 1);
    EXPECT_EQ(p1.getResources("wood"), 2);
    EXPECT_EQ(p2.getResources("wood"), 1);
    EXPECT_EQ(p1.getResources("ore"), 1);
    EXPECT_EQ(p2.getResources("ore"), 2);
}

TEST(GameMechanicsTest, BuyDevelopmentCard) {
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    p1.addResources("ore", 1);
    p1.addResources("wheat", 1);
    p1.addResources("wool", 1);
    p1.buyDevelopmentCard(board);
    EXPECT_EQ(p1.getResources("ore"), 0);
    EXPECT_EQ(p1.getResources("wheat"), 0);
    EXPECT_EQ(p1.getResources("wool"), 0);
    EXPECT_EQ(p1.getNumOfKnights(), 0);
}



TEST(GameMechanicsTest, PlaceRoad) {
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    p1.addResources("wood", 1);
    p1.addResources("brick", 1);
    p1.placeRoad(25, board);
    EXPECT_EQ(p1.getRoads().size(), 1);
    EXPECT_EQ(p1.getResources("wood"), 0);
    EXPECT_EQ(p1.getResources("brick"), 0);
}

TEST(GameMechanicsTest, PlaceSettlement) {
    Player p1("Amit");
    Board board;
    board.addPlayer(p1);
    p1.addResources("wood", 1);
    p1.addResources("brick", 1);
    p1.addResources("wheat", 1);
    p1.addResources("wool", 1);
    p1.placeSettlement(21, board);
    EXPECT_EQ(p1.getSettlements().size(), 1);
    EXPECT_EQ(p1.getResources("wood"), 0);
    EXPECT_EQ(p1.getResources("brick"), 0);
    EXPECT_EQ(p1.getResources("wheat"), 0);
    EXPECT_EQ(p1.getResources("wool"), 0);
}

TEST(GameMechanicsTest, RemoveAllResources) {
    Player p1("Amit");
    p1.addResources("wood", 3);
    p1.addResources("brick", 2);
    p1.addResources("wheat", 1);
    p1.addResources("wool", 1);
    EXPECT_EQ(p1.removeAllResources("wood"), 3);
    EXPECT_EQ(p1.removeAllResources("brick"), 2);
    EXPECT_EQ(p1.removeAllResources("wheat"), 1);
    EXPECT_EQ(p1.removeAllResources("wool"), 1);
}

TEST(GameMechanicsTest, AddVictoryPoints) {
    Player p1("Amit");
    p1.addVictoryPoints(2);
    EXPECT_EQ(p1.getVictoryPoints(), 4);
}

TEST(GameMechanicsTest, AddKnight) {
    Player p1("Amit");
    p1.addKnight();
    EXPECT_EQ(p1.getNumOfKnights(), 1);
}

TEST(GameMechanicsTest, SetTurn) {
    Player p1("Amit");
    p1.setTurn(true);
    EXPECT_TRUE(p1.isTurnPlayer());
}

TEST(GameMechanicsTest, PrintPoints) {
    Player p1("Amit");
    p1.addVictoryPoints(2);
    p1.printPoints();
}

TEST(GameMechanicsTest, GetSettlements) {
    Player p1("Amit");
    p1.addResources("wood", 1);
    p1.addResources("brick", 1);
    p1.addResources("wheat", 1);
    p1.addResources("wool", 1);
    Board board;
    p1.placeSettlement(21, board);
    EXPECT_EQ(p1.getSettlements().size(), 1);
}

TEST(GameMechanicsTest, GetCities) {
    Player p1("Amit");
    p1.addResources("wood", 1);
    p1.addResources("brick", 1);
    p1.addResources("wheat", 3);
    p1.addResources("wool", 1);
    Board board;
    Settlement* s2= p1.placeSettlement(21, board);
    p1.addResources("ore", 3);
    City* city= p1.upgradeToCity(board, 21);
    EXPECT_EQ(p1.getCities().size(), 1);
}

TEST(GameMechanicsTest, GetRoads) {
    Player p1("Amit");
    p1.addResources("wood", 1);
    p1.addResources("brick", 1);
    Board board;
    p1.placeRoad(25, board);
    EXPECT_EQ(p1.getRoads().size(), 1);
}



// Test Choosing Starting Player
TEST(CatanTest, ChooseStartingPlayer) {
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    catan.ChooseStartingPlayer();
    EXPECT_TRUE(p1.isTurnPlayer());
    EXPECT_FALSE(p2.isTurnPlayer());
    EXPECT_FALSE(p3.isTurnPlayer());
}









TEST(GameMechanicsTest, EndTurn) {
    Player p1("Amit");
    p1.endTurn();
    EXPECT_FALSE(p1.isTurnPlayer());
}



// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
