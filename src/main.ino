#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
#include <Interface/Interface.h>
#include <SchedulerARMAVR.h>
// #include <DueOverclock.h>

GameObject test(tank_left,tank_palette);
Bullet b;

Draw t;

Converter con;

Interface interface;

Keyboard input(10,8);
MapEditor Map;


void setup() {
  Serial.begin(9600);
  input.begin();
  VGA.begin(320,240,VGA_COLOR);
  b.setSpeed(0.01f);
  interface.begin();
  //Start the second thread
  Scheduler.startLoop(loop2);
}
int x=100,y=100;
int x1=300;
void loop() {
  if(!test.tileMapCollision(MAP2)){
    y--;
  }

  test.setPosition(x,y);
  test.setFacingSide(DOWN);
  test.draw();
  test.update();
  // b.shoot(test);
  // b.worldDestroyer(MAP2);


  Map.drawMap_2d(MAP2);
  delay(10);
  // con.flipSprite(tank, tank_CW, CW);
  // t.drawImage(tank_CW,16,16,100,100);
  VGA.waitSync();
}
// switch (dirInput) {
//   case UP: gameObject.setSprite(tankUp,tank_palette);break;
//   // ...etc //TODO
// }

//Second thread for backgroung processing
void loop2(){
  yield();
  delay(10);
}
