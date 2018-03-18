#include "Bullet.h"
#include <Arduino.h>

extern int bullet_x,bullet_y;


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
// void Bullet::loop(GameObject gameObject){
//   int buff_y;
//   int buff_x;
//   if(enable){
//     Serial.println("SHOOT");
//     int _side=gameObject.getFacingSide();
//       switch (_side) {
//         case LEFT :
//         buff_y=static_cast<int>((getPositionY())/16);
//         buff_x=static_cast<int>(getPositionX()/16);
//         if(!(MAP2[buff_y+1][buff_x]==0 || MAP2[buff_y][buff_x]==0)){
//           drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();
//         }
//           break;
//         case RIGHT:
//         buff_y=static_cast<int>((getPositionY())/16);
//         buff_x=static_cast<int>((getPositionX()/16)+1);
//         if(!(MAP2[buff_y+1][buff_x]==0 || MAP2[buff_y][buff_x]==0)){
//           drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();
//         }
//           break;
//         case UP:
//         buff_y=static_cast<int>((getPositionY()/16));
//         buff_x=static_cast<int>(getPositionX()/16);
//         if(!(MAP2[buff_y][buff_x+1]==0 || MAP2[buff_y][buff_x]==0)){
//           drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();
//         }
//           break;
//         case DOWN:
//         buff_y=static_cast<int>((getPositionY()/16)+1);
//         buff_x=static_cast<int>((getPositionX()/16));
//         if(!(MAP2[buff_y][buff_x+1]==0 || MAP2[buff_y][buff_x]==0)){
//           drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();
//         }
//           break;
//     }
//   }
//
// }
void Bullet::destroy(){

}

void Bullet::shoot(GameObject gameObject){
      bullet_x=gameObject.getPositionX()+(gameObject.getWidth()/2);
      bullet_y=(gameObject.getPositionY())+(gameObject.getHeight()/2);
      enable=true;
  }

void Bullet::loop(GameObject gameObject){
  if(enable){
  int _side=gameObject.getFacingSide();
  switch (_side) {
    case LEFT :
      while (!MAP2[bullet_y/16][bullet_x/16]) {
        drawAtPosition(bullet_x,bullet_y);bullet_x-=getSpeed();update();delayMicroseconds(800);}
        if(MAP2[bullet_y/16][bullet_x/16]==BRICKS_DESTRUCTIVE){MAP2[bullet_y/16][bullet_x/16]=0;}
        break;
    case RIGHT:
      while (!MAP2[bullet_y/16][bullet_x/16]) {drawAtPosition(bullet_x,bullet_y);bullet_x+=getSpeed();update();delayMicroseconds(800);}
        break;
    case UP:
        while (!MAP2[bullet_y/16][bullet_x/16]) {drawAtPosition(bullet_x,bullet_y);bullet_y-=getSpeed();update();delayMicroseconds(800);}
        break;
    case DOWN:
        while (!MAP2[bullet_y/16][bullet_x/16]) {drawAtPosition(bullet_x,bullet_y);bullet_y+=getSpeed();update();delayMicroseconds(800);}
        break;
  }
  enable=false;
}
}
