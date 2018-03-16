#include "MapEditor.h"

GameObject *spriteSelector;
GameObject GameObjects;





MapEditor::MapEditor(){}

void MapEditor::begin(){
}
// void MapEditor::update(int *x,int *y){
//   moveCursor();
//   selectPosition(x,y);
// }
// void MapEditor::moveCursor(){
//   VGA.drawRect(xCursor,yCursor,xCursor+16,yCursor+16,50);
//   x_prev=xCursor;
//   y_prev=yCursor;
//   if(xCursor!=x_prev || yCursor!=y_prev){
//     VGA.drawRect(x_prev,y_prev,x_prev+16,y_prev+16,getBackgroundColor());
//   }
//   switch (input.control()) {
//     case LEFT:xCursor-=16;break;
//     case DOWN:yCursor+=16;break;
//     case RIGHT:xCursor+=16;break;
//     case UP:yCursor-=16;break;
//   }
// }
// void MapEditor::selectPosition(int *x,int *y){
//   if(input.key(PS2_ENTER)){
//     x=&xCursor;
//     y=&yCursor;
//   }
// }
int MapEditor::getBackgroundColor(){
	return BACKGROUND_COLOR;
}
void MapEditor::getSprites(){

}

// void MapEditor::drawSpriteSelector(){
//   int _x=WIDTH/80;
//   int _y=5;
//   for(int i=0;i<AVAILABLE_SPRITES;i++){
//     spriteSelector[i].setSprite(availableSprites[BRICKS_DESTRUCTIVE]
//       ,availableSprites[BRICKS_DESTRUCTIVE+1]);
//     spriteSelector[i].setPosition(_x, _y);
//     _x+=spriteSelector->getWidth()+5;
//   }
// }
void MapEditor::drawMap_1d(unsigned int _map[]){
	int _width=_map[MAP_WIDTH];
	int _height=_map[MAP_HEIGHT];
	int _y=0;
	int _x=0;
	for(int _pos=2;_pos<=(_width*_height)+2;_pos++){
			if(_map[_pos]==BRICKS_DESTRUCTIVE){
				if((_pos-2)%(_width)==0&&(_pos-2)!=0)_y++;
				_x=(_pos-2)-_y*_width;
				GameObjects.setSprite(bricks_destructive,bricks_destructive_palette);
				GameObjects.setPosition(_x*16,_y*16);
				GameObjects.draw();
				// GameObjects.drawAtPosition(_x*16-2,_y*16-2);
		}
	}
}
// template <size_t rows, size_t cols>
void MapEditor::drawMap_2d(unsigned int _map[][20]){
  for(int y=0;y<15;y++){
    for(int x=0;x<20;x++){
      if(_map[y][x]==BRICKS_DESTRUCTIVE){
        int width=16;
        int height=16;
				GameObjects.setSprite(bricks_destructive,bricks_destructive_palette);
        GameObjects.drawAtPosition(x*width,y*height);
      }
    }
  }
}