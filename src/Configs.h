#pragma once

// Window Settings

#define WINDOW_FULLSCREEN false
#define WINDOW_FPS 60
#define FRAME_TARGET_TIME (1000/WINDOW_FPS)

// Board Settings
#define BOARD_GAMESTART_COLUMNS 7
#define BOARD_COLUMN_BLOCK_NUMBER  10
#define BOARD_MAX_COLUMN_SIZE 16

// Game Settings
#define PUSH_TIMER 10
#define NEXT_LEVEL_SCORE 100
#define NEXT_LEVEL_SCORE_MULTIPLY 1.6f

//Images
#define ENDLINE_IMAGE "assets/Sign.png"
#define TILE_GREY_IMAGE "assets/TileGrey.png"
#define BUTTON_IMAGE "assets/Button.png"

//Colors
#define TEXT_COLOR {252, 253, 77}
#define BACKGROUND_COLOR {37,38,59}
#define BLUE_COLOR {140,140,255}
#define GREEN_COLOR {140,255,140}
#define DARK_GREEN_COLOR {0,120,0}
#define RED_COLOR {255,140,140}
#define DARK_RED_COLOR {120,0,0}
#define YELLOW_COLOR {255,255,140}

//Font Settings
#define FONT_LOCATION "assets/pixel.ttf"

//Hacks
#define HACK_BREAK_EVERY_BLOCK false