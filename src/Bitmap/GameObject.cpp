#include "GameObject.h"


extern GameObject OnScreen[];
extern MapEditor Map;
int curr_object1=0;
int curr_object2=0;



GameObject::GameObject(){}
GameObject::GameObject(unsigned char *sprite,unsigned char *sprite_palette){
  this->sprite=sprite;
  this->sprite_palette=sprite_palette;
}
GameObject::GameObject(unsigned char *sprite,unsigned char *sprite_palette,int x, int y){
  this->sprite=sprite;
  this->sprite_palette=sprite_palette;
  this->x=x;
  this->y=y;
}

// void GameObject::internalLoop(GameObject *_OnScreen){
// }
//
// //TODO
// void GameObject::internalLoop(){
//   if(collision(OnScreen[curr_object1],OnScreen[curr_object2]) &&
//      OnScreen[curr_object1].getType()==DESTROYER){
//
//      }
// }

void GameObject::update(){
  if(x_prev!=x){
    //Movement LEFT
    if(x<x_prev){VGA.fillRect(x_prev+getWidth(),y_prev,x_prev+getWidth(),y_prev+getHeight(),Map.getBackgroundColor());}
    //Movement RIGHT
    else {VGA.fillRect(x_prev,y_prev,x_prev-1,y_prev+getHeight(),Map.getBackgroundColor());}
  }
  else if(y_prev!=y){
    //Movement DOWN
    if(y<y_prev){VGA.fillRect(x_prev,y_prev+getHeight(),x_prev+getWidth(),y_prev+getHeight()-1,Map.getBackgroundColor());}
    //Mevement UP
    else {VGA.fillRect(x_prev,y_prev,x_prev+getWidth(),y_prev,Map.getBackgroundColor());}
  }
  //If it is enabled it gets respawned to the other side
  outOfScreen();
  x_prev=getPositionX(); y_prev=getPositionY();
}

void GameObject::outOfScreen(){
  // if(getRespawnOutOfScreen()){
    if(getPositionX()>WIDTH){
      setPosition(0,getPositionY());
    }
    else if(getPositionX()<0){
      setPosition(WIDTH-getWidth(),getPositionY());
    }
    else if(getPositionY()>HEIGHT){
      setPosition(getPositionX(),0);
    }
    else if(getPositionY()<0){
      setPosition(getPositionX(),HEIGHT-getHeight());
    }
  // }
  // else {
  //   //TODO
  // }
}

void GameObject::drawImage(unsigned char *sprite){
  bitmap.drawImage(sprite,sprite[0],sprite[1],x,y);
}
void GameObject::draw(){
  bitmap.drawSprite(sprite,sprite_palette,0,x,y);
}
void GameObject::drawAtPosition(int x,int y){
  setPosition(x,y);
  draw();
  // bitmap.drawSprite(sprite,sprite_palette,0,x,y);
}
float GameObject::getPositionX(){
  return x;
}
float GameObject::getPositionY(){
  return y;
}
void GameObject::setRespawnOutOfScreen(bool enable){
  this->enable=enable;
}
void GameObject::setPosition(float x, float y){
  this->x=x;
  this->y=y;
}
bool GameObject::getRespawnOutOfScreen(){
  return enable;
}
void GameObject::setGravity(int _gravity){
  gravity=_gravity;
}
void GameObject::setSprite(unsigned char *_sprite,unsigned char *_sprite_palette){
  sprite=_sprite;
  sprite_palette=_sprite_palette;
}
void GameObject::setType(int _type){
  type=_type;
}
void GameObject::setEnabled(bool enable){
  visible=enable;
}
void GameObject::setSpeed(float speed){
  this->speed=speed;
}
float GameObject::getSpeed(){
  return speed;
}
int GameObject::getWidth(){
  return sprite[SPRITE_WIDTH];
}
int GameObject::getHeight(){
  return sprite[SPRITE_HEIGHT];
}
int GameObject::getType(){
  return type;
}
bool GameObject::getEnabled(){
  return visible;
}

int GameObject::getFacingSide(){
  return side;
}
void GameObject::setFacingSide(int side){
  //TODO rotation of the sprite
  this->side=side;
}

bool GameObject::collision(GameObject _object1,GameObject _object2){
  return   !(_object2.getPositionX()>=_object1.getPositionX()+_object1.getWidth() ||
            _object2.getPositionX()+_object2.getWidth()<=_object1.getPositionX()  ||
            _object2.getPositionY()>=_object1.getPositionY()+_object1.getHeight()  ||
            _object2.getPositionY()+_object2.getHeight()<=_object1.getPositionY());
}

bool GameObject::tileMapCollision(unsigned int Map[][20]){
  int x=getPositionX()/16,y=getPositionY()/16;

    return (Map[y][x]!=0 ||
            Map[y][x+1]!=0 ||
            Map[y+1][x]!=0);

}
void GameObject::gravitationalPull(GameObject _object1,GameObject _object2){
  if(!collision(_object1, _object2)){
    float step=0;
    while(step<=10){
      step+=0.1;
      setPosition(x,y+step);
    }
  }
}
