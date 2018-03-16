#ifndef DRAW_H
#define DRAW_H

#include <VGA.h>
#include <crntsc.h>
#include <crpal.h>
// #include <GameEngine.h>
// #include <MapEditor/MapEditor.h>



#define RESX 320
#define RESY 240

class Draw{
  public:
    Draw();
    int getWidth(unsigned char sprite[]);
    int getHeight(unsigned char sprite[]);
    int getFrameCount(unsigned char sprite[]);
    void drawSprite(unsigned char sprite[],unsigned char blend[],int current_frame,int o_left , int o_top);
    void drawImage(unsigned char background[],int width,int height,int left, int top);
    unsigned char *getImageSample(unsigned char background[],int src_width,int width,int height,int left,int top);
    void drawColourTable(int left,int top);
};

extern Draw draw;
#endif
