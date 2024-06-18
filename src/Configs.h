#pragma once

// Window Settings
static constexpr int WINDOW_WIDTH = 640 * 2;
static constexpr int WINDOW_HEIGHT = 360 * 2;
static const char* WINDOW_TITLE = "Ores Game by Luiz Felipe Bustamante";
static constexpr bool WINDOW_FULLSCREEN = false;
static constexpr int WINDOW_FPS = 60;
static constexpr int FRAME_TARGET_TIME = 1000 / WINDOW_FPS;

// Board Settings
static constexpr int TILE_SIDE = WINDOW_HEIGHT / 15;
static constexpr int BOARD_GAMESTART_COLUMNS = 7;
static constexpr int BOARD_COLUMN_BLOCK_NUMBER = 10;
static constexpr float BOARD_INITIALCOLUMN_HEIGHT_POS = WINDOW_HEIGHT/10;
static constexpr int BOARD_MAX_COLUMN_SIZE = 16;

// Game Settings
static constexpr int PUSH_TIMER = 10;
static constexpr int NEXT_LEVEL_SCORE = 100;
static constexpr float NEXT_LEVEL_SCORE_MULTIPLY = 1.6f;

//Images
static const char* ENDLINE_IMAGE = "assets/Sign.png";
static const char* TILE_GREY_IMAGE = "assets/TileGrey.png";
static const char* BUTTON_IMAGE = "assets/Button.png";

//Colors
#define TEXT_COLOR { 252, 253, 77 }
#define BACKGROUND_COLOR { 37,38,59 }
#define BLUE_COLOR { 140,140,255 }
#define GREEN_COLOR { 140,255,140 }
#define DARK_GREEN_COLOR { 0,120,0 }
#define RED_COLOR { 255,140,140 }
#define DARK_RED_COLOR { 120,0,0 }
#define YELLOW_COLOR { 255,255,140 }

//Font Settings
static const char* FONT_LOCATION = "assets/pixel.ttf";

//Hacks
#define HACK_BREAK_EVERY_BLOCK false
