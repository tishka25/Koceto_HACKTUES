#include <PS2Keyboard.h>
//Controls
// #define UP     0
// #define RIGHT  1
// #define DOWN   2
// #define LEFT   3


#define SHIELD_DATAPIN 8
#define SHIELD_IRQ  9

class Keyboard{
public:
  int DataPin , IRQpin;
  char *buffer[];
  PS2Keyboard keyboard;
  Keyboard();
  Keyboard(int DataPin , int IRQpin);
  void begin();

  bool key(int key);
  char input();
   int control();
  void setPins(int _DataPin,int _IRQpin);
};
