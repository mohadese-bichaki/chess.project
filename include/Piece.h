#include "Position.h"
#ifndef PIECE_H
#define PIECE_H
class Board;
class Piece
{
 protected:
  Position position; 
  char color;
  bool alive;
  
  public:
  Piece();
  Piece(const Position& p,char c);
 virtual ~Piece();
 void SetPosition(const Position& p);
 void setcolor(char c);
 void setalive(bool a);
 Position getposition()const;
 char GetColor()const;
 bool isalive()const;
 virtual bool CanMove(const Position& to,const Board& board)const;
};
#endif