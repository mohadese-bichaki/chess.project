#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Board.h"
class Pawn: public Piece
{
  public:
   Pawn();
   Pawn(Position p,char c);
   ~Pawn();
bool CanMove (const Position& to,const Board& board) const override;
};
#endif 