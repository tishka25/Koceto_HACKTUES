#include "Draw.h"

Draw::Draw(){}
int Draw::getHeight(unsigned char sprite[]){
  return sprite[1];
}
int Draw::getWidth(unsigned char sprite[]){
  return sprite[0];
}
int Draw::getFrameCount(unsigned char *sprite){
  return sprite[2];
}
void Draw::drawSprite(unsigned char sprite[],unsigned char blend[],int current_frame,int o_left,int o_top){

  int w = sprite[0];
  int h = sprite[1];
  int count = sprite[2];

  int frame_offset = (w*h) * current_frame;

  for(int x = 0;x<w;x++){

     for(int y = 0;y<h;y++){

       int pixel_offset = (w * y) + x;
       int unpacked_pixel = 0;
       int packed_pixel = 0;
       int offset = frame_offset + pixel_offset;

       packed_pixel = sprite[3+(int)floor(offset/2)];

       if(offset % 2){
          unpacked_pixel = packed_pixel & 0xf;
       }
       else
       {
          unpacked_pixel = (packed_pixel >> 4) & 0xf;
       }

       if( unpacked_pixel != 0 ){
         VGA.putCPixelFast(o_left+x,o_top+y,blend[unpacked_pixel-1]);
       }
       else
       {
         //int i = x+o_left;
         //int j = y+o_top;
         //VGA.putCPixelFast(i,j,backdrop[(j*320) + i]);
        VGA.putCPixelFast(x+o_left,y+o_top, blend[(y*w) + x]);
       }

     }

  }
}
void Draw::drawImage(unsigned char background[],int width,int height,int left,int top){
  for(int x = 0;x<width;x++){
   for(int y = 0;y<height;y++){
    VGA.putCPixelFast(left+x,top+y,background[y*width + x]);
   }
  }
}

unsigned char *Draw::getImageSample(unsigned char *background,int src_width, int width, int height, int left, int top){
  unsigned char buf[width*height];
  for(int x = 0;x<width;x++){
   for(int y = 0;y<height;y++){
     int i = x+left;
     int j = y+top;
     buf[y*width + x] = background[(j*src_width) + i];
     //VGA.putCPixelFast(pos_left+x,pos_top+y, backdrop[(j*src_width) + i]);
   }
  }
  return buf;
}
void Draw::drawColourTable(int left, int top){
  // Horizontal block of 4*8 pixels
for(int c = 0;c < 8;c++){
  // 8 down
  for(int d = 0;d < 8;d++){
    // 4 across
    for(int a = 0;a < 4;a++){
       int x = (c*4) + a;
       int y = d;

       int offset = c*32;

       VGA.putCPixelFast(left+x,top+y,offset + (4*d) + a);
    }
  }
}
}
