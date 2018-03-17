#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
// #include <Interface/Interface.h>
#include <SchedulerARMAVR.h>
// #include <DueOverclock.h>

GameObject Player;
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
  Scheduler.startLoop(loop2);
}
float x=100,y=100;

void loop() {
  //Interface
  // interface.begin();

  //Main Game


  Player.update();
  Player.setPosition(x, y);
  Player.draw();

  // b.shoot(Player);
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
  if(!Player.tileMapCollision(MAP2)){
    switch (psx.getInput()) {
      case psxRight:
        Player.setSprite(tank_right,tank_right_palette);
        Player.setFacingSide(RIGHT);

        x+=Player.getSpeed();
        break;
      case psxLeft:
        Player.setSprite(tank_left,tank_left_palette);
        Player.setFacingSide(LEFT);

        x-=Player.getSpeed();
        break;
      case psxDown:
        Player.setSprite(tank_down,tank_down_palette);
        Player.setFacingSide(DOWN);

        y+=Player.getSpeed();
        break;
      case psxUp:
        Player.setSprite(tank_up,tank_up_palette);
        Player.setFacingSide(UP);

        y-=Player.getSpeed();
        break;
    }
  }
}
