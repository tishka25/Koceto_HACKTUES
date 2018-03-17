#include "PSX.h"

PSX::PSX(){
  begin();
}
void PSX::begin(){
  pinMode(VCC,OUTPUT);
  digitalWrite(VCC,HIGH);
  psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
}

int PSX::getInput(){
  return psx.read();
}
bool PSX::getAnyKey(){
  return (getInput()!=0);
}
