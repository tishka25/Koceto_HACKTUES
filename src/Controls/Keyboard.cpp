#include "Keyboard.h"


Keyboard::Keyboard(){}

void Keyboard::begin(){
  keyboard.begin(SHIELD_DATAPIN,SHIELD_IRQ);
}
char Keyboard::input(){
  int count=0;
  char c;
  if(keyboard.available()) {
    c=keyboard.read();
    Serial.print(c);
    buffer[count]=&c;
  }
  if(keyboard.read()==PS2_ENTER){
    return **buffer;
  }
}
// int Keyboard::control(){
//   int dir;
//   if (keyboard.available()) {
//     char c=keyboard.read();
//     switch (c) {
//       case PS2_UPARROW: dir=UP;break;
//       case PS2_RIGHTARROW: dir=RIGHT;break;
//       case PS2_DOWNARROW:dir=DOWN;break;
//       case PS2_LEFTARROW: dir=LEFT;break;
//       default: dir=-1;break;
//     }
//   }
//   return dir;
// }

bool Keyboard::key(int key){
  if(keyboard.read()==key){return true;}
  else {return false;}
}
