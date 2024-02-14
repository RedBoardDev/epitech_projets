#include "../includes/SDLEncaps.hpp"
#include <dirent.h>



static std::string findAFont()
{
    DIR *dir;
    struct dirent *ent;
    std::string tmp;
    std::string path;

    DIR *indir;
    struct dirent *inent;

    if ((dir = opendir("/usr/share/fonts")) == NULL) {
        exit(84);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            tmp = "/usr/share/fonts/";
            tmp += ent->d_name;
            if (tmp != "." && tmp != ".." && (indir = opendir(tmp.c_str())) != NULL) {
                path = tmp.c_str();
                path += "/";
                while ((inent = readdir(indir)) != NULL) {
                    if (inent->d_type == DT_REG) {
                        tmp = inent->d_name;
                        if (tmp.find(".ttf") != std::string::npos) {
                            path += tmp;
                            closedir(indir);
                            closedir(dir);
                            return path;
                        }
                    }
                }
                closedir(indir);
            }
        }
    }
    closedir(dir);
    exit(84);
}
SDLEncaps::SDLEncaps(int winX, int winY)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer(winX, winY, SDL_WINDOW_FULLSCREEN, &(this->win), &(this->renderer));
    this->screen = SDL_GetWindowSurface(this->win);
    this->timeBetweenFrames = 16;
    this->font = TTF_OpenFont("/usr/share/fonts/dejavu-sans-fonts/DejaVuSans.ttf", 20);
    this->lastFrame = NOW;

    if (!this->font)
        this->font = TTF_OpenFont(findAFont().c_str(), 20);
    if (!this->font)
        exit(84);


}

SDLEncaps::~SDLEncaps()
{
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void SDLEncaps::putPixel(int x, int y, unsigned int color)
{
    Uint32 *pixel = (Uint32 *) ((Uint8 *) this->screen->pixels + y * this->screen->pitch + x * this->screen->format->BytesPerPixel);
    *pixel = SDL_MapRGBA(this->screen->format,(color >> 24) % 256, (color >> 16) % 256, (color >> 8) % 256, color % 256);
}

static bool isInEvents(std::vector<Arcade::Graphics::IDisplayModule::Events> events, Arcade::Graphics::IDisplayModule::Events event)
{
    for (int i = 0; i < events.size(); ++i) {
        if (events[i] == event)
            return true;
    }
    return false;
}

std::vector<Arcade::Graphics::IDisplayModule::Events> SDLEncaps::getEvents()
{
    SDL_Event event;
    Arcade::Graphics::IDisplayModule::Events tmp;
    bool pass = false;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            if (event.key.keysym.sym >= SDLK_a || event.key.keysym.sym <= SDLK_z) {
                tmp = (Arcade::Graphics::IDisplayModule::Events) (event.key.keysym.sym - 97);
                pass = true;
            }
            if (event.key.keysym.sym >= SDLK_KP_1 && event.key.keysym.sym <= SDLK_KP_0) {
                tmp = (Arcade::Graphics::IDisplayModule::Events) (event.key.keysym.sym - SDLK_KP_1 + 30);
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_LEFT) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyLeft;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyRight;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_UP) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyUp;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyDown;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_SPACE) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keySpace;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyEscape;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_KP_ENTER || event.key.keysym.sym == SDLK_RETURN) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyEnter;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                tmp = Arcade::Graphics::IDisplayModule::Events::keyEscape;
                pass = true;
            }
            if (event.key.keysym.sym == SDLK_BACKSPACE) {
                tmp = Arcade::Graphics::IDisplayModule::Events::backSpace;
                pass = true;
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                tmp = Arcade::Graphics::IDisplayModule::Events::leftClic;
                pass = true;
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                tmp = Arcade::Graphics::IDisplayModule::Events::rightClic;
                pass = true;
            }
        }
        if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN) {
            if (pass && !isInEvents(this->eventList, tmp))
                this->eventList.push_back(tmp);
        }
        if (event.type == SDL_KEYUP || event.type == SDL_MOUSEBUTTONUP) {
            if (pass) {
                for (auto i = this->eventList.begin(); i != this->eventList.end(); ++i) {
                    if ((*i) == tmp) {
                        this->eventList.erase(i);
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_QUIT) {
            exit(0);
            tmp = Arcade::Graphics::IDisplayModule::Events::close;
            if (!isInEvents(this->eventList, tmp))
                this->eventList.push_back(tmp);
        }
    }
    return this->eventList;
}

std::pair<int, int>SDLEncaps::getMousePos()
{
    SDL_GetMouseState(&(this->mousePos.first), &(this->mousePos.second));
    return this->mousePos;
}

void SDLEncaps::display()
{
    SDL_UpdateWindowSurface(this->win);

    if (this->timeBetweenFrames != 0) {
        while (NOW - this->lastFrame < this->timeBetweenFrames);
    }
    this->lastFrame = NOW;
}

void SDLEncaps::setFrameRateLimit(int limit)
{
    if (limit <= 0)
        return;
    int tmp = 1000 / limit;

    (tmp <= 0) ? (tmp = 1) : (0);
    this->timeBetweenFrames = tmp;
}

void SDLEncaps::putText(int x, int y, unsigned int color, const std::string &str)
{
    SDL_Surface *fontSurface = TTF_RenderText_Solid(this->font, str.c_str(), (SDL_Color){(Uint8)((color >> 24) % 256), (Uint8)((color >> 16) % 256),(Uint8)((color >> 8) % 256)});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = fontSurface->clip_rect.w;
    dest.h = fontSurface->clip_rect.h;
    SDL_BlitSurface(fontSurface , &(fontSurface->clip_rect), this->screen, &dest);
}