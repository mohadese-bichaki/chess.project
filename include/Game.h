#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Move.h"
#include <vector>
using namespace std;
class Game
{
private:
Board board;
char currentPlayer;
vector<Move> moveHestory;
bool gameOver;
public:
Game();
void start();
};
#endif