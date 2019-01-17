#include "connect4.h"

int main(int argc, char *argv[]) {

	initializeAllegro("Connect 4");

	int field[7][6] = {0};
	bool exit = false;
	int colour = 1;
	int switcher = 0;
	coord mouseCoordinates;
	drawScreen(field, 7, 0, switcher);

	al_start_timer(timer);
    while(!exit){
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            exit = true;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
            mouseCoordinates.mx = ev.mouse.x;
            mouseCoordinates.my = ev.mouse.y;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            mouseCoordinates.mx = ev.mouse.x;
            mouseCoordinates.my = ev.mouse.y;
            if(switcher == 0){
                if(column(mouseCoordinates, switcher) == 7)
                    switcher = 1;
            }
            else if(field[column(mouseCoordinates, switcher)][0] == 0){
                exit = checkerplacer(field, column(mouseCoordinates, switcher), colour);
                if(colour == 1)
                    colour = 2;
                else
                    colour = 1;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER){
            drawScreen(field, column(mouseCoordinates, switcher), colour, switcher);
        }
    }
    return 0;
}

bool checkerplacer(int f[][6], int column, int colour){
    coord placedPiece;
    placedPiece.mx = column;
    for(int i=5; i>=0; i--){
        if(f[column][i] == 0){
            f[column][i] = colour;
            placedPiece.my = i;
            break;
        }
    }
    if(!winner(f, placedPiece, colour)){
        drawScreen(f, 7, 0, 1);
        return false;
    }
    else{
        drawScreen(f, 8, colour, 1);
        return true;
    }
}

bool winner(int board[][6], coord lastPlaced, int tint){
    bool stopper[2] = {false, false};
    int counter = 0;
    /// direction 1: horizontal
    for(int i = 1; i < 4; i++){
        if(lastPlaced.mx - i <= -1)
            stopper[0] == true;
        else if(!stopper[0]){
            if(board[lastPlaced.mx-i][lastPlaced.my] == tint)
                counter ++;
            else
                stopper[0] = true;
        }
        if(lastPlaced.mx + i >= 7)
            stopper[1] == true;
        else if(!stopper[1]){
            if(board[lastPlaced.mx+i][lastPlaced.my] == tint)
                counter ++;
            else
                stopper[1] = true;
        }
        if(counter >= 3)
            return true;
    }
    counter = 0;
    stopper[0] = false;
    stopper[1] = false;
    /// direction 2: vertical
    for(int i = 1; i < 4; i++){
        if(lastPlaced.my + i >= 6)
            stopper[1] == true;
        else if(!stopper[1]){
            if(board[lastPlaced.mx][lastPlaced.my+i] == tint)
                counter ++;
            else
                stopper[1] = true;
        }
        if(counter >= 3)
            return true;
    }
    counter = 0;
    stopper[0] = false;
    stopper[1] = false;
    /// direction 3: first diagonal (\)
    for(int i = 1; i < 4; i++){
        if(lastPlaced.mx - i <= -1 || lastPlaced.my - i <= -1){
            stopper[0] == true;
        }
        else if(!stopper[0]){
            if(board[lastPlaced.mx-i][lastPlaced.my-i] == tint){
                counter ++;
            }
            else{
                stopper[0] = true;
            }
        }
        if(lastPlaced.mx + i >= 7 || lastPlaced.my + i >= 6){
            stopper[1] == true;
        }
        else if(!stopper[1]){
            if(board[lastPlaced.mx+i][lastPlaced.my+i] == tint){
                counter ++;
            }
            else{
                stopper[1] = true;
            }
        }
        if(counter >= 3)
            return true;
    }
    counter = 0;
    stopper[0] = false;
    stopper[1] = false;
    /// direction 4: second diagonal (/)
    for(int i = 1; i < 4; i++){
        if(lastPlaced.mx - i <= -1 || lastPlaced.my + i >= 6)
            stopper[0] == true;
        else if(!stopper[0]){
            if(board[lastPlaced.mx-i][lastPlaced.my+i] == tint)
                counter ++;
            else
                stopper[0] = true;
        }
        if(lastPlaced.mx + i >= 7 || lastPlaced.my - i <= -1)
            stopper[1] == true;
        else if(!stopper[1]){
            if(board[lastPlaced.mx+i][lastPlaced.my-i] == tint)
                counter ++;
            else
                stopper[1] = true;
        }
        if(counter >= 3)
            return true;
    }
    return false;
}

int column(coord xyvalues, int screen){
    if(screen == 1){
        if((xyvalues.mx > 111 && xyvalues.mx < 191) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 0;
        else if((xyvalues.mx > 191 && xyvalues.mx < 248) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 1;
        else if((xyvalues.mx > 248 && xyvalues.mx < 304) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 2;
        else if((xyvalues.mx > 304 && xyvalues.mx < 358) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 3;
        else if((xyvalues.mx > 358 && xyvalues.mx < 414) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 4;
        else if((xyvalues.mx > 414 && xyvalues.mx < 469) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 5;
        else if((xyvalues.mx > 469 && xyvalues.mx < 555) && (xyvalues.my > 54 && xyvalues.my < 350))
            return 6;
    }
    else if(screen == 0){
        if((xyvalues.mx > 280 && xyvalues.mx < 380) && (xyvalues.my > 370 && xyvalues.my < 410))
            return 7;
    }
}

void drawScreen(int f[][6], int verticalRow, int hue, int modifier){
    if(modifier == 1){
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
        if(verticalRow < 7){
            if(hue == 1)
                al_draw_filled_circle(165+(verticalRow*55), 30, 23, RED);
            else
                al_draw_filled_circle(165+(verticalRow*55), 30, 23, BLACK);
        }
        if(verticalRow == 8){
            if(hue == 1){
                al_draw_text(arial, BLACK, 255, 10, 0, "RED WINS!");
            }
            else{
                al_draw_text(arial, BLACK, 255, 10, 0, "BLACK WINS!");
            }
        }
    }
    if(modifier == 0){
        al_clear_to_color(WHITE);
        al_draw_bitmap(image, 0, 0, 0);
        for(int i=0; i<=5; i++){
            for(int j=0; j<=6; j++){
                if((i+j)%2 == 1){
                    al_draw_filled_circle(165+(j*55), 80+(i*50), 23, RED);
                }
                else{
                    al_draw_filled_circle(165+(j*55), 80+(i*50), 23, BLACK);
                }
            }
        }
        al_draw_text(arial, BLACK, 255, 10, 0, "Connect 4");
        al_draw_filled_rectangle(280, 370, 380, 410, BLUE);
        al_draw_text(arial, BLACK, 300, 370, 0, "Play");
        al_flip_display();
    }
    al_flip_display();
    if(verticalRow == 8)
        al_rest(5);
}


int initializeAllegro(const char title[]){
    // Initialize Allegro
	al_init();

	// Initialize display
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}
 	al_set_window_title(display, title);

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	timer = al_create_timer(1.0 / FPS);
   	if (!timer) {
   		al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

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
	if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
    }
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon

    arial = al_load_ttf_font("arial.ttf", 32, 0);
    if (!arial){
        al_show_native_message_box(display, "Error", "Error", "Could not load arial.ttf",
                        nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return -1;
	}
    al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	return 0;
}
