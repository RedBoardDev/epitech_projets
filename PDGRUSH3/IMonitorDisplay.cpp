#include "IMonitorDisplay.hpp"


void IMonitorDisplay::choose_launch(DisplayType type)
{
    if (type == NCURSES)
        launch_terminal();
    else
        launch_SFML();
}

void IMonitorDisplay::launch_terminal(void)
{
    return main_ncurses();
}

void IMonitorDisplay::launch_SFML(void)
{
    return main_SFML();
}
