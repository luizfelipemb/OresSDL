#pragma once

// Window Settings
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define WINDOW_TITLE "Ore Game by Luiz Felipe Bustamante"
#define WINDOW_FULLSCREEN false
#define WINDOW_FPS 60
#define FRAME_TARGET_TIME (1000/WINDOW_FPS)

// Image Settings
#define BACKGROUND_IMAGE "assets/background.jpg"
#define TILE_GREY_IMAGE "assets/TileGrey.png"
#define TILE_YELLOW_IMAGE "assets/TileYellow.png"
#define TILE_BLUE_IMAGE "assets/TileBlue.png"
#define TILE_GREEN_IMAGE "assets/TileGreen.png"
#define TILE_RED_IMAGE "assets/TileRed.png"
#define TILE_SIDE 50

// Board Settings
#define BOARD_GAMESTART_COLUMNS 7
#define BOARD_COLUMN_BLOCK_NUMBER 10
#define BOARD_INITIALCOLUMN_HEIGHT_POS 50
#define BOARD_MAX_COLUMN_SIZE 16

// Game Settings
#define PUSH_TIMER 3
#define NEXT_LEVEL_SCORE 10
#define NEXT_LEVEL_SCORE_MULTIPLY 1.6f

//Font Settings
#define FONT_LOCATION "assets/pixel.ttf"