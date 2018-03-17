#include "Interface.h"



Interface::Interface(){
}
void Interface::post(){
  Interface::setBackground(0);

  VGA.drawText("Initializing SD card...",0,0,255);
  if(!SD.begin(SD_PIN)){
    VGA.drawText("Initialization failed!",0,10,255);
  }
  else{
    VGA.drawText("Initialization done",0,10,255);
  }
  delay(1000);
}
void Interface::bootScreen(){
  // VGA.drawImage(); TODO Put Elsys logo here
  delay(1000);
}
void Interface::begin()
{
  Interface::setBackground(BLUE);
  Interface::draw();
  while(backToMenu){
    Interface::select();
  }
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
  switch(INPUT_METHOD){
    case MENU_KEY_UP:Interface::move(MENU_UP);break;
    case MENU_KEY_DOWN:Interface::move(MENU_DOWN);break;
    case MENU_KEY_SELECT:Interface::menuSelect(menu_pos);break;
    default: Interface::move(0);break;
  }
}
void Interface::move(int direction){
  menu_pos=menu_pos+direction;
  if(menu_pos_prev!=menu_pos){
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
    menu_pos_prev=menu_pos;
  }
}
void Interface::menuSelect(int item){
  switch(item){
    case 1:backToMenu=0;break; //TODO Start game
    case 2:backToMenu=0;break; //TODO Start Map Editor
    case 3:Interface::menuAbout();backToMenu=1;break;
    default:break;
  }
}
void Interface::menuAbout(){
  while(INPUT_METHOD!=MENU_KEY_SELECT){
    VGA.drawText("Hello,",0,0,255);
    VGA.drawText("We are the Fluffy bears team",0,10,255);
    VGA.drawText("This is our Arduino based project",0,20,255);
  }
}
