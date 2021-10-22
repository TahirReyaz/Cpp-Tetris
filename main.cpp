#include<iostream>
using namespace std;

#include<Windows.h>

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int nScreenWidth = 80; // Console Screen size X
int nScreenHeight = 30; // Console Screen size Y

// Function for rotation
int rotate(int x, int y, int r) {
  switch(r % 4) {
    case 0: return ( y * 4 ) + x; // 0 degrees
    case 1: return 12 + y - ( x * 4); // 90 degrees
    case 2: return 15 - x - ( y * 4 ); // 180 degrees
    case 3: return 3 - y + ( x * 4 ); // 270 degrees
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
  // Right Z
  tetromino[1].append(L"..X.");
  tetromino[1].append(L".XX.");
  tetromino[1].append(L".X..");
  tetromino[1].append(L"....");
  // Left Z
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

  // Create play area
  pField = new unsigned char[nFieldWidth*nFieldHeight];
  // Set Board Boundary
  for (int x=0; x < nFieldWidth; x++) {
    for (int y=0; y< nFieldHeight; y++) {
      pField[y * nFieldWidth + x] = (x== 0 || x== nFieldWidth -1 || y== nFieldHeight -1) ? 9 : 0;
    }
  }

  wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight ];
  for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
  HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  SetConsoleActiveScreenBuffer(hConsole);
  DWORD dwBytesWritten = 0;

  bool bGameOver = false;

  while(!bGameOver) {
    // Display frame
    WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten)
  }

  return 0;
}