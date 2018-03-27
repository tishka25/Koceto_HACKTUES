#include "Input.h"

Input::Input(){}
Input::Input(int type){
  this->type=type;
}
void Input::begin(){
  switch (type) {
    case KEYBOARD:
      keyboard.begin();
      break;
    case PS_CONTROLLER:
      psx.begin();
      break;
  }
}
unsigned int Input::getInput(){
  switch (type) {
    case KEYBOARD:
      return fakeJoystick(keyboard.input());
      break;
    case PS_CONTROLLER:
      return psx.getInput();
      break;
  }
}
unsigned int Input::fakeJoystick(char keyInput){
  switch(keyInput){
    case 'a':return psxLeft;
    case 's':return psxDown;
    case 'd':return psxRight;
    case 'w':return psxUp;
    // case PS2_ENTER:return psxStrt;
    // case PS2_TAB:return psxSlct;
    case 'j':return psxSqu;
    case 'k':return psxX;
    case 'l':return psxO;
    case 'i':return psxTri;
    case 'p':return psxR1;
    case 'e':return psxL1;
    case 'o':return psxR2;
    case 'q':return psxL2;
    default:return 0;
  }
}
