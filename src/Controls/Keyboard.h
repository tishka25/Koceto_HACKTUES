#include <PS2Keyboard.h>

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define SHIELD_DATAPIN 2
#define SHIELD_IRQ  3

class Keyboard{
public:
  char *buffer[];
  PS2Keyboard keyboard;
  Keyboard();
  void begin();
  bool key(int key);
  char input();
   int control();
};

#endif
