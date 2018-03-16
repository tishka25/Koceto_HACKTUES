#include <MapEditor/MapEditor.h>



class Interface{
  public:
    Interface();
    int menu_pos=1;
    void begin();
    void setBackground(int color);
    void draw();
    void select();
    void move(int direction);
  };

extern Keyboard input;
