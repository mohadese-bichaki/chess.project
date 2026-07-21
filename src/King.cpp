#include "King.h"
#include "Board.h"
#include "Rook.h"
King::King()
{

}
King::King(Position p, char c)
:Piece(p , c)
{
 hasMoved = false;
}
King::~King()
{
    
}
bool King::CanMove
(const Position& to,const Board& board)const
{Position current =getposition();
    int rowDiff=abs(to.getRow()-current.getRow());
    int colDiff=abs(to.getCol()-current.getCol());
    if(rowDiff==0 && colDiff==0)//not move
    return false;
Piece* target = board.GetPiece(to);
if(target!=nullptr)
{
    if(target->GetColor()==GetColor())
        return false;
}
 if(rowDiff<=1&&colDiff<=1)
 return true;
    //castling  
    if(rowDiff==0 &&colDiff==2)
{
    if(HasMoved())
        return false;
    Position rookPos;
    if(to.getCol() > current.getCol())
        rookPos=Position(current.getRow(), 7);  
    else
        rookPos=Position(current.getRow(), 0); 

    Piece* rookPiece=board.GetPiece(rookPos);

    Rook* rook=dynamic_cast<Rook*>(rookPiece);

    if(rook==nullptr)
        return false;

    if(rook->HasMoved())
        return false;
    if(!board.IsPathClear(current,rookPos))
    return false;
    return true;
}








    return false;
}

bool King::HasMoved()const{
    return hasMoved;
}
void King ::SetMoved(bool moved){
    hasMoved=moved;
}