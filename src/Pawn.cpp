#include "Pawn.h"
Pawn::Pawn()
{

};
Pawn::Pawn( Position p, char c)
  :Piece(p ,c){
    
}

    bool Pawn::CanMove(const Position& to,const Board& board)const
{
    Position current = getposition();
    int rowDiff=to.getRow()-current.getRow();
    int colDiff=to.getCol()-current.getCol();
 if(GetColor() == 'W') //dell
    {
        if(colDiff==0 && rowDiff== -1)
            return true;
        if(current.getRow()== 6 &&colDiff==0 &&rowDiff==-2)
            return true;
    }
    else
    {
        if(colDiff==0 && rowDiff==1)
            return true;

        if(current.getRow()==1&&colDiff == 0 &&rowDiff==2)
            return true;  //dell
    }
if(abs(colDiff)==1)
{
    if(GetColor()=='W'&&rowDiff==-1)
    {
        if(!board.IsEmpty(to))
        {
            Piece* target=board.GetPiece(to);

            if(target->GetColor()!='W')
                return true;
        }
    }

    if(GetColor()=='B'&&rowDiff==1)
    {
        if(!board.IsEmpty(to))
        {
            Piece* target=board.GetPiece(to);

            if(target->GetColor()!='B')
                return true;
        }
    }
}


//En Passant 

int dir = (GetColor() == 'W') ? -1 : 1;

if (abs(to.getCol()-current.getCol())== 1&& to.getRow()==current.getRow()+dir)
{
    if (board.IsEmpty(to))
    {
        if (board.LastMoveWasPawnTwoSteps())
        {
            Position last=board.GetLastTo();

            if (last.getRow()==current.getRow()&&last.getCol()==to.getCol())
            {
                return true;
            }
        }
    }
}
    return false;
}
Pawn::~Pawn()
{
    
}