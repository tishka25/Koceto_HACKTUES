#include <MapEditor/MapEditor.h>
#include <SDcard/SDcard.h>


class Interface{
  public:
    Interface();
    int menu_pos=1;
    void post();
    void bootScreen();
    void begin();
    void setBackground(int color);
    void draw();
    void select();
    void move(int direction);
    void menuSelect(int item);
    void menuAbout();
  };

// extern Keyboard input;
