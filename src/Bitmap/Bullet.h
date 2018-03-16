#include <Bitmap/GameObject.h>
#include <MapEditor/Sprites.h>

#ifndef BULLET_H
#define BULLET_H


class Bullet:GameObject
{
public:
  GameObject gameObject;
  float speed=0.01f;
  int color=255;
  Bullet();
  Bullet(GameObject gameObject);

  int getColor();
  void setColor(int color);

  float getSpeed();
  void setSpeed(float speed);

  GameObject getShooter();
  void setShooter(GameObject gameObject);

  bool tileMapCollision(unsigned int Map[][20]);


  void shoot(GameObject gameObject);

};

#endif