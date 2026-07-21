#include "Game.h"
#include <iostream>
#include <string>
#include "Move.h"

using namespace std;
Game::Game()
{
currentPlayer='W';
gameOver=false;
}

void Game::start()
{
while(!gameOver)
{
board.PrintBoard();
 if(currentPlayer=='W')
    cout<<"******* White's turn*******"<<endl;
 else cout<<"*******Black's turn*******"<<endl;
 string from;
 string to;
 cout<<"Enter the Position from witch to move:";
 cin>>from;
 cout<<"Enter the destination:";
 cin>>to;
 Position fromPos=Position::FromString(from);
 cout<<fromPos.getRow()<<" "<<fromPos.getCol()<<endl;
 Position toPos=Position::FromString(to);
Piece* piece =board.GetPiece(fromPos);
if(piece==nullptr)
{// check if the square is empty or not
    cout<<"No piece in this position!"<<endl;
    continue;
}
cout<<"Current Player:"<<currentPlayer<<endl;
cout<<"Piece Color:"<<piece->GetColor()<<endl;
if (piece->GetColor() !=currentPlayer)
{
    cout<<"Wrong piece!"<<endl;
    continue;
}
if(!piece->CanMove(toPos, board))
{
    cout<<"Invalid Move!"<<endl;
    continue;
}
Piece* target=board.GetPiece(toPos);

if(target!=nullptr)
{
    if(target->GetColor()==currentPlayer)
    {
        cout<<"You can not capture your own piece!"<<endl;
        continue;
    }
}

Move move(fromPos,toPos);
move.SetCapturedPiece(target);
board.MovePiece(fromPos, toPos);
if(board.IsKingInCheck(currentPlayer))
{  // currentPlayers color
    board.UndoMove(move);
    cout<<"Illegal Move! Your King would be in check."<< endl;
    continue;
}
moveHestory.push_back(move);
if(currentPlayer=='W')
 currentPlayer='B';
 else
 currentPlayer='W';
    
 if(board.IsKingInCheck(currentPlayer))
{
    if(board.IsCheckmate(currentPlayer))
    {
        cout<<"CHECKMATE!"<<endl;
        gameOver=true;
        break;
    }

    cout<<"CHECK!"<<endl;
}     
    else if(board.IsStalemate(currentPlayer))
{
    cout<<"STALEMATE!"<<endl;
    gameOver=true;
    break;
}  
}
}
