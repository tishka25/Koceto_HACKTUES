#include "Bullet.h"
#include <Arduino.h>

extern float bullet_x,bullet_y;


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
void Bullet::loop(GameObject gameObject){
  if(enable || !tileMapCollision(MAP2)){
    int _side=gameObject.getFacingSide();
      switch (_side) {
        case LEFT :
          drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();
          break;
        case RIGHT:
          drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();
          break;
        case UP:
          drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();
          break;
        case DOWN:
          drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();
          break;
    }
  }
}

void Bullet::shoot(GameObject gameObject){
      bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
      bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      enable=true;
  }


// void Bullet::shoot(GameObject gameObject){
//   int _side=gameObject.getFacingSide();
//   int width=1;
//   switch (_side) {
//     case LEFT :
//       bullet_x=gameObject.getPositionX()-2;
//       bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2-1);
//       drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();
//         break;
//     case RIGHT:
//       bullet_x=gameObject.getPositionX()+gameObject.getWidth();
//       bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2-1);
//         drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();
//         break;
//     case UP:
//       bullet_x=gameObject.getPositionX()+gameObject.getWidth()/2;
//       bullet_y=gameObject.getPositionY()-2;
//         drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();
//         break;
//     case DOWN:
//       bullet_x=gameObject.getPositionX()+gameObject.getWidth()/2;
//       bullet_y=gameObject.getPositionY()+gameObject.getHeight();
//       drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();
//         break;
//   }
//
// }
