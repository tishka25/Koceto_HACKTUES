#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
#include <Interface/Interface.h>
#include <SchedulerARMAVR.h>

GameObject Player(tank_left,tank_left_palette);

Bullet b;
Input input(PS_CONTROLLER);

Interface interface;

MapEditor Map;
int cursor_x,cursor_y;
float bullet_x,bullet_y;

float x=100,y=100;

void setup() {
  Serial.begin(9600);
  input.begin();
  VGA.begin(320,240,VGA_COLOR);
  Player.setSpeed(1);

  b.setShooter(Player);

  //Interface
  interface.post();
  interface.bootScreen();

  //Interface
    interface.begin();
    VGA.clear();

  //Start the second thread
  Scheduler.startLoop(loop2);
  Scheduler.startLoop(loop3);
}


void loop() {
  //Map
  // Map.updateGrid(&cursor_x,&cursor_y);

  //Main Game
  Player.update();
  Player.setPosition(x, y);
  Player.draw();
  if(input.getInput()==psxX){
    b.shoot(Player);
  }
  // tankShoot();

  Map.drawMap_2d(MAP2);
  delay(1);
}

//Second thread for backgroung processing
void loop2(){
  tankMove();
  //Used to pass task to other tasks
  delay(1);
  yield();

}

void loop3(){
  b.loop(Player);
  yield();
}

void tankMove(){
  int buff_y;
  int buff_x;
    switch (input.getInput()) {
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
