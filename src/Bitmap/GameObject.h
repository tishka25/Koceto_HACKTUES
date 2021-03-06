#ifndef GameObject_H
#define GameObject_H

#include "Draw.h"
#include <VGA.h>
#include <Controls/PSX.h>
#include <MapEditor/Sprites.h>
#include <MapEditor/MapEditor.h>
// #include <Controls/Keyboard.h>
#include <SDcard/Converter.h>
// #include <SDCard.h>

#define LEFT  1
#define RIGHT 2
#define UP    3
#define DOWN  4


#define X 0
#define Y 1

#define PLAYER 2
#define ENEMY 3
#define PLATFORM 3
#define DESTRUCTABLE 4
#define DESTROYER 5
//#define etc...

#define SPRITE_WIDTH 0
#define SPRITE_HEIGHT 1

#define BUFFER 20

#define SPAWN_POSITION  33
#define SPAWN_POSITION1  Enemy.setPosition(33,33);
#define SPAWN_POSITION2  Enemy.setPosition(33,200);
#define SPAWN_POSITION3  Enemy.setPosition(270,200);

class GameObject{
public:
    Draw bitmap;
   unsigned char *sprite;
   unsigned char *sprite_palette;
   int type;
   int side=0;
   float x,y;
   float x_prev,y_prev;
   float speed=1;
   int gravity;
   bool enable=false;
   bool visible=false;
   int dir=0;

  GameObject();
  GameObject(unsigned char *sprite,unsigned char *sprite_palette);
  GameObject(unsigned char *sprite,unsigned char *sprite_palette,int x , int y);

  //Physics of the gameGameObjects
  void setGravity(int _gravity);
  void draw();
  void drawAtPosition(int x , int y);
  void drawImage(unsigned char *sprite);

  void update();
  void outOfScreen();
  void internalLoop(GameObject *_OnScreen);
  void internalLoop();

  void setPosition(float x , float y);
  void setEnabled(bool enable);
  void setType(int _type);
  void setSpeed(float speed);
  void setRespawnOutOfScreen(bool enable);
  bool getRespawnOutOfScreen();
  float getSpeed();
  float getPositionX();
  float getPositionY();
  int getType();
  bool getEnabled();
  void setSprite(unsigned char _sprite[],unsigned char _sprite_palette[]);
  int getWidth();
  int getHeight();
  int getFrames();
  int getFacingSide();
  void setFacingSide(int side);

  int getDirection();
  void setDirection(int dir);

  void move(int dir, float speed);

// private:
  void gravitationalPull(GameObject _object1,GameObject _object2);
  static bool collision(GameObject _object1,GameObject _object2);

  bool tileMapCollision(unsigned int Map[][20]);
  // bool tileMapCollision();

};
extern GameObject *physics;
extern MapEditor Map;


#endif
