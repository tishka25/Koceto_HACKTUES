#include "PSX.h"
#include "Keyboard.h"

#ifndef INPUT_H
#define INPUT_H


#define KEYBOARD      1
#define PS_CONTROLLER 2



#define LEFT  1
#define RIGHT 2
#define UP    3
#define DOWN  4

class Input{
public:
  int type=2;
  Keyboard keyboard;
  PSX psx;
  Input();
  Input(int type);
  void begin();
  unsigned int getInput();
  unsigned int fakeJoystick(char keyInput);
};

#endif
