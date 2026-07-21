#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Board.h"
class Queen:public Piece
{
public:
Queen();
Queen(Position p,char c);
~Queen();
 bool CanMove (const Position& to, const Board& board)const override;
};
#endif