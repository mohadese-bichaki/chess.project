#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Board.h"
class Knight:public Piece
{
  public:
   Knight();
   Knight(Position p, char c);
   ~Knight();
   bool CanMove (const Position& to,const Board& board)const override;
};
#endif