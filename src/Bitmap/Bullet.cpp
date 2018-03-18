#include "Bullet.h"
#include <Arduino.h>


extern GameObject Player;
extern GameObject Enemy;
extern GameObject bull;
extern int bullet_x,bullet_y;
extern float enemy_x,enemy_y;
extern float player_x,player_y;



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
  // long t =millis();
  // if(millis()-t>=100)
      bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
      bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      enable=true;
      // t=millis();
  }

void Bullet::loop(GameObject gameObject){
  if(enable){
  int _side=gameObject.getFacingSide();
  switch (_side) {
    case LEFT :
      while (!(MAP2[bullet_y/16][bullet_x/16])
         && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();delayMicroseconds(800);}
         if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());}
        break;
    case RIGHT:
      while (!(MAP2[bullet_y/16][bullet_x/16])
        && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();delayMicroseconds(800);}
        if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());}
        break;
    case UP:
        while (!(MAP2[bullet_y/16][bullet_x/16])
          && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();delayMicroseconds(800);}
          if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());}
        break;
    case DOWN:
        while (!(MAP2[bullet_y/16][bullet_x/16])
          && !collision()) {drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();delayMicroseconds(800);}
          if(collision()){Enemy.setSprite(bullet,bullet_palette);VGA.fillRect(enemy_x,enemy_y,enemy_x+16,enemy_y+16,Map.getBackgroundColor());}
        break;
  }
  enable=false;
}
}
