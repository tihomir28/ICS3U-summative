#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

const int SCREEN_W = 650;       // screen width
const int SCREEN_H = 450;       // screen height

ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_BITMAP *image = nullptr;
#define WHITE al_map_rgb(255,255,255)
#define RED al_map_rgb(255,0,0)
#define BLACK al_map_rgb(0,0,0)

int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *image);
int circlemaker(int f[][6]);
void checkerplacer(int f[][6], int column, int colour);
