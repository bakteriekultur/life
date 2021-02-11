#pragma once
#include <windows.h>
#include <vector>
class display{
  public:
    display();
    ~display();

  private:
  HANDLE oldScreenBuffer;
  HANDLE newScreenBuffer;
  int width;
  int height;
  std::vector<CHAR_INFO> screen;



};
