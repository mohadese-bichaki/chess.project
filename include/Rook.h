#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
class Rook:public Piece
{
public:
Rook();
Rook(Position p, char c);
~Rook();
  bool CanMove (const Position& to,const Board& board)const override;
bool HasMoved()const;
void SetMoved(bool moved);
 private:
 bool hasMoved;             
};
#endif