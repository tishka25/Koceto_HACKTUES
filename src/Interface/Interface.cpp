#include "Interface.h"

#define INTRWIDTH (WIDTH/2)-25
#define BLUE 10
#define YELLOW 250
#define WHITE 255
#define MENU_UP 1
#define MENU_DOWN -1



Interface::Interface(){
}

void Interface::begin()
{
  Interface::setBackground(BLUE);
  Interface::draw();
  Interface::select();
}
void Interface::setBackground(int color){
  VGA.fillRect(0,0,WIDTH,HEIGHT,color);
  VGA.setPaper(color);
}
void Interface::draw(){
  VGA.setInk(255);
  VGA.drawText("Games",INTRWIDTH,(HEIGHT/2)-50,WHITE);
  VGA.drawText("Map Editor",INTRWIDTH,HEIGHT/2,WHITE);
  VGA.drawText("About",INTRWIDTH,(HEIGHT/2)+50,WHITE);
}
void Interface::select(){
  switch(input.input()){
    case 'w':Interface::move(MENU_UP);break;
    case 's':Interface::move(MENU_DOWN);break;
    default: Interface::move(0);break;
  }
}
void Interface::move(int direction){
  menu_pos=menu_pos+direction;
  switch(menu_pos){
    case 1:
      Interface::draw();
      VGA.drawText("Games",INTRWIDTH,(HEIGHT/2)-50,YELLOW);
      break;
    case 2:
      Interface::draw();
      VGA.drawText("Map Editor",INTRWIDTH,HEIGHT/2,YELLOW);
      break;
    case 3:
      Interface::draw();
      VGA.drawText("About",INTRWIDTH,(HEIGHT/2)+50,YELLOW);
      break;
    default:
      menu_pos=1;
      break;
  }
}
