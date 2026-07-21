#ifndef  BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop:public Piece

{
public:
Bishop();
Bishop(Position p,char c);
~Bishop();
 bool CanMove(const Position& to,
              const Board& board) 
              const override;
};

#endif              