#include "GameObject.h"


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



void GameObject::update(){
  outOfScreen();
  VGA.drawRect(x-1,y-1,x+getWidth()+1,y+getHeight()+1,Map.getBackgroundColor());
  draw();
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

void GameObject::move(int dir, float speed){
  // speed/=100;
  int buff_x,buff_y;
  switch (dir) {
    case RIGHT:
    buff_y=static_cast<int>((getPositionY())/16);
    buff_x=static_cast<int>((getPositionX()/16)+1);
    if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
      x+=speed;}break;
    case LEFT:
    buff_y=static_cast<int>((getPositionY())/16);
    buff_x=static_cast<int>(getPositionX()/16);
    if(!(MAP2[buff_y+1][buff_x]!=0 || MAP2[buff_y][buff_x]!=0)){
      x-=speed;}break;
    case UP:
    buff_y=static_cast<int>((getPositionY()/16));
    buff_x=static_cast<int>(getPositionX()/16);
    if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
      y-=speed;}break;
    case DOWN:
    buff_y=static_cast<int>((getPositionY()/16)+1);
    buff_x=static_cast<int>((getPositionX()/16));
    if(!(MAP2[buff_y][buff_x+1]!=0 || MAP2[buff_y][buff_x]!=0)){
      y+=speed;}break;
    default: ;break;
  }
  update();
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
int GameObject::getFrames(){
  return bitmap.getFrameCount(sprite);
}
void GameObject::setFacingSide(int side){
  this->side=side;
}

int GameObject::getDirection(){return dir;}
void GameObject::setDirection(int dir){this->dir=dir;}

bool GameObject::collision(GameObject _object1,GameObject _object2){
  return   !(_object2.getPositionX()>=_object1.getPositionX()+_object1.getWidth() ||
            _object2.getPositionX()+_object2.getWidth()<=_object1.getPositionX()  ||
            _object2.getPositionY()>=_object1.getPositionY()+_object1.getHeight()  ||
            _object2.getPositionY()+_object2.getHeight()<=_object1.getPositionY());
}

bool GameObject::tileMapCollision(unsigned int Map[][20]){
  int x=getPositionX()/16,y=getPositionY()/16;
    return (Map[y][x]!=0  ||
            Map[y][x+1]!=0 ||
            Map[y+1][x]!=0);
}

// bool GameObject::tileMapCollision(){
//   int buff_x=getPositionX()/16,buff_y=getPositionY()/16;
//   int buff_pos=(buff_y*Map.getWidth())+buff_x;
//   unsigned int *buff_map=Map.getMap();
//   return (buff_map[buff_pos]!=0);
// }
void GameObject::gravitationalPull(GameObject _object1,GameObject _object2){
  if(!collision(_object1, _object2)){
    float step=0;
    while(step<=10){
      step+=0.1;
      setPosition(x,y+step);
    }
  }
}
