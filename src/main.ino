// #include <Bitmap/GameObject.h>
// #include <Bitmap/Bullet.h>
// #include <Interface/Interface.h>
// #include <SchedulerARMAVR.h>

#include "GameEngine.h"
#include <PS2Keyboard.h>

bool first=1;
bool enable=false;

GameObject Player(tank_left,tank_left_palette);
GameObject Enemy(tank_left,tank_left_palette);
Bullet bull;

Interface interface;

PS2Keyboard keyboard;
MapEditor Map;
float enemy_x,enemy_y;
float player_x,player_y;
int bullet_x,bullet_y;

int AIdir=1;

long t;
long shootTime;

void setup() {
  randomSeed(analogRead(A0));
  Serial.begin(9600);

  keyboard.begin(SHIELD_DATAPIN,SHIELD_IRQ);

  VGA.begin(320,240,VGA_COLOR);
  Enemy.setType(ENEMY);
  Player.setType(PLAYER);
  //Interface
  interface.post();
  interface.bootScreen();

  //Interface
    interface.begin();
    VGA.clear();

  Player.setPosition(20,20);
  Enemy.setPosition(270,200);
  Player.update();
  Serial.println("I am availbal");

  //Start the second thread
  Scheduler.startLoop(loop2);

}


void loop() {
  //Map
  // Map.updateGrid(&cursor_x,&cursor_y);

  //Main Game

  tankMove();
  enemyMove();

  if(millis()-t>=2000 || first==1){
    // VGA.clear();
    AIdir=random(1,5);
    t=millis();
    first=0;
  }

  // if(keyboard.available() && keyboard.read()=='f'){
  // }

  delay(1);
  yield();

}

//Second thread for backgroung processing
void loop2(){
  bull.loop(Player);
  // bull.loop(Enemy);
  Map.drawMap_1d(MAP);

  //Used to pass task to other threads
  delay(1);
  yield();

}

void tankMove(){
  switch(keyboard.read()){
    case 'd':Player.setFacingSide(RIGHT);Player.setSprite(tank_right,tank_right_palette);Player.move(RIGHT,1);break;
    case 'a':Player.setFacingSide(LEFT);Player.setSprite(tank_left,tank_left_palette);Player.move(LEFT,1);break;
    case 'w':Player.setFacingSide(UP);Player.setSprite(tank_up,tank_up_palette);Player.move(UP,1);break;
    case 's':Player.setFacingSide(DOWN);Player.setSprite(tank_down,tank_down_palette);Player.move(DOWN,1);break;
    case PS2_ENTER:bull.shoot(Player);break;
  }

}


void enemyMove(){
  switch (AIdir) {
    case RIGHT:Enemy.setFacingSide(RIGHT);Enemy.setSprite(tank_right,tank_right_palette);Enemy.move(RIGHT,1);break;
    case LEFT:Enemy.setFacingSide(LEFT);Enemy.setSprite(tank_left,tank_left_palette);Enemy.move(LEFT,1);break;
    case UP:Enemy.setFacingSide(UP);Enemy.setSprite(tank_up,tank_up_palette);Enemy.move(UP,1);break;
    case DOWN:Enemy.setFacingSide(DOWN);Enemy.setSprite(tank_down,tank_down_palette);Enemy.move(DOWN,1);break;
  }
}
