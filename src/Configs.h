#pragma once

// Window Settings
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define WINDOW_TITLE "Ore Game by Luiz Felipe Bustamante"
#define WINDOW_FULLSCREEN false
#define WINDOW_FPS 60
#define FRAME_TARGET_TIME (1000/WINDOW_FPS)

// Board Settings
#define TILE_SIDE 50
#define BOARD_GAMESTART_COLUMNS 7
#define BOARD_COLUMN_BLOCK_NUMBER 10
#define BOARD_INITIALCOLUMN_HEIGHT_POS 100
#define BOARD_MAX_COLUMN_SIZE 16

// Game Settings
#define PUSH_TIMER 1
#define NEXT_LEVEL_SCORE 10
#define NEXT_LEVEL_SCORE_MULTIPLY 1.6f

// Visual Settings
	//Images
#define SIGN_IMAGE "assets/Sign.png"
#define TILE_GREY_IMAGE "assets/TileGrey.png"
#define BUTTON_IMAGE "assets/Button.png"
	//Menu
#define MENU_TITLE "Ore Game"
#define MENU_SUBTITLE "by Luiz Felipe Bustamante"
#define PLAY_BUTTON_WIDTH WINDOW_WIDTH/8
#define PLAY_BUTTON_X WINDOW_WIDTH/2 - PLAY_BUTTON_WIDTH/2
	//Colors
#define TEXT_COLOR {252, 253, 77}
#define BACKGROUND_COLOR {37,38,59}
#define BLUE_COLOR {140,140,255}
#define GREEN_COLOR {140,255,140}
#define DARK_GREEN_COLOR {0,120,0}
#define RED_COLOR {255,140,140}
#define DARK_RED_COLOR {120,0,0}
#define YELLOW_COLOR {255,255,140}
	//UI InGame
#define ABOVE_UI_POS_Y WINDOW_HEIGHT / 100
#define UI_BARS_WIDTH 100
#define UI_BARS_HEIGHT 20
#define PUSH_UI_POS_X WINDOW_WIDTH/2 * 1.6f
#define SCORE_UI_POS_X WINDOW_WIDTH/2

//Font Settings
#define FONT_LOCATION "assets/pixel.ttf"