#include<iostream>
using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

// Function for rotation
int rotate(int x, int y, int r) {
  switch(r % 4) {
    case 0: return ( y * 4 ) + x
    case 1: return 12 + y - ( x * 4)
    case 2: return 15 - x - ( y * 4 )
    case 3: return 3 - y + ( x * 4 )
  }
  return 0;
}

int main()
{
  // Creating assets (peices)
  // Line
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");
  tetromino[0].append(L"..X.");
  // Z
  tetromino[1].append(L"..X.");
  tetromino[1].append(L".XX.");
  tetromino[1].append(L".X..");
  tetromino[1].append(L"....");
  // Another Z
  tetromino[2].append(L"..X.");
  tetromino[2].append(L".XX.");
  tetromino[2].append(L".X..");
  tetromino[2].append(L"....");
  // Square
  tetromino[3].append(L"....");
  tetromino[3].append(L".XX.");
  tetromino[3].append(L".XX.");
  tetromino[3].append(L"....");
  // T
  tetromino[4].append(L"..X.");
  tetromino[4].append(L".XX.");
  tetromino[4].append(L"..X.");
  tetromino[4].append(L"....");
  // Left L
  tetromino[5].append(L"....");
  tetromino[5].append(L".XX.");
  tetromino[5].append(L"..X.");
  tetromino[5].append(L"..X.");
  // Right L
  tetromino[6].append(L"....");
  tetromino[6].append(L".XX.");
  tetromino[6].append(L".X..");
  tetromino[6].append(L".X..");
    
  return 0;
}