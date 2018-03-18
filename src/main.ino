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
float enemy_x=100,enemy_y=160;

int AIdir=0;


long t;

void setup() {
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  input.begin();
  VGA.begin(320,240,VGA_COLOR);
  Enemy.setType(ENEMY);
  Player.setType(PLAYER);
  //Interface
  interface.post();
  interface.bootScreen();

  //Interface
    interface.begin();
    VGA.clear();

  //Start the second thread
  Scheduler.startLoop(loop2);

}


void loop() {
  t=millis();
  //Map
  // Map.updateGrid(&cursor_x,&cursor_y);

  //Main Game

  if(input.getInput()==psxX){
    bull.shoot(Player);
  }

  Map.drawMap_2d(MAP2);
  gameObjectMove();


  // if(millis()-t>=1000){
    // VGA.clear();
    AIdir=random(1,4);
    // t=millis();
  // }

  delay(1);
}

//Second thread for backgroung processing
void loop2(){
  bull.loop(Player);
  //Used to pass task to other tasks
  delay(1);
  yield();

}


void gameObjectMove(){
  Player.update();
  Player.setPosition(player_x, player_y);
  Player.draw();
  tankMove();
  Enemy.update();
  Enemy.setPosition(enemy_x, enemy_y);
  Enemy.draw();
  enemyMove();
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


void enemyMove(){
  int buff_y;
  int buff_x;

    switch (AIdir) {
      case RIGHT:
        buff_y=static_cast<int>((Enemy.getPositionY())/16);
        buff_x=static_cast<int>((Enemy.getPositionX()/16)+1);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          enemy_x+=Enemy.getSpeed();
          Enemy.setSprite(tank_right,tank_right_palette);
          Enemy.setFacingSide(RIGHT);
        }
        break;
      case LEFT:
        buff_y=static_cast<int>((Enemy.getPositionY())/16);
        buff_x=static_cast<int>(Enemy.getPositionX()/16);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          enemy_x-=Enemy.getSpeed();
          Enemy.setSprite(tank_left,tank_left_palette);
          Enemy.setFacingSide(LEFT);
      }
        break;
      case DOWN:
        buff_y=static_cast<int>((Enemy.getPositionY()/16)+1);
        buff_x=static_cast<int>((Enemy.getPositionX()/16));
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          enemy_y+=Enemy.getSpeed();
          Enemy.setSprite(tank_down,tank_down_palette);
          Enemy.setFacingSide(DOWN);
        }
        break;
      case UP:
        buff_y=static_cast<int>((Enemy.getPositionY()/16));
        buff_x=static_cast<int>(Enemy.getPositionX()/16);
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          enemy_y-=Enemy.getSpeed();
          Enemy.setSprite(tank_up,tank_up_palette);
          Enemy.setFacingSide(UP);
        }
        break;
    }
}
