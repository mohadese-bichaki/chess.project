#include "Bishop.h"
#include "cmath"
#include"Board.h"
Bishop::Bishop()
{

}
Bishop::Bishop(Position p, char c)
:Piece(p ,c)
{

}
Bishop::~Bishop()
{
    
}
bool Bishop::CanMove(const Position& to,const Board& board) const
{ 
    Position current = getposition();
    Piece* target = board.GetPiece(to);
if(target!=nullptr)
{
    if(target->GetColor()==GetColor())
     return false;
}
    int rowDiff=to.getRow()-current.getRow();
    int colDiff=to.getCol()-current.getCol();
     
    if(abs(rowDiff)==abs(colDiff))
        {if(!board.IsPathClear(current,to))
           return false;
           return true;
        }
    return false;}
