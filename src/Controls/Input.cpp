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
