#include "display.h"
#include "display.cpp"

int main(){
  Display* disp = NULL;
  disp = new Display;
  bool running = true;
  disp->Clear();
  disp->PrintScreen();
  delete disp;
  return 0;
}
