// #include <VGA.h>
// #include <MapEditor/Sprites.h>
#include <Bitmap/GameObject.h>
#include <Controls/Input.h>
// #include <Controls/Keyboard.h>
#include <Psx.h>
#include <vector>
#include <stdio.h>


#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H


#define WIDTH 320
#define HEIGHT 240

#define TRANSPARENT -256


GameObject g;


class MapEditor{
  public:
    int xCursor,x_prev;
    int yCursor,y_prev;
    int BACKGROUND_COLOR=0;
    int width=WIDTH/16,height=HEIGHT/16;
    unsigned int *_map;

    MapEditor();
    void begin();
    void update(int *x,int *y);
    void moveCursor();
    void selectPosition(int *x,int *y);
    void setBackgroundColor(int color);//TODO

    int getWidth();
    int getHeight();
    void setSize(int width,int height);//TODO

    unsigned int* getMap();
    void setMap(unsigned int *_map);
    void fillMap(std::vector<GameObject>&Map,unsigned int *_map);

    int getBackgroundColor();
    void drawMap_1d(unsigned int *_map);
    void drawMap_2d(unsigned int _map[][20]);
    void drawGrid();
    int* updateGrid(int *xCursor,int *yCursor);
  private:
};
extern Input input;

#endif
