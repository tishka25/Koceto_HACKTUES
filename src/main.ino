#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
// #include <Interface/Interface.h>
#include <SchedulerARMAVR.h>
// #include <DueOverclock.h>

GameObject test(tank_left,tank_palette);
Bullet b;
PSX psx;

Draw t;

// Interface interface;

MapEditor Map;


void setup() {
  Serial.begin(9600);
  psx.begin();
  VGA.begin(320,240,VGA_COLOR);
  b.setSpeed(0.01f);

  // interface.post();

  // interface.bootScreen();

  //Start the second thread
  //Interface
  interface.begin();
  Scheduler.startLoop(loop2);
}
float x=100,y=100;

void loop() {
  //Interface
  // interface.begin();

  //Main Game



  test.setFacingSide(DOWN);
  test.setPosition(x, y);
  test.draw();
  test.update();
  // b.shoot(test);
  // b.worldDestroyer(MAP2);

  Map.drawMap_2d(MAP2);
  delay(5);
  yield();
}

// switch (dirInput) {
//   case UP: gameObject.setSprite(tankUp,tank_palette);break;
//   // ...etc //TODO
// }

//Second thread for backgroung processing
void loop2(){
  tankMove();
  //Used to pass task to other tasks
  yield();
  delay(5);
}


void tankMove(){
  if(!test.tileMapCollision(MAP2)){
    switch (psx.getInput()) {
      case psxRight:
        x+=test.getSpeed();
        break;
      case psxLeft:
        x-=test.getSpeed();
        break;
      case psxDown:
        y+=test.getSpeed();
        break;
      case psxUp:
        y-=test.getSpeed();
        break;
    }
  }
}
