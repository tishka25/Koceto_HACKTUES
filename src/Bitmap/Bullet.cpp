#include "Bullet.h"
#include <Arduino.h>


extern GameObject Player;
extern GameObject Enemy;
extern GameObject bull;
extern int bullet_x,bullet_y;
extern float enemy_x,enemy_y;
extern float player_x,player_y;
extern bool enable;

long t1;


Bullet::Bullet(){
  setSprite(bullet,bullet_palette);
}

Bullet::Bullet(GameObject gameObject){
  this->gameObject=gameObject;
}

GameObject Bullet::getShooter(){
  return gameObject;
}
void Bullet::setShooter(GameObject gameObject){
  this->gameObject=gameObject;
}

int Bullet::getColor(){
  return color;
}
void Bullet::setColor(int color){
  this->color=color;
}

float Bullet::getSpeed(){
  return speed;
}
void Bullet::setSpeed(float speed){
  this->speed=speed;
}

bool Bullet::tileMapCollision(unsigned int Map[][20]){
  int x16=getPositionX()/16,y16=getPositionY()/16;

    return (Map[y16][x16]!=0);
}

long Bullet::getReloadTime(){
  return reloadTime;
}
void Bullet::setReloadTime(long reloadTime){
  this->reloadTime=reloadTime;
}
void Bullet::destroy(){

}

bool Bullet::collision(){
  int width=16;
  return !(bullet_x>=enemy_x+width ||
          bullet_x+2<=enemy_x  ||
          bullet_y>=enemy_y+width  ||
          bullet_y+2<=enemy_y );
}

void Bullet::shoot(GameObject gameObject){
  bool first=1;
  if(millis()-t1>=500||first==1)
      // bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
      // bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      enable=true;
      t1=millis();
      first=0;
  }

void Bullet::loop(GameObject gameObject){
  if(enable){
  int _side=gameObject.getFacingSide();
  switch (_side) {
    case LEFT :
    bullet_x=gameObject.getPositionX()-5;
    bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      while (!(MAP2[bullet_y/16][bullet_x/16])
         && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();delayMicroseconds(800);}
         if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());
          SPAWN_POSITION3  Enemy.draw();}
        break;
    case RIGHT:
    bullet_x=gameObject.getPositionX()+(gameObject.getWidth());
    bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      while (!(MAP2[bullet_y/16][bullet_x/16])
        && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();delayMicroseconds(800);}
        if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());
          SPAWN_POSITION2  Enemy.draw();}
        break;
    case UP:
    bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
    bullet_y=gameObject.getPositionY()-5;
        while (!(MAP2[bullet_y/16][bullet_x/16])
          && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();delayMicroseconds(800);}
          if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());
          SPAWN_POSITION3  Enemy.draw();}
        break;
    case DOWN:
    bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
    bullet_y=(gameObject.getPositionY())+(gameObject.getHeight());
        while (!(MAP2[bullet_y/16][bullet_x/16])
          && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();delayMicroseconds(800);}
          if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());
            SPAWN_POSITION1 Enemy.draw();}
        break;
  }
  enable=false;
}
}
