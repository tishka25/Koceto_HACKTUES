#include <MapEditor/MapEditor.h>
#include <SDcard/SDcard.h>

#define INTRWIDTH (WIDTH/2)-25
#define BLUE 10
#define YELLOW 250
#define WHITE 255
#define MENU_UP 1
#define MENU_DOWN -1

#define MENU_KEY_UP 'w'
#define MENU_KEY_DOWN 's'
#define MENU_KEY_SELECT PS2_ENTER
#define INPUT_METHOD input.input()

#define SD_PIN 1


class Interface{
  public:
    Interface();
    int menu_pos=1;
    int menu_pos_prev=0;
    bool backToMenu=1;
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
