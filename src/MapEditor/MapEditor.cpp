#include "MapEditor.h"
GameObject spriteSelector;
GameObject gameObject;
static int GridArray [15][20];


using namespace std;


MapEditor::MapEditor(){}

void MapEditor::begin(){}


int MapEditor::getBackgroundColor(){
	return BACKGROUND_COLOR;
}
// void MapEditor::getSprites(){
//
// }

int MapEditor::getWidth(){return width;}
int MapEditor::getHeight(){return height;}


void MapEditor::fillMap(std::vector<GameObject>&Map,unsigned int *_map){
	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			int pos=(y*width)+x;
			if(_map[pos]==BRICKS_DESTRUCTIVE){
				Map.push_back(new GameObject(bricks_destructive,bricks_destructive_palette,x*16,y*16));
			}
		}

	}
}

void MapEditor::drawMap_1d(unsigned int *_map){
	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			int pos=(y*width)+x;
			if(_map[pos]==BRICKS_DESTRUCTIVE){
				gameObject.setSprite(bricks_destructive,bricks_destructive_palette);
				gameObject.drawAtPosition(x*16,y*16);
			}
		}
	}
}

unsigned int* MapEditor::getMap(){return _map;}
void MapEditor::setMap(unsigned int *_map){	this->_map=_map;}

void MapEditor::drawMap_2d(unsigned int _map[][20]){
  for(int y=0;y<15;y++){
    for(int x=0;x<20;x++){
      if(_map[y][x]==BRICKS_DESTRUCTIVE){
        int width=16;
        int height=16;
				gameObject.setSprite(bricks_destructive,bricks_destructive_palette);
        gameObject.drawAtPosition(x*width,y*height);
      }
    }
  }
}
void MapEditor::drawGrid(){
	int width=16;
	for(int y=0;y<15;y++){
		for(int x=0;x<20;x++){
			VGA.drawRect(x*16,y*16,x*16+width,y*16+width,255);
		}
	}
}

int* MapEditor::updateGrid(int *xCursor,int *yCursor){

int width=16;

if(input.getInput()==psxUp){
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,255 );

		(*yCursor)--;
		if((*yCursor)<=0){
				(*yCursor)=15;
		}
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,224 );
}
if(input.getInput()==psxLeft){
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,255 );

		(*xCursor)--;
		if((*xCursor)<=0){
				(*xCursor)=20;
		}
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,224 );

}

if(input.getInput()==psxRight){
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,255 );

		(*xCursor)++;
		if((*xCursor)>=20){
				(*xCursor)=0;
		}
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,224 );

	 }
if(input.getInput()==psxDown){
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,255 );

		(*yCursor)++;
		if((*yCursor)>=15){
				(*yCursor)=0;
		}
		VGA.drawRect((*xCursor)*16,(*yCursor)*16,(*xCursor)*16+width,(*yCursor)*16+width,224 );
	}
	if(input.getInput()==psxSqu){
	spriteSelector.setSprite(bricks_destructive,bricks_destructive_palette);
	 spriteSelector.drawAtPosition((*xCursor)*16,(*yCursor)*16);
	 spriteSelector.update();
	 GridArray[(*yCursor)][(*xCursor)]=1;
	 Serial.println(GridArray[(*yCursor)][(*xCursor)]);
 }
	delay(120);
if(input.getInput()==psxSlct){
	Serial.println(GridArray[5][5]);
	return (int*)GridArray;
}

}
