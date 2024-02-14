#pragma once

#include <iostream>

#include "nucurses/monitor_nucurses.hpp"
#include "SFML/IGraphic.hpp"

class IMonitorDisplay {
    public :
        enum DisplayType {
            NCURSES,
            SFML
        };
        void choose_launch(DisplayType type);
        void launch_terminal(void);
        void launch_SFML(void);
};

void main_ncurses(void);
void main_SFML();
