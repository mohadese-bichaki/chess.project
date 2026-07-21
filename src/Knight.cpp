#include "Knight.h"
#include "cmath"
Knight::Knight()
{

}
Knight::Knight(Position p, char c)
:Piece( p ,c)
{

}
Knight::~Knight()
{
    
}
bool Knight::CanMove(const Position& to,const Board& board)const
{ Position current=getposition();
  Piece* target=board.GetPiece(to);
if(target!=nullptr)
{
    if(target->GetColor()==GetColor())
        return false;
}
    int rowDiff=abs(to.getRow()-current.getRow());
    int colDiff=abs(to.getCol()-current.getCol());
      if (rowDiff==2 && colDiff==1)
        return true;
      if (colDiff==1&&rowDiff==2)
        return true;
    return false;
}