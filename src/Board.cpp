#include <iostream>
using namespace std;
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Move.h"
#include "Position.h"
#include "Piece.h"
#include <cctype>
Board::Board()
{
 for (int row=0;row<8;row++)
 {
     for(int col=0;col<8;col++)
     {
        board[row][col]=nullptr;
     }
 }
   board[0][0]=new
   Rook(Position(0,0),'B');

   board[0][1]=new
   Knight(Position(0,1),'B');

   board[0][2]=new
   Bishop(Position(0,2),'B');

   board[0][3]=new
   Queen(Position(0,3),'B')  ;
   
   board[0][4]=new
   King(Position(0,4) ,'B');

   board[0][5]=new
   Bishop(Position(0,5),'B');

   board[0][6]=new
   Knight(Position(0,6),'B');

   board[0][7]=new
   Rook(Position(0,7),'B');

   for(int col=0;col<8;col++)
   {
     board[1][col]=new 
     Pawn(Position(1,col),'B');
   }

   for(int col=0;col<8;col++)
   {
     board[6][col]=new 
     Pawn(Position(6,col),'W');
   }

   board[7][0]=new
   Rook(Position(7,0),'W');

   board[7][1]=new
   Knight(Position(7,1),'W');

   board[7][2]=new
   Bishop(Position(7,2),'W');

   board[7][3]=new
   Queen(Position(7,3),'W');

   board[7][4]=new
   King(Position(7,4),'W');

   board[7][5]=new
   Bishop(Position(7,5),'W');

   board[7][6]=new
   Knight(Position(7,6),'W');

   board[7][7]=new
   Rook(Position(7,7),'W');

}
Board::~Board()
{
for(int row=0;row<8;row++)
{
     for(int col=0;col<8;col++)
     {
       if ( board[row][col]!=nullptr)
       {
        delete board[row][col];
        board[row][col]=nullptr;
     }
   }
 }
};
void Board::PrintBoard()
{
    cout << "\n";
    cout << "      a   b   c   d   e   f   g   h\n";
    cout << "    +---+---+---+---+---+---+---+---+\n";

    for(int row = 0;row < 8;row++)
    {
        cout << " "<< 8-row<< "  |";

        for(int col = 0; col < 8; col++)
        {
            if(board[row][col]==nullptr)
            {
                cout << "   |";
            }
            else
            {
                char symbol;

                Piece*piece=board[row][col];

                if(dynamic_cast<King*>(piece))
                    symbol='K';
                else if(dynamic_cast<Queen*>(piece))
                    symbol='Q';
                else if(dynamic_cast<Rook*>(piece))
                    symbol='R';
                else if(dynamic_cast<Bishop*>(piece))
                    symbol='B';
                else if(dynamic_cast<Knight*>(piece))
                    symbol='N';
                else
                    symbol='P';

                if(piece->GetColor()=='B')
                    symbol =tolower(symbol);

                cout << " "<<symbol <<" |";
            }
        }

        cout << " "<< 8-row << endl;
        cout << "    +---+---+---+---+---+---+---+---+\n";
    }

    cout << "      a   b   c   d   e   f   g   h\n\n";
}
   

Piece* Board::GetPiece(const Position& p)const
{
    return board[p.getRow()][p.getCol()];
}

void Board::MovePiece(const Position& from, const Position& to)
{
    //intial state
    bool destinationWasEmpty=(board[to.getRow()][to.getCol()]==nullptr);
        Piece*capturePiece=board[to.getRow()][to.getCol()];
  //piece movement
    board[to.getRow()][to.getCol()]=board[from.getRow()][from.getCol()];
    board[to.getRow()][to.getCol()]->SetPosition(to);
    Piece* piece = board[to.getRow()][to.getCol()];
//log the king and rook move
    if(dynamic_cast<King*>(piece))
    dynamic_cast<King*>(piece)->SetMoved(true);
    if(dynamic_cast<Rook*>(piece))
    dynamic_cast<Rook*>(piece)->SetMoved(true);
    //special moves
    //Castling 
    King* king=dynamic_cast<King*>(piece);

    if(king!=nullptr && abs(to.getCol()-from.getCol())==2)
    {
    //short castling
        if(to.getCol()>from.getCol())
        {
            board[from.getRow()][5]=board[from.getRow()][7];

            board[from.getRow()][7]=nullptr;
            board[from.getRow()][5]->SetPosition(Position(from.getRow(),5));
            dynamic_cast<Rook*>(board[from.getRow()][5])->SetMoved(true);
        }
        //long castling
        else
        {
            board[from.getRow()][3]=board[from.getRow()][0];

            board[from.getRow()][0]=nullptr;
            board[from.getRow()][3]->SetPosition(Position(from.getRow(),3));
            dynamic_cast<Rook*>(board[from.getRow()][3])->SetMoved(true);
        }
    }
//en passant
    if(dynamic_cast<Pawn*>(piece))
{
    if(destinationWasEmpty&&abs(to.getCol()-from.getCol())==1&&lastMoveWasPawnTwoSteps)
    {
        if(lastTo.getRow()==from.getRow()&&lastTo.getCol()==to.getCol())
        {
            board[lastTo.getRow()][lastTo.getCol()]=nullptr;
        }
    }

}
// Promotion

Pawn* pawn=dynamic_cast<Pawn*>(piece);
if(pawn)
{
    if((pawn->GetColor()=='W'&& to.getRow()==0)||(pawn->GetColor()=='B'&& to.getRow()==7))
    {
        char choice;
        cout << "Promote to (Q,R,B,N): ";
        cin >> choice;
        delete board[to.getRow()][to.getCol()];
        switch(toupper(choice))
        {
        case 'Q':
            board[to.getRow()][to.getCol()]=new Queen(to, pawn->GetColor());
            break;
        case 'R':
            board[to.getRow()][to.getCol()]=new Rook(to, pawn->GetColor());
            break;
        case 'B':
            board[to.getRow()][to.getCol()]=new Bishop(to, pawn->GetColor());
            break;
        case 'N':
            board[to.getRow()][to.getCol()]=new Knight(to,pawn->GetColor());
            break;
        default:
            board[to.getRow()][to.getCol()]=new Queen(to, pawn->GetColor());
            break;
        }
        piece=board[to.getRow()][to.getCol()];
    }
}
   if(dynamic_cast<Pawn*>(piece))
    {
        if(abs(to.getRow()-from.getRow())==2)
        {
            lastMoveWasPawnTwoSteps = true;
            lastFrom = from;
            lastTo = to;
        }
        else
        {
            lastMoveWasPawnTwoSteps=false;
        }
    }
    else
    {
        lastMoveWasPawnTwoSteps=false;
    }
//clearing the previous square   
     board[from.getRow()][from.getCol()]=nullptr;
}


bool Board::IsEmpty(const Position& p)const
{
    return board[p.getRow()][p.getCol()]==nullptr;
}


bool Board::IsPathClear(const Position& from,const Position& to)const
{
    int rowStep=0;
    int colStep=0;

    if(to.getRow()>from.getRow())
        rowStep=1;
    else if(to.getRow()<from.getRow())
        rowStep=-1;

    if(to.getCol()>from.getCol())
        colStep=1;
    else if(to.getCol()<from.getCol())
        colStep=-1;
    int currentRow=from.getRow()+rowStep;
    int currentCol=from.getCol()+colStep;

    while(currentRow!= to.getRow()||currentCol!=to.getCol())
    {
        if(board[currentRow][currentCol]!=nullptr)
            return false;
        currentRow+=rowStep;
        currentCol+=colStep;
    }

    return true;
}
//removing piece
void Board::RemovePiece(const Position& p)
{
    if(board[p.getRow()][p.getCol()]!=nullptr)
    {
        delete board[p.getRow()][p.getCol()];
        board[p.getRow()][p.getCol()]=nullptr;
    }
}
King* Board::FindKing(char color)const
{
    for (int row=0;row<8;row++)
    {
        for (int col=0;col<8;col++)
        {
            Piece* piece=board[row][col];
            if(piece!=nullptr&&piece->GetColor()==color)
            {
                King* king=dynamic_cast<King*>(piece);
                if(king!=nullptr)
                return king;
            }
        }
    }
    return nullptr;
}
bool Board::IsKingInCheck(char color)const
 {
  
 King* king=FindKing(color);
 if(king==nullptr)
    return false;
Position kingPos=king->getposition();
char enemy;
if(color=='W')
 enemy='B';
 else 
 enemy='W';
 
 for(int row=0; row<8; row ++)
 {
    for(int col=0; col<8; col++)
    {
       Piece* piece=board[row][col]; //store the piece in the 'piece' variable
       if(piece!= nullptr && piece->GetColor()==enemy)
       {
        if(piece->CanMove(kingPos,*this)){
            return true;
        }
       }
    }
 }
 return false;
}

