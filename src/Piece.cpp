#include "Piece.h"
Piece::Piece()
{
 alive=true;
}

Piece::Piece( const Position& p, char c)
{
    position=p;
    color =c;
    alive=true;
}
Piece::~Piece()
{

}
bool Piece::CanMove(const Position& to,
const  Board& board )const 
{
return false;
}

char Piece::GetColor()const
{
    return color;
}
Position Piece::getposition()const
{
  return position;
}
void Piece::SetPosition(const Position& p)
{
    position=p;
}