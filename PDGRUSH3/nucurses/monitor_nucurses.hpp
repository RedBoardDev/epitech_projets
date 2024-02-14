#pragma once
#include "../Geters.hpp"
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <functional>
#include <thread>

class Monitor : public Geters {
    public :
        Monitor();
        bool draw_box(const std::string& name, const std::string& text, int color, bool &is_update);
        void update_chart();
        void choose_module(int const &pressed);
        void destroy_box();
        void update_modules();
        enum content {
            NOTHING,
            CPU,
            RAM,
            DATE,
            NETWORK,
            PC_INFO
        };
        std::string get_infos(Monitor::content to_check);
        bool _t_running = true;
    private :
        void check_chart(int value, int box);
        void check_cpu(int box);
        void check_ram(int box);
        void check_network(int box);
        void set_chart(int value, int x, int y, int color);
        int _nb_box_placed;
        int _box[7];
        int _box_color[7];
        long unsigned int BOX_SIZE = 45;
        content _content_box[7];
        std::map<content, std::string> _name_content = {{NOTHING, ""}, {CPU, "CPU"}, {RAM, "RAM"},{DATE, "DATE"},{NETWORK, "NETWORK"},{PC_INFO, "PC INFORMATIONS"}};
};

void t_memory_available(Monitor &monitor);
void t_bandwith(Monitor &monitor);