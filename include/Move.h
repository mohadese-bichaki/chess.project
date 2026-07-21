#ifndef MOVE_H
#define MOVE_H
#include "Position.h"
class Piece;
class Move
{
private:
 Position from;
 Position to;
 Piece* capturedPiece;
public:
 Move();
 Move(Position f,Position t);
 Position GetFrom()const;
 Position GetTo()const;
 void SetFrom(const Position& p);
 void SetTo(const Position& p);
 Piece* GetCapturedPiece()const;
 void SetCapturedPiece(Piece* piece);
};
#endif
