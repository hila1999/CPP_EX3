#include "catan.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;
Catan::Catan(Player& player1, Player& player2, Player& player3) 
    : p1(player1), p2(player2), p3(player3), currentPlayer(&p1) {
    // currentPlayer = &p1;
    static Board board;
    }
    

Catan::~Catan(){}
    
void Catan::ChooseStartingPlayer() {
    currentPlayer = &p1;
    p1.setTurn(true);
    p2.setTurn(false);
    p3.setTurn(false);
    std::cout << "The starting player is: " << currentPlayer->getName() << std::endl;
}
Player& Catan::getCurrentPlayer(){
    return *currentPlayer;
}
Board& Catan::getBoard(){
    return board;
}