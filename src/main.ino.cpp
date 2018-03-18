# 1 "/var/folders/t1/87z234gj5sqgsq5zhpbkfvlr0000gn/T/tmplZdAqH"
#include <Arduino.h>
# 1 "/Users/teodorstanishev/Documents/PlatformIO/Projects/HackTues30X/src/main.ino"
#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
#include <Interface/Interface.h>
#include <SchedulerARMAVR.h>

GameObject Player(tank_left,tank_left_palette);
GameObject Enemy(tank_left,tank_left_palette);
Bullet bull;
Input input(PS_CONTROLLER);
Interface interface;
MapEditor Map;

int cursor_x,cursor_y;
int bullet_x=0;
int bullet_y=0;

float player_x=100,player_y=100;
void setup();
void loop();
void loop2();
void gameObjectMove();
void tankMove();
#line 20 "/Users/teodorstanishev/Documents/PlatformIO/Projects/HackTues30X/src/main.ino"
void setup() {
  Serial.begin(9600);
  input.begin();
  VGA.begin(320,240,VGA_COLOR);


  interface.post();
  interface.bootScreen();


    interface.begin();
    VGA.clear();


  Scheduler.startLoop(loop2);

}


void loop() {




  gameObjectMove();

  if(input.getInput()==psxX){
    bull.shoot(Player);
  }

  Map.drawMap_2d(MAP2);
  delay(1);
}


void loop2(){
  bull.loop(Player);

  delay(1);
  yield();

}


void gameObjectMove(){
  Player.update();
  Player.setPosition(player_x, player_y);
  Player.draw();
  tankMove();
  Enemy.update();
  Enemy.setPosition(100, 150);
  Enemy.draw();
}

void tankMove(){
  int buff_y;
  int buff_x;
    switch (input.getInput()) {
      case psxRight:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>((Player.getPositionX()/16)+1);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_x+=Player.getSpeed();
          Player.setSprite(tank_right,tank_right_palette);
          Player.setFacingSide(RIGHT);
        }
        break;
      case psxLeft:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_x-=Player.getSpeed();
          Player.setSprite(tank_left,tank_left_palette);
          Player.setFacingSide(LEFT);
      }
        break;
      case psxDown:
        buff_y=static_cast<int>((Player.getPositionY()/16)+1);
        buff_x=static_cast<int>((Player.getPositionX()/16));
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_y+=Player.getSpeed();
          Player.setSprite(tank_down,tank_down_palette);
          Player.setFacingSide(DOWN);
        }
        break;
      case psxUp:
        buff_y=static_cast<int>((Player.getPositionY()/16));
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_y-=Player.getSpeed();
          Player.setSprite(tank_up,tank_up_palette);
          Player.setFacingSide(UP);
        }
        break;
    }
}