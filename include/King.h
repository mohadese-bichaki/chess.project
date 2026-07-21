#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Board.h"
class King:public Piece
{
public:
King();
King(Position p,char c);
~King();
  bool CanMove (const Position& to, const Board& board) const override;
  bool HasMoved()const;
  void SetMoved(bool moved);
private:
   bool hasMoved;           
};
#endif