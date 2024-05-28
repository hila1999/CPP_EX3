#include "catan.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;
Catan::Catan(Player& player1, Player& player2, Player& player3) 
    : p1(player1), p2(player2), p3(player3), currentPlayer(nullptr) {
    currentPlayer = &p1;
    Board board;
    }

Catan::~Catan(){
    // delete p1;
    // delete p2;
    // delete p3;
}
string Catan::ChooseStartingPlayer(){
    // cout<<"the starting player is:"<<currentPlayer ->getName()<<endl;
    return currentPlayer ->getName();
}
Board& Catan::getBoard(){
    return board;
}