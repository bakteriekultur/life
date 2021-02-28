#include "display.h"
Display::Display(){
  oldScreenBuffer = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(oldScreenBuffer, &bufferInfo);
  width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
  height = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1;
  screen.resize(width*height, {{L' '}, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY});
  screenBuffer = CreateConsoleScreenBuffer(GENERIC_WRITE,
      FILE_SHARE_WRITE,
      NULL,
      CONSOLE_TEXTMODE_BUFFER,
      NULL);
  SetConsoleActiveScreenBuffer(screenBuffer);
  SetConsoleTitle("Life"); 
  std::cout << "start" << std::endl;
}
Display::~Display(){
  SetConsoleActiveScreenBuffer(oldScreenBuffer);
  CloseHandle(oldScreenBuffer);
  CloseHandle(screenBuffer);
  std::cout << "end" << std::endl;
}
void Display::PrintScreen(){
  SMALL_RECT rect = {0,0,(short)width,(short)height};
  if(!WriteConsoleOutput(screenBuffer, screen.data(),
  (COORD){(short)width, (short)height}, (COORD){0,0}, &rect))
    std::cout << "Write console failed" <<std::endl;
  std::cout << "w: " << (short)width << "h: " << (short)height << std::endl;
      }
void Display::Clear(){
  screen.resize(width*height, {{L'a'}, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY});
  //std::cout << screen[0].Char.UnicodeChar << std::endl;
}

