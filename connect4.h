#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

const int SCREEN_W = 650;       // screen width
const int SCREEN_H = 450;       // screen height
const float FPS = 7;
struct coord{
    int mx;
    int my;
};

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_BITMAP *image = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER *timer;
#define WHITE al_map_rgb(255,255,255)
#define RED al_map_rgb(255,0,0)
#define BLACK al_map_rgb(0,0,0)

int initializeAllegro(const char title[]);
int drawScreen(int f[][6], int verticalRow, int hue);
bool checkerplacer(int f[][6], int column, int colour);
int column(coord xyvalues);
bool winner(int board[][6], coord lastPlaced, int tint);
