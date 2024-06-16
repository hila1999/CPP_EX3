/**
 * Demo file for Ex3.
 *
 */
//hila.shamir99@gmail.com
//314906983
#include "catan.hpp"
#include "player.hpp"
#include "Board.hpp"
#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
//add check that edge near to the vertex
//add check that the edge and vertex is not already taken
//make boear static
//implement cardRoadBuilding implementation cardMonopoly
//chack if add 3 cardsKingRoad so add 2 victory points
using namespace std;
using namespace ariel;


int main()
{
        cout << "Players11 created" << endl;
        Player p1("Amit");
        Player p2("Yossi");
        Player p3("Dana");

        Catan catan(p1, p2, p3);
         cout << "Players created" << endl;
        catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
        Board& board = catan.getBoard(); // get the board of the game.
        board.addPlayer(p1);
        board.addPlayer(p2);
        board.addPlayer(p3);
        Structure* s1 = new Settlement(&p1);
        Structure* s2 = new Settlement(&p1);
        Structure* s3 = new Settlement(&p2);
        Structure* s4 = new Settlement(&p2);
        Structure* s5 = new Settlement(&p3);
        Structure* s6 = new Settlement(&p3);
        board.placeStructure(*s1, 21);
        board.placeStructure(*s2, 33);
        board.placeStructure(*s3, 19);
        board.placeStructure(*s4, 44);
        board.placeStructure(*s5, 12);
        board.placeStructure(*s6, 40);
        Structure* r1 = new Road(&p1);
        Structure* r2 = new Road(&p1);
        Structure* r3 = new Road(&p2);
        Structure* r4 = new Road(&p2);
        Structure* r5 = new Road(&p3);
        Structure* r6 = new Road(&p3);
        board.placeRoad(*r1, 25);
        board.placeRoad(*r2, 38);
        board.placeRoad(*r3, 24);
        board.placeRoad(*r4, 48);
        board.placeRoad(*r5, 44);
        board.placeRoad(*r6, 20);
        cout <<  "RAOAD AND SETTLEMENTS CREATED" << endl;
        p1.addResources("wood", 5);
        p2.addResources("wood", 2);
        p3.addResources("wood", 1);
        p2.addResources("ore", 1);
        p3.addResources("ore", 2);
        p2.addResources("wheat", 1);
        p3.addResources("wheat", 1);
        p2.addResources("wool", 1);
        p1.addResources("brick", 3);
        p2.addResources("brick", 1);
        p3.addResources("brick", 1);
        p1.addResources("wheat", 5);
        p1.addResources("wool", 1);
        p1.addResources("ore", 100);
        catan.getCurrentPlayer().rollDice(board);
        p1.placeRoad(26, board);
        Settlement* s25= p1.placeSettlement(13, board);
        City* c1=p1.upgradeToCity(board, 13);
        p1.trade(p2, "wood", "ore", 1, 1); // p1 trades 1 wood for 1 brick with p2.
        p1.addResources("ore" , 100);
        p1.addResources("wheat" ,10);
        p1.addResources("wheat" ,10);
        p1.addResources("wool" ,10);
        p2.addResources("ore" , 100);
      
        s1=p1.upgradeToCity(board, 21);
        cout <<p1.getVictoryPoints() <<endl;
        cout << p1.getName()<< " has" <<p1.getResources("ore") << " ore" << endl;
        cout <<p2.getName() << p2.getResources("ore") << endl;
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.buyDevelopmentCard(board);
        p1.useDevelopmentCard(board);
        p1.useDevelopmentCard(board);
        p1.useDevelopmentCard(board);
        p1.useDevelopmentCard(board);
        
        cout << p1.getName()<< " has" <<p1.getResources("ore") << " ore" << endl;
        p1.endTurn();
        p2.setTurn(true);
        p2.rollDice(board);

        try
        {
          p3.rollDice(board);
        }
        catch (const std::runtime_error &e)
        {
          cout << e.what() << endl;
          // Add a statement here if needed
        }
        p2.endTurn();
        try
        {
        Settlement* s26= p1.placeSettlement(44, board);
        }
          catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl; // Handle "Vertex already has an owner"
         } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl; // Handle "Not enough resources to place a settlement."
          } catch (const std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
      }
          
          delete s1;
          delete s2;
          delete s3;
          delete s4;
          delete s5;
          
          delete s6;
          delete c1;
          delete r1;
          delete r2;
          delete r3;
          delete r4;
          delete r5;
          delete r6;
}
    
   

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {4, 9};
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board);
    // try
    // {
    //     p3.placeSettelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }
    // vector<string> places = {"Forest", "Pasture Land"};
    // vector<int> placesNum = {5, 9};
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {3, 8};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board);
    // vector<string> places = {"Agricultural Land", "Pasture Land"};
    // vector<int> placesNum = {3, 9};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

    // // p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    // p1.rollDice();                                    // Lets say it's print 4. Then, p2 gets ore from the mountations.
    // p1.placeRoad({"Forest", "Hills"}, {5, 6}, board); // p1 continues to build a road.
    // p1.endTurn();                                     // p1 ends his turn.

    // p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.endTurn();  // p2 ends his turn.

    // p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    // p3.endTurn();  // p3 ends his turn.

    // try
    // {
    //     p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    // p1.rollDice();                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    // p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    // p1.endTurn();                        // p1 ends his turn.

    // p2.rollDice();           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    // p2.endTurn();            // p2 ends his turn.

    // p1.printPoints(); // p1 has 2 points because it has two settelments.
    // p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    // p3.printPoints(); // p3 has 2 points because it has two settelments.

    // catan.printWinner(); // Should print None because no player reached 10 points.
