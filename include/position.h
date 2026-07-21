#ifndef POSITION_H
#define POSITION_H
#include <string>
using namespace std;

class Position
{
private:
int row;
int col;
public:
Position();
~Position();
Position(int r,int c);
void setRow(int r);
void setCol(int c);
int getRow()const;
int getCol()const;
static Position FromString(const string& s);
};
#endif