#ifndef BOARD_H
#define  BOARD_H
#include "Piece.h"

class King;
class Move;
class Board
{
private:
  Piece* board[8][8];
  Position lastFrom;
  Position lastTo;
  bool lastMoveWasPawnTwoSteps=false;
  public:
  Board();
  ~Board();
  void PrintBoard();
  Piece* GetPiece(const Position& p)const;
  void MovePiece(const Position& from,const Position& to);
  bool IsEmpty(const Position& p)const;
  bool IsPathClear(const Position&from,const Position& to)const;

 void RemovePiece(const Position& p);
 King* FindKing(char color)const;
 bool IsKingInCheck(char color)const;
 void UndoMove(const Move& move);
 bool IsCheckmate(char color);
 bool IsStalemate(char color);
 bool LastMoveWasPawnTwoSteps()const;
Position GetLastFrom()const;
Position GetLastTo()const;
};


#endif