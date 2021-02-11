#include "display.h"
display::display(){
  oldScreenBuffer = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(oldScreenBuffer, &bufferInfo);
  width = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;
  height = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1;
  screen.resize(width*height, {L{' '}, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY});
  newScreenBuffer = CreateConsoleScreenBuffer(GENERIC_WRITE,
      FILE_SHARE_WRITE,
      NULL,
      CONSOLE_TEXTMODE_BUFFER,
      NULL);
  SetConsoleActiveScreenBuffer(newScreenBuffer);
}
display::~display(){
  SetConsoleActiveScreenBuffer(oldScreenBuffer);
  CloseHandle(oldScreenBuffer);
  CloseHandle(newScreenBuffer);
}
