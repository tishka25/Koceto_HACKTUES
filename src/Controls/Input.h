#include "PSX.h"
#include "Keyboard.h"

#ifndef INPUT_H
#define INPUT_H


#define KEYBOARD      1
#define PS_CONTROLLER 2

class Input{
  int type;
  Keyboard keyboard;
  PSX psx;
  Input();
  Input(int type);
  void begin();
};

#endif
