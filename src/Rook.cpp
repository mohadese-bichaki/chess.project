#include "Rook.h"
#include "Board.h"
Rook::Rook()
{

}
Rook::Rook(Position p,char c)
:Piece(p, c)
{
 hasMoved= false;
}
Rook::~Rook()
{

}

bool Rook::CanMove(const Position& to,const Board& board)const
{

Position current = getposition();
Piece* target = board.GetPiece(to);
if(target != nullptr)
{
    if(target->GetColor()==GetColor())
        return false;
}
    int rowDiff = to.getRow()-current.getRow();
    int colDiff = to.getCol()-current.getCol();
  
    if(rowDiff == 0||colDiff==0)
{
    if(!board.IsPathClear(current,to))
        return false;
    return true;
}

return false;
}
bool Rook::HasMoved()const
{
    return hasMoved;
}
void Rook ::SetMoved(bool moved)
{
    hasMoved=moved;
}