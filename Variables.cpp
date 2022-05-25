#include "Variables.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The sound effects that will be used
Mix_Music *winner = NULL;
Mix_Music *loser = NULL;
Mix_Chunk *click = NULL;
Mix_Chunk *menuClick = NULL; 
Mix_Chunk *emoteClick = NULL;
Mix_Chunk *menuMS = NULL;

//Globally used font
TTF_Font *gFont = NULL;
TTF_Font *gMSFont = NULL;


TTF_Font *gPlayerWin = NULL;
TTF_Font *gGameOver = NULL;
    //Menu Item
TTF_Font *gDifficulty = NULL;
TTF_Font *gDifficultyMS = NULL; 
TTF_Font *gQuit = NULL;
TTF_Font *gQuitMS = NULL;
TTF_Font *gBeginner = NULL;
TTF_Font *gBeginnerMS = NULL;
TTF_Font *gIntermediate = NULL;
TTF_Font *gIntermediateMS = NULL;
TTF_Font *gExpert = NULL;
TTF_Font *gExpertMS = NULL;
TTF_Font *gBacktoMenu = NULL;
TTF_Font *gBacktoMenuMS = NULL;
TTF_Font *gTheme = NULL;
TTF_Font *gClassicTheme = NULL;
TTF_Font *gClassicThemeMS = NULL;
TTF_Font *gEmojiTheme = NULL;
TTF_Font *gEmojiThemeMS = NULL;

//Mouse button texture
SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
LTexture gButtonSpriteSheetTexture;

//Emote texture 
SDL_Rect gEmoteClips[ EMOTE_SPRITE_TOTAL ];
LTexture gEmoteSpriteSheetTexture;

//Menu texture 
LTexture gMenuItem[ MENU1_ITEM_TOTAL ];

//Screen texture
LTexture gWinningTexture;
LTexture gBackgroundTexture;
LTexture gmenuBackgroundTexture;

//Rendered texture
LTexture gPlayerWinTexture; 
LTexture gGameOverTexture;
LTexture gMineLeftTexture;
    //Menu
LTexture gDifficultyTexture;
LTexture gDifficultyMSTexture; 
LTexture gQuitTexture;
LTexture gQuitMSTexture;
LTexture gBeginnerTexture;
LTexture gBeginnerMSTexture;
LTexture gIntermediateTexture;
LTexture gIntermediateMSTexture;
LTexture gExpertTexture; 
LTexture gExpertMSTexture;
LTexture gBacktoMenuTexture; 
LTexture gBacktoMenuMSTexture; 
LTexture gThemeTexture;
LTexture gClassicThemeTexture;
LTexture gClassicThemeMSTexture;
LTexture gEmojiThemeTexture;
LTexture gEmojiThemeMSTexture;

LTexture gClassicThemePreviewTexture;
LTexture gEmojiThemePreviewTexture; 

//Gameplay variables
int b_countMineLeft = B_MINE_COUNT;
int i_countMineLeft = I_MINE_COUNT;
int e_countMineLeft = E_MINE_COUNT;

int b_countTileLeft = B_ROW_SIZE * B_COLUMN_SIZE;
int i_countTileLeft = I_ROW_SIZE * I_COLUMN_SIZE;
int e_countTileLeft = E_ROW_SIZE * E_COLUMN_SIZE;

bool gameOver = false;
bool isWinning = false;
bool quitGame = false;
bool quitApp = false;
bool newGame = false;

//In memory text stream
stringstream mineLeft;

int emoteStatus;

LButton gIngameEmote;

//Menu's buttons
LButton gDifficultyButton;
LButton gQuitButton;
LButton gBeginnerButton;
LButton gIntermediateButton;
LButton gExpertButton;
LButton gBacktoMenuButton;
LButton gClassicThemeButton;
LButton gEmojiThemeButton; 
LButton gDifficultyMSButton; 

int mainMenuStatus = 0;
int difficultyMenuStatus = 0;
int themeMenuStatus = 0;
int menuDifficultyStatus;
int menuQuitStatus; 
int textStatus = 0; 
int menuBeginnerStatus;
int menuIntermediateStatus;
int menuExpertStatus;
int menuBackToMenuStatus;
int menuClassicThemeStatus;
int menuEmojiThemeStatus; 
