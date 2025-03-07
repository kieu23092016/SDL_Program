// Tên Hieu 
#include "graphic.h"
SDL_Texture* Graphic::loadTexture(const char* filename) {
    SDL_Surface* load_surface = IMG_Load(filename);
    return SDL_CreateTextureFromSurface(renderer, load_surface);
}

// TRUONG QUANG HOANH
void Graphic::renderTexture(SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Rect src = {0, 0, w, h};
    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}
//Duong
void Graphic::quitSDL()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

// chi minh
void Graphic::logErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    quitSDL();
}

//Duy Manh
void Graphic::initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE){
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        logErrorAndExit("SDL_Init", SDL_GetError());
    }
    
    window = SDL_CreateWindow(WINDOW_TITLE, 
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
         SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());
    
}

// Binh
void Graphic::prepareSence() {
    SDL_RenderClear(renderer);
}
// phuc khanh
void Graphic::presentSence(){
    SDL_RenderPresent(renderer);
}