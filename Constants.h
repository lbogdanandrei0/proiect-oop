#pragma once
#include <iostream>

const double PI = 3.1415;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 768;
const int FRAMERATE = 1000 / 144;

const std::string MAIN_MENU_BACKGROUND = "mainMenuBackground.png";
const std::string MAIN_MENU_PLAY_BUTTON = "playButton.png";
const std::string MAIN_MENU_SETTINGS_BUTTON = "settingsButton.png";
const std::string MAIN_MENU_EXIT_BUTTON = "exitButton.png";

const std::string BOARD_TEXTURE = "board.png";

const int COLLISION_UP_LEFT = 0;
const int COLLISION_LEFT = 1;
const int COLLISION_UP = 2;
const int COLLISION_UP_RIGHT = 3;
const int COLLISION_RIGHT = 4;
const int COLLISION_DOWN_LEFT = 5;
const int COLLISION_DOWN = 6;
const int COLLISION_DOWN_RIGHT = 7;
