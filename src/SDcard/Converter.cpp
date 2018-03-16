#include "Converter.h"
#include <Arduino.h>

Converter::Converter(){}

template <size_t rows, size_t cols>
void Converter::convert1Dto2Darr(unsigned int *arr1D,int (&arr2D)[rows][cols]){
  int _width=arr1D[0];
	int _height=arr1D[1];
	int _x=0;
	int _y=0;
	for(int _pos=2;_pos<=(_width*_height)+2;_pos++){
			if((_pos-2)%(_width)==0&&(_pos-2)!=0)_y++;
			_x=(_pos-2)-_y*_width;
      arr2D[_x][_y]=arr1D[_pos];
	}
}
void Converter::flipSprite(unsigned char *arr,unsigned char *arrNew, int rotation){
  int _width = 16;  arrNew[1] = _width;
	int _height =16; arrNew[0] = _height;
	int _frames = 1; arrNew[2] = _frames;
	int _pos = 3;
	for (int frameCount = 1; _frames >= frameCount; frameCount++) {
		int _oldPos = (_width*_height*frameCount)+1;
		int _newPos = _oldPos;
		int count = 0;
		for (; _pos - (_width*_height)*(frameCount-1) < (_width*_height) + 3; _pos++) {
			if ((_newPos - _width) >= count + (_width*_height)*(frameCount - 1)) {
				_newPos = _newPos - _width;
			}
			else {
				count++;
				_newPos = _oldPos + count -_width;
			}
			arrNew[_pos] = arr[_newPos+2];
		}
	}
	if (rotation>1)flipSprite(arr, arrNew, rotation--);
}
