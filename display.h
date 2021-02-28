#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
class Display{
  public:
    Display();
    ~Display();
    void PrintScreen();
    void Clear();

  private:
  HANDLE oldScreenBuffer;
  HANDLE screenBuffer;
  int width;
  int height;
  std::vector<CHAR_INFO> screen;
};
