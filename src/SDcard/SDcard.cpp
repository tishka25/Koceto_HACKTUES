#include "SDcard.h"

SDcard::SDcard(int sdPin){
  this->sdPin=sdPin;
}
void SDcard::writeToFile(char *fileName ,char *array){
  file=SD.open(fileName,FILE_WRITE);
  if(file){
    Serial.print("Writing to file...");
    file.print(array);
    file.close();
    Serial.println("done.");
  }
  else{
    Serial.println("error opening file");
  }
}
void SDcard::readFile(char *fileName , char *array){
  file=SD.open(fileName);
  int count=0;
  if(file){
    Serial.println("Copying file..");
    while(file.available()&&count<file.size()){
      array[count]=file.read();
      count++;
    }
    array[count]='\0';
    file.close();
  }else{
    Serial.println("error opening file");
  }
}
void SDcard::readFileToSerial(char *fileName){
  file=SD.open(fileName);
  if(file){
    Serial.println("file content:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
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
