#include "Position.h"
Position::Position()
{
row=0;
col=0;
};
Position::Position(int r, int c)
{
 row=r;
 col=c;
};
Position::~Position()
{

}
void Position::setRow(int r)
{
  row=r;
};
void Position::setCol(int c)
{
    col=c;
}
int Position::getRow()const
{
    return row;
}
int Position::getCol()const
{
    return col;
}

Position Position::FromString(const string& s)
{
    int col =s[0]-'a';
    int row=8- (s[1]-'0');
    return Position(row ,col);
};