void Board::UndoMove(const Move& move)
{
    Piece* piece = board[move.GetTo().getRow()][move.GetTo().getCol()];
           
    // undo En Passant 
    if(dynamic_cast<Pawn*>(piece)&& 
       move.GetCapturedPiece()==nullptr&&abs(move.GetTo().getCol()-move.GetFrom().getCol())==1)
    {
        // put the opponent's pawn back
        Position capturedPos(move.GetFrom().getRow(), move.GetTo().getCol());
        char enemyColor=(piece->GetColor()=='W')?'B':'W';
        board[capturedPos.getRow()][capturedPos.getCol()]=new Pawn(capturedPos,enemyColor);
    }
     // undo the main move
    board[move.GetFrom().getRow()][move.GetFrom().getCol()]=piece;
    board[move.GetTo().getRow()][move.GetTo().getCol()]=move.GetCapturedPiece();
    
    if(piece != nullptr)
    piece->SetPosition(move.GetFrom());
//if the move was Castling 
    King* king = dynamic_cast<King*>(piece);
    if(king && abs(move.GetTo().getCol()-move.GetFrom().getCol())==2)
    {
        int row=move.GetFrom().getRow();
        if (move.GetTo().getCol() > move.GetFrom().getCol()) //short castling
        {
            // move the rook back from 5 to 7
            board[row][7]=board[row][5];
            board[row][5]=nullptr;
            if(board[row][7])
                board[row][7]->SetPosition(Position(row,7));
        }
        else //long castling
        {
            //  move the rook back from 3 to 0
            board[row][0]=board[row][3];
            board[row][3]=nullptr;
            if (board[row][0])
                board[row][0]->SetPosition(Position(row, 0));
        }
    }


    if (piece!=nullptr)
        piece->SetPosition(move.GetFrom());

    // reset the lastMoveWasPawnTwoSteps
    lastMoveWasPawnTwoSteps=false;
}

bool Board::IsCheckmate(char color)
{
    if(!IsKingInCheck(color))
        return false;
    for(int row=0;row<8;row++)
    {
        for(int col=0;col<8;col++)
        {
            Piece* piece=board[row][col];
            if(piece==nullptr||piece->GetColor()!=color)
                continue;
            for(int r=0;r<8;r++)
            {
                for(int c=0;c< 8;c++)
                {
                    Position to(r,c);
                    if(!piece->CanMove(to,*this))
                        continue;
                    Position from=piece->getposition();
                    Move move(from,to);
                    Piece* target=GetPiece(to);
                    move.SetCapturedPiece(target);

                    //  save the lastMoveWasPawnTwoSteps
                    bool oldLastMoveWasPawnTwoSteps=lastMoveWasPawnTwoSteps;
                    Position oldLastFrom=lastFrom;
                    Position oldLastTo=lastTo;
                    MovePiece(from, to);
                    if (!IsKingInCheck(color))
                    {
                        UndoMove(move);
                        //  restore the state
                        lastMoveWasPawnTwoSteps=oldLastMoveWasPawnTwoSteps;
                        lastFrom=oldLastFrom;
                        lastTo=oldLastTo;
                        return false;
                    }
                    UndoMove(move);
                    //  restore the state
                    lastMoveWasPawnTwoSteps=oldLastMoveWasPawnTwoSteps;
                    lastFrom=oldLastFrom;
                    lastTo=oldLastTo;
                }
            }
        }
    }
    return true;
}

//stalemate
bool Board::IsStalemate(char color)
{
    if(IsKingInCheck(color))
        return false;
    for(int row=0; row<8;row++)
        for(int col=0;col<8;col++)
        {
            Piece* piece=board[row][col];

            if(piece==nullptr||piece->GetColor()!= color)
                continue;

            for(int r=0; r<8;r++)
            {
                for(int c=0;c<8;c++)
                {
                    Position to(r,c);
                    Piece* target=GetPiece(to);
                    if(target!=nullptr&&target->GetColor()==color)
                        continue;
                    if(!piece->CanMove(to,*this))
                        continue;
                    Position from=piece->getposition();
                    Move move(from, to);
                    move.SetCapturedPiece(target);
                    // save situation of en Passant
                    bool oldLastMoveWasPawnTwoSteps=lastMoveWasPawnTwoSteps;
                    Position oldLastFrom=lastFrom;
                    Position oldLastTo=lastTo;
                    MovePiece(from,to);
                    bool kingSafe = !IsKingInCheck(color);

                    UndoMove(move);

                    //   restore the state
                    lastMoveWasPawnTwoSteps=oldLastMoveWasPawnTwoSteps;
                    lastFrom=oldLastFrom;
                    lastTo=oldLastTo; 
                    if(kingSafe)
                        return false;
                }
            }
        }
    return true;
}
 bool Board::LastMoveWasPawnTwoSteps()const
{
    return lastMoveWasPawnTwoSteps;
}

Position Board::GetLastFrom()const
{
    return lastFrom;
}

Position Board::GetLastTo()const
{
    return lastTo;
}     

