#include "Bullet.h"
#include <Arduino.h>

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

    return (Map[y16][x16]!=0 ||
            Map[y16][x16+1]!=0 ||
            Map[y16+1][x16]!=0);

}
void Bullet::worldDestroyer(unsigned int Map[][20]){
  if(tileMapCollision(Map)){
    Map[y16][x16]=0;
  }
}

void Bullet::shoot(GameObject gameObject){
  int _side=gameObject.getFacingSide();
  float x;  float y;
  int width=1;
  switch (_side) {
    case LEFT :
      x=gameObject.getPositionX()-2;
      y=(gameObject.getPositionY())+(gameObject.getHeight()/2-1);
      while(x>0) {drawAtPosition(x,y);x-=getSpeed();update();}
        break;
    case RIGHT:
      x=gameObject.getPositionX()+gameObject.getWidth();
      y=(gameObject.getPositionY())+(gameObject.getHeight()/2-1);
      while(x<WIDTH) {drawAtPosition(x,y);x+=getSpeed();update();}
        break;
    case UP:
      x=gameObject.getPositionX()+gameObject.getWidth()/2;
      y=gameObject.getPositionY()-2;
      while(y>0)  {drawAtPosition(x,y);y-=getSpeed();update();}
        break;
    case DOWN:
      x=gameObject.getPositionX()+gameObject.getWidth()/2;
      y=gameObject.getPositionY()+gameObject.getHeight();
      while(y<HEIGHT)  {worldDestroyer(MAP2);drawAtPosition(x,y);y+=getSpeed();update();}
        break;
  }

}
