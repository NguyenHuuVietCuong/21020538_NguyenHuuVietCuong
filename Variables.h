#pragma once

#include <SDL2/SDL_mixer.h>
#include <sstream>
#include "Texture.h"
#include "Constances.h"
#include "Button.h"


//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//The sound effects that will be used
extern Mix_Music *winner;
extern Mix_Music *loser;
extern Mix_Chunk *click;
extern Mix_Chunk *menuClick; 
extern Mix_Chunk *emoteClick;
extern Mix_Chunk *menuMS;

//Globally used font
extern TTF_Font *gFont;
extern TTF_Font *gMSFont; 

extern TTF_Font *gPlayerWin;
extern TTF_Font *gGameOver;
    //Menu 
extern TTF_Font *gDifficulty;
extern TTF_Font *gDifficultyMS; 
extern TTF_Font *gQuit;
extern TTF_Font *gQuitMS;
extern TTF_Font *gBeginner;
extern TTF_Font *gBeginnerMS;
extern TTF_Font *gIntermediate;
extern TTF_Font *gIntermediateMS;
extern TTF_Font *gExpert;
extern TTF_Font *gExpertMS;
extern TTF_Font *gBacktoMenu;
extern TTF_Font *gBacktoMenuMS;
extern TTF_Font *gTheme;
extern TTF_Font *gClassicTheme;
extern TTF_Font *gClassicThemeMS;
extern TTF_Font *gEmojiTheme;
extern TTF_Font *gEmojiThemeMS;

//Mouse button texture
extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
extern LTexture gButtonSpriteSheetTexture;

//Emote texture 
extern SDL_Rect gEmoteClips[ EMOTE_SPRITE_TOTAL ];
extern LTexture gEmoteSpriteSheetTexture;

//Menu texture 
extern LTexture gMenuItem[ MENU1_ITEM_TOTAL ];

//Screen texture
extern LTexture gWinningTexture;
extern LTexture gBackgroundTexture;
extern LTexture gmenuBackgroundTexture;


//Rendered texture
extern LTexture gPlayerWinTexture; 
extern LTexture gGameOverTexture;
extern LTexture gMineLeftTexture;
    //Menu
extern LTexture gDifficultyTexture;
extern LTexture gDifficultyMSTexture; 
extern LTexture gQuitTexture;
extern LTexture gQuitMSTexture;
extern LTexture gBeginnerTexture;
extern LTexture gBeginnerMSTexture;
extern LTexture gIntermediateTexture;
extern LTexture gIntermediateMSTexture;
extern LTexture gExpertTexture; 
extern LTexture gExpertMSTexture;
extern LTexture gBacktoMenuTexture; 
extern LTexture gBacktoMenuMSTexture; 
extern LTexture gThemeTexture;
extern LTexture gClassicThemeTexture;
extern LTexture gClassicThemeMSTexture;
extern LTexture gEmojiThemeTexture;
extern LTexture gEmojiThemeMSTexture;

extern LTexture gClassicThemePreviewTexture;
extern LTexture gEmojiThemePreviewTexture; 

//Gameplay variables
extern int b_countMineLeft;
extern int i_countMineLeft;
extern int e_countMineLeft;

extern int b_countTileLeft;
extern int i_countTileLeft;
extern int e_countTileLeft;

extern bool gameOver;
extern bool isWinning;
extern bool quitGame;
extern bool quitApp;
extern bool newGame;

//In memory text stream
extern stringstream mineLeft;

extern int emoteStatus;

extern LButton gIngameEmote;

//Menu's buttons
extern LButton gDifficultyButton;
extern LButton gQuitButton;
extern LButton gBeginnerButton;
extern LButton gIntermediateButton;
extern LButton gExpertButton;
extern LButton gBacktoMenuButton;
extern LButton gClassicThemeButton;
extern LButton gEmojiThemeButton;
extern LButton gDifficultyMSButton;

//Menu status manager
extern int mainMenuStatus;
extern int difficultyMenuStatus; 
extern int themeMenuStatus;
extern int menuDifficultyStatus;
extern int menuQuitStatus; 
extern int menuBeginnerStatus;
extern int menuIntermediateStatus;
extern int menuExpertStatus;
extern int menuBackToMenuStatus;
extern int menuClassicThemeStatus;
extern int menuEmojiThemeStatus; 
extern int textStatus; 
/*
mainMenuStatus = 0 : Haven't selected yet
mainMenuStatus = 1 : is selecting 
mainMenuStatus = 2 : Quit option has been selected
mainMenuStatus = 3 : Difficulty option has been selected
difficultyMenuStatus = 1 : Beginner
difficultyMenuStatus = 2 : Intermediate
difficultyMenuStatus = 3 : Expert 
*/

