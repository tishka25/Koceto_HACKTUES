// #include <VGA.h>
// #include <MapEditor/Sprites.h>
#include <Bitmap/GameObject.h>
// #include <Controls/Keyboard.h>
#include <Psx.h>                                          // Includes the Psx Library

#pragma once

#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H


#define WIDTH 320
#define HEIGHT 240

#define TRANSPARENT -256


class MapEditor{
  public:
    int xCursor,x_prev;
    int yCursor,y_prev;
    int BACKGROUND_COLOR=0;
    MapEditor();
    void begin();
    void update(int *x,int *y);
    void moveCursor();
    void selectPosition(int *x,int *y);
    void setBackgroundColor(int color);//TODO
    int getBackgroundColor();
    void drawMap_1d(unsigned int _map[]);
    void drawMap_2d(unsigned int _map[][20]);
    void drawGrid();
    int updateGrid(int *xCursor,int *yCursor);
  private:
};

#endif
