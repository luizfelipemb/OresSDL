#pragma once

// Window Settings
#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1024
#define WINDOW_TITLE "Ore Game by Luiz Felipe Bustamante"
#define WINDOW_FULLSCREEN false
#define WINDOW_FPS 60
#define FRAME_TARGET_TIME (1000/WINDOW_FPS)

// Image Settings
#define TILE_IMAGE "assets/tile.png"
#define SNAKE_IMAGE "assets/snake.png"
#define APPLE_IMAGE "assets/apple.png"

// Font Settings
#define FONT_DIRECTORY "assets/RetroGaming.ttf"
#define UIFONTSIZE 65

// Audio Settings
#define VOLUME 60

// Board Settings
#define BOARD_NUM_OF_XLINES 12
#define BOARD_NUM_OF_YLINES 12
#define SQUARE_SIZE 50

// Game Settings
#define SNAKE_BEGGINING_SIZE 5
#define SNAKE_BEGGIN_LINE_X 5
#define SNAKE_BEGGIN_LINE_Y 5
#define TIMER_TO_UPDATE_SNAKE_IN_SECS 0.5f
#define SECS_TO_SPAWN_APPLE 5