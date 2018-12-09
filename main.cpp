#include "connect4.h"

int main(int argc, char *argv[]) {

	initializeAllegro(display, image);
	int field[7][6] = {0};
	circlemaker(field);
	checkerplacer(field, 0, 1);
    checkerplacer(field, 0, 2);
    al_rest(5);
    return 0;
}

void checkerplacer(int f[][6], int column, int colour){
    for(int i=5; i>=0; i--){
        if(f[column][i] == 0){
            f[column][i] = colour;
            break;
        }
    }
    circlemaker(f);
}

int circlemaker(int f[][6]){
    image = al_load_bitmap("c4.bmp");
    al_draw_bitmap(image, 0,  0, 0);
    for(int i=0; i<=5; i++){
        for(int j=0; j<=6; j++){
            switch(f[j][i]){
                case 0:
                    al_draw_filled_circle(165+(j*55), 80+(i*50), 23, WHITE);
                    break;
                case 1:
                    al_draw_filled_circle(165+(j*55), 80+(i*50), 23, RED);
                    break;
                case 2:
                    al_draw_filled_circle(165+(j*55), 80+(i*50), 23, BLACK);
                    break;
            }
        }
    }


    al_flip_display();
    return 0;
}


int initializeAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *image){
    // Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
 	al_set_window_title(display, "Connect 4");

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare a BITMAP called image, setting it's initial value to nullptr


	// Load the bitmap into the Bitmap structure
	// image file must be in same directory.
	// Particularly check return code of this type of function that will fail if file not found.
    image = al_load_bitmap("c4.bmp");
  	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	al_destroy_display(display);
     	return -1;
	 }
	 if (!al_init_primitives_addon()) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}
	return 0;
}
