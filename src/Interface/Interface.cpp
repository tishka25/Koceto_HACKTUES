#include "Interface.h"



Interface::Interface(){
}
int Interface::post(){
  Interface::setBackground(0);

  VGA.drawText("Initializing SD card...",0,0,255);
  if(!SD.begin(1)){
    VGA.drawText("Initialization failed!",0,10,255);
    return 0;
  }
  else{
    VGA.drawText("Initialization done",0,10,255);
    return 1;
  }
  delay(1000);
  VGA.clear();
}
void Interface::bootScreen(){
  // VGA.drawImage(); TODO Put Elsys logo here

  delay(1000);
}
void Interface::begin()
{

  Interface::setBackground(BLUE);
  Interface::draw();
  while(!playGame){
    Interface::select();
  }
}
void Interface::setBackground(int color){
  VGA.fillRect(0,0,WIDTH,HEIGHT,color);
  VGA.setPaper(color);
}
void Interface::draw(){
  VGA.setInk(255);
  VGA.drawText("Game",INTRWIDTH,(HEIGHT/2)-50,WHITE);
  VGA.drawText("Elsys30",INTRWIDTH,HEIGHT/2,WHITE);
  VGA.drawText("About",INTRWIDTH,(HEIGHT/2)+50,WHITE);
}
void Interface::select(){
  switch(input.getInput()){
    case MENU_KEY_UP:Interface::move(MENU_UP);break;
    case MENU_KEY_DOWN:Interface::move(MENU_DOWN);break;
    case MENU_KEY_SELECT:Interface::menuSelect(menu_pos);break;
    default: Interface::move(0);break;
  }
  delay(200);
}
void Interface::move(int direction){
  menu_pos=menu_pos+direction;
  if(menu_pos_prev!=menu_pos){
    if(menu_pos>3)menu_pos=3;
    if(menu_pos<1)menu_pos=1;
    switch(menu_pos){
      case 1:
        Interface::draw();
        VGA.drawText("Game",INTRWIDTH,(HEIGHT/2)-50,RED);
        break;
      case 2:
        Interface::draw();
        VGA.drawText("Elsys30",INTRWIDTH,HEIGHT/2,RED);
        break;
      case 3:
        Interface::draw();
        VGA.drawText("About",INTRWIDTH,(HEIGHT/2)+50,RED);
        break;
      default:
        break;
    }
    menu_pos_prev=menu_pos;
  }
}
void Interface::menuSelect(int item){
  VGA.clear();
  switch(item){
    case 1:playGame=1;break; //TODO Start game
    case 2:Interface::playMusic("elsys.wav");Interface::begin(); //TODO Start Map Editor
    case 3:Interface::menuAbout();Interface::begin();
    default:Interface::begin();
  }
}
void Interface::menuAbout(){
  // VGA.clear();
  delay(200);
  while(input.getInput()!=MENU_KEY_SELECT){
    VGA.drawText("Hello,",0,0,255);
    VGA.drawText("We are the Fluffy bears team",0,10,255);
    VGA.drawText("This is our Arduino based project",0,20,255);
  }
  delay(200);
  return Interface::begin();
}
void Interface::playMusic(char *songName){
  if(Interface::post()){
    Audio.begin(88200, 100);
    File myFile = SD.open(songName);
    if (!myFile) {
      Serial.println("error opening test.wav");
      return Interface::begin();
    }
    const int S = 1024;
    short buffer[S];
    Serial.print("Playing");
    while (myFile.available()) {
      myFile.read(buffer, sizeof(buffer));
      int volume = 1024;
      Audio.prepare(buffer, S, volume);
      Audio.write(buffer, S);
    }
    myFile.close();
    }
  }
