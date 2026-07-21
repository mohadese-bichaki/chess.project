#include "Queen.h"
Queen::Queen()
{

}
Queen::Queen(Position p, char c)
:Piece(p ,c)
{

}
Queen::~Queen()
{
    
}
bool Queen::CanMove(const Position& to,const Board& board)const
{
    Position current=getposition();
    Piece* target = board.GetPiece(to);
    if(target!=nullptr)
    {
        if(target->GetColor()==GetColor())
            return false;
    }

    int rowDiff=abs(to.getRow()-current.getRow());
    int colDiff=abs(to.getCol()-current.getCol());
    if(rowDiff==0 && colDiff==0)
        return false;
    if(rowDiff==0||colDiff==0)
        return board.IsPathClear(current,to);
    if(rowDiff==colDiff)
        return board.IsPathClear(current,to);
    return false;
}