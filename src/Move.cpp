#include "Move.h"
#include "Piece.h"
Move::Move()
{


}
Move::Move( Position f, Position t)
{
 from=f;
 to=t;
 capturedPiece=nullptr;
};
Position Move::GetFrom()const
{
    return from;
}
Position Move::GetTo()const
{
    return to;
}
Piece* Move::GetCapturedPiece()const
{
    return capturedPiece;
}
void Move ::SetCapturedPiece(Piece* piece)
{
    capturedPiece = piece;
}





