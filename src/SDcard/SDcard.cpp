#include "SDcard.h"

SDcard::SDcard(int sdPin){
  this->sdPin=sdPin;
}
void SDcard::writeToFile(char *fileName ,char *array){
  sprite=SD.open(fileName,FILE_WRITE);
  if(sprite){
    Serial.print("Writing to file...");
    sprite.print(array);
    sprite.close();
    Serial.println("done.");
  }
  else{
    Serial.println("error opening file");
  }
}
void SDcard::readFile(char *fileName , char *array){
  sprite=SD.open(fileName);
  int count=0;
  if(sprite){
    Serial.println("Copying file..");
    while(sprite.available()&&count<sprite.size()){
      array[count]=sprite.read();
      count++;
    }
    array[count]='\0';
    sprite.close();
  }else{
    Serial.println("error opening file");
  }
}
void SDcard::readFileToSerial(char *fileName){
  sprite=SD.open(fileName);
  if(sprite){
    Serial.println("file content:");
    while (sprite.available()) {
      Serial.write(sprite.read());
    }
    sprite.close();
    Serial.println(" ");
  }else{Serial.println("error opening file");}
}
void SDcard::removeFile(char *fileName){
  if(SD.exists(fileName)){
    SD.remove(fileName);
    Serial.println("file removed");
  }
  else
  {
      Serial.println("no file to remove");
  }
}
