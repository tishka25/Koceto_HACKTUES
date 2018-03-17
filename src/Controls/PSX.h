#include <Psx.h>
#include <Arduino.h>

#ifndef PSX_H
#define PSX_H

#define dataPin 12
#define cmndPin 11
#define attPin 10
#define clockPin 9

#define VCC 13

class PSX{
public:
  Psx psx;
  PSX();
  void begin();

  int getInput();
  bool getAnyKey();
};

#endif
