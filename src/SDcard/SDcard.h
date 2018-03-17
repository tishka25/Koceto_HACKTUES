// MOSI - pin 11
// MISO - pin 12
// CLK - pin 13
// CS - pin 4


#include <SPI.h>
#include <SD.h>


class SDcard{
  public:
    int sdPin;
    SDcard(int sdPin);
    File sprite;
    char *file1;
    void removeFile(char *fileName);
    void writeToFile(char *fileName ,char *array);
    void readFileToSerial(char *fileName);
    void readFile(char *fileName,  char *array);

    void setFileName(File file,char *fileName[]);


};
