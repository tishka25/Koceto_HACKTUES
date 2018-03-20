#include <Bitmap/GameObject.h>
#include <Bitmap/Bullet.h>
#include <Interface/Interface.h>
#include <SchedulerARMAVR.h>

GameObject Player(tank_left,tank_left_palette);
GameObject Enemy(tank_left,tank_left_palette);
Bullet bull;
Input input(KEYBOARD);

Interface interface;
MapEditor Map;

int cursor_x,cursor_y;
int bullet_x=0;
int bullet_y=0;

float player_x=280,player_y=SPAWN_POSITION;
float enemy_x=SPAWN_POSITION,enemy_y=SPAWN_POSITION;

int AIdir=1;
int PlayerDir=2;


long t;
long shootTime;

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
    // interface.begin();
    VGA.clear();

  //Start the second thread
  Scheduler.startLoop(loop2);

}
bool first=1;

void loop() {
  //Map
  // Map.updateGrid(&cursor_x,&cursor_y);

  //Main Game

  if(input.getInput()==psxX){
    bull.shoot(Player);
  }

  Map.drawMap_2d(MAP2);
  gameObjectMove();


  if(millis()-t>=2000 || first==1){
    // VGA.clear();
    AIdir=random(1,5);
    PlayerDir=random(1,5);

    t=millis();
    first=0;
  }
  if(millis()-shootTime>=10000 || first){
    bull.shoot(Player);
    first=0;
  }

  delay(1);
}

//Second thread for backgroung processing
void loop2(){
  bull.loop(Player);
  bull.loop(Enemy);
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

    switch (PlayerDir) {
    // switch (input.getInput()) {
      // case psxRight:
        case RIGHT:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>((Player.getPositionX()/16)+1);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_x+=Player.getSpeed();
          Player.setSprite(tank_right,tank_right_palette);
          Player.setFacingSide(RIGHT);
        }
        else{
          PlayerDir=random(1,5);
        }
        break;
      // case psxLeft:
        case LEFT:
        buff_y=static_cast<int>((Player.getPositionY())/16);
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_x-=Player.getSpeed();
          Player.setSprite(tank_left,tank_left_palette);
          Player.setFacingSide(LEFT);
      }
      else{
        PlayerDir=random(1,5);
      }
        break;
      // case psxDown:
        case DOWN:
        buff_y=static_cast<int>((Player.getPositionY()/16)+1);
        buff_x=static_cast<int>((Player.getPositionX()/16));
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_y+=Player.getSpeed();
          Player.setSprite(tank_down,tank_down_palette);
          Player.setFacingSide(DOWN);
        }
        else{
          PlayerDir=random(1,5);
        }
        break;
      // case psxUp:
        case UP:
        buff_y=static_cast<int>((Player.getPositionY()/16));
        buff_x=static_cast<int>(Player.getPositionX()/16);
        if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
          player_y-=Player.getSpeed();
          Player.setSprite(tank_up,tank_up_palette);
          Player.setFacingSide(UP);
        }
        else{
          PlayerDir=random(1,5);
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
        else{
          AIdir=random(1,5);
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
      else{
        AIdir=random(1,5);
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
        else{
          AIdir=random(1,5);
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
        else{
          AIdir=random(1,5);
        }
        break;
    }
  }
