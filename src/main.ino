#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
#include <Interface/Interface.h>
#include <SchedulerARMAVR.h>
// #include <DueOverclock.h>

GameObject Player(tank_left,tank_left_palette);
// Bullet b;
PSX psx;
Input input(PS_CONTROLLER);

Interface interface;

MapEditor Map;
int cursor_x;
int cursor_y;


void setup() {
  Serial.begin(9600);
  psx.begin();
  VGA.begin(320,240,VGA_COLOR);
  Player.setSpeed(1);
  // interface.post();
  // interface.bootScreen();
  // VGA.clear();
  //Start the second thread
  Scheduler.startLoop(loop2);

}
float x=100,y=100;

void loop() {
<<<<<<< HEAD
  //Map
  // Map.updateGrid(&cursor_x,&cursor_y);
=======

  //Interface
  // interface.begin();

  //Main Game


  //Interface
//   interface.begin();
  //map
//   Map.updateGrid();
  Map.updateGrid(&cursor_x,&cursor_y);
>>>>>>> 8b96f362729ef35d0e9fe870070f8b057a0221fa
//Interface
  // interface.begin();

  //Main Game
  Player.update();
  Player.setPosition(x, y);
  Player.draw();

  Map.drawMap_2d(MAP2);
  delay(5);
  yield();
}

//Second thread for backgroung processing
void loop2(){
  tankMove();
<<<<<<< HEAD
=======

>>>>>>> 8b96f362729ef35d0e9fe870070f8b057a0221fa
  //Used to pass task to other tasks
  yield();
  delay(5);
}


void tankMove(){
  int buff_y;
  int buff_x;

    switch (psx.getInput()) {
      case psxRight:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>((Player.getPositionX()/16)+1);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          x+=Player.getSpeed();
          Player.setSprite(tank_right,tank_right_palette);
          Player.setFacingSide(RIGHT);
        }
        break;
      case psxLeft:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          x-=Player.getSpeed();
          Player.setSprite(tank_left,tank_left_palette);
          Player.setFacingSide(LEFT);
      }
        break;

      case psxDown:
        buff_y=static_cast<int>((Player.getPositionY()/16)+1);
        buff_x=static_cast<int>((Player.getPositionX()/16));
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          y+=Player.getSpeed();

          Player.setSprite(tank_down,tank_down_palette);
          Player.setFacingSide(DOWN);
        }
        break;
      case psxUp:
        buff_y=static_cast<int>((Player.getPositionY()/16));
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          y-=Player.getSpeed();
          Player.setSprite(tank_up,tank_up_palette);
          Player.setFacingSide(UP);
        }
        break;
    }
}
