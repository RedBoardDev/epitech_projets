#include "monitor_nucurses.hpp"
#include <cstdlib>
#include <curses.h>
#include <string>

Monitor::Monitor()
{
    content tmp_content = NOTHING;
    _nb_box_placed = 0;
    for (int i = 0; i < 6; ++i) {
        _box[i] = 0;
        _box_color[i] = 0;
        _content_box[i] = tmp_content;

    }
}

void Monitor::set_chart(int value, int x, int y, int color)
{
    attron(COLOR_PAIR(color));
    for (int i = y; i > y - value; --i)
        mvprintw(i, x, " ");
    attroff(COLOR_PAIR(color));
}

std::string Monitor::get_infos(Monitor::content to_check)
{

    if (to_check == DATE)
        return "Current Date : " + g_current_date() + "\nCurrent time : " + g_current_time() + "\nPc is running since " + g_uptime_seconds() + " Seconds\n";
    if (to_check == PC_INFO)
        return "Kernel Version : " + g_kernel_version() + "\nName of the System : " + g_sysname() + "\nActual user : " + g_computer_name() + "\nName of the computer : " + g_user() + "\n";
    if (to_check == CPU)
        return "Model of the CPU : " + g_cpu_model_name() + "\nActual Usage : " + g_cpu_usage() + " %\nNumber of core : "+ g_cpu_nbr_core() + "\nNumber of process Running : " + g_cpu_process_running() + "\nTemperture : " + g_cpu_temp() + "°C";
    if (to_check == RAM)
        return "Total RAM Available : " + g_memory_total() + " GB\nRam used : " + g_memory_available() + " GB\n";
    if (to_check == NETWORK)
        return "Name of the Network : " + g_network_ssid() + "Ping : " + g_network_ping() + "Hostname : " + g_hostname() + "\nBandwdith : " + g_bandwidth();
    return "";
}

void Monitor::update_modules()
{
    int swap = _nb_box_placed;
    bool is_true = true;
    for (int i = 0; i < 6; ++i)
        if (_content_box[i] != NOTHING) {
            _nb_box_placed = i;
            draw_box(_name_content[_content_box[i]], get_infos(_content_box[i]), _box_color[i], is_true);
        }
    _nb_box_placed = swap;
}

void Monitor::choose_module(int const &pressed)
{
    bool is_false  = false;
    if (pressed == 'c') {
        _content_box[_nb_box_placed] = CPU;
        draw_box(_name_content[CPU], "", 12, is_false);
    }
    if (pressed == 'r') {
        _content_box[_nb_box_placed] = RAM;
        draw_box(_name_content[RAM], "", 1, is_false);
    }
    if (pressed == 'd') {
        _content_box[_nb_box_placed] = DATE;
        draw_box(_name_content[DATE], "", 2, is_false);
    }
    if (pressed == 'n') {
        _content_box[_nb_box_placed] = NETWORK;
        draw_box(_name_content[NETWORK], "", 7, is_false);
    }
    if (pressed == 'p') {
        _content_box[_nb_box_placed] = PC_INFO;
        draw_box(_name_content[PC_INFO], "", 13, is_false);
    }
    if (pressed == 'e')
        destroy_box();
}

void Monitor::check_chart(int value, int box)
{
    long unsigned int widht = 20;
    long unsigned int height = 0;
    if (box == 1 || box == 3)
        height = BOX_SIZE * 1.5;
    if (box == 2 || box == 3 || box == 5)
        widht = BOX_SIZE / 2 + 20;
    if (box == 4 || box == 5)
        height = (BOX_SIZE * 2) * 1.5;
    if (_box[box] >= 60) {
        for (int i = 0; i < 60; ++i)
            set_chart(15, height + i, widht, _box_color[box]);
        _box[box] = 0;
        return;
    }
    set_chart(value, height + _box[box], widht, 0);
    _box[box]++;
}

void Monitor::check_cpu(int box)
{
    int cores = std::atoi(g_cpu_nbr_core().c_str());
    int lenght = 0;
    long unsigned int widht = 8;
    long unsigned int height = 0;
    if (box == 1 || box == 3)
        height = BOX_SIZE * 1.5;
    if (box == 2 || box == 3 || box == 5)
        widht = BOX_SIZE / 2 + 8;
    if (box == 4 || box == 5)
        height = (BOX_SIZE * 2) * 1.5;
    for (int i = 1; i < cores + 1; i++) {
        _threadArray.at(i).s_thread_usage(i);
        attron(COLOR_PAIR(_box_color[box]));
        mvprintw(widht + i, height, "thread: %d", i);
        for (int j = 0; j < 50; ++j)
            mvprintw(widht + i, height + j + 11, " ");
        attroff(COLOR_PAIR(_box_color[box]));
        lenght = std::atof(_threadArray.at(i).g_thread_usage().c_str()) * 0.6;
        attron(0);
        for (int j = 0; j < lenght; ++j)
            mvprintw(widht + i, height + j + 11, " ");
        attroff(0);

    }
}

void Monitor::check_ram(int box)
{
    float value = (std::stof(g_memory_available())) * 1;
    check_chart(value, box);
}

void Monitor::check_network(int box)
{
    std::string str = this->g_bandwidth();
    std::stringstream ss(str);
    float num1;
    ss >> num1;
    if (num1 > 4)
        num1 = 4;
    else if (num1 < 0.5)
        num1 = 0.5;
    num1 *= 3;
    check_chart(num1, box);
}

void Monitor::update_chart()
{
    for (int i = 0; i < 6; ++i) {
        if (_content_box[i] == CPU)
            check_cpu(i);
        if (_content_box[i] == RAM)
            check_ram(i);
        if (_content_box[i] == NETWORK)
            check_network(i);
    }
}

void Monitor::destroy_box()
{
    int widht = 0;
    int height = 0;
    if (_nb_box_placed <= 0)
        return;
    if (_nb_box_placed == 2 || _nb_box_placed == 4)
        height = BOX_SIZE * 1.5;
    if (_nb_box_placed == 3 || _nb_box_placed == 4 || _nb_box_placed == 6)
        widht = BOX_SIZE / 2;
    if (_nb_box_placed == 5 || _nb_box_placed == 6)
        height = (BOX_SIZE * 2) * 1.5;
    --_nb_box_placed;
    _box_color[_nb_box_placed] = 0;
    _content_box[_nb_box_placed] = NOTHING;
    attron(COLOR_PAIR(0));
    mvprintw(widht, height, " ");
    for (long unsigned int i = 0; i < BOX_SIZE / 2; ++i) {
        mvprintw(widht + i, height, " ");
        for (long unsigned int j = 0; j < BOX_SIZE * 1.5; ++j)
            printw(" ");
    }
    attroff(COLOR_PAIR(0));
}

bool Monitor::draw_box(const std::string& name, const std::string& text, int color, bool &is_update)
{
    int widht = 0;
    int height = 0;
    std::istringstream ss(text);
    std::string line;
    long unsigned int length = BOX_SIZE + 1 - name.length();
    long unsigned int sec_lenght = (length / 2.0) * 1.5;
    length = sec_lenght;
    if (_nb_box_placed > 5) {
        _nb_box_placed = 6;
        return false;
    }
    if (_nb_box_placed == 1 || _nb_box_placed == 3)
        height = BOX_SIZE * 1.5;
    if (_nb_box_placed == 2 || _nb_box_placed == 3 || _nb_box_placed == 5)
        widht = BOX_SIZE / 2;
    if (_nb_box_placed == 4 || _nb_box_placed == 5)
        height = (BOX_SIZE * 2) * 1.5;
    if (!is_update) {
        _box_color[_nb_box_placed] = color;
        _nb_box_placed++;
    }
    attron(COLOR_PAIR(color));
    mvprintw(widht, height, " ");
    for (long unsigned int i = 0; i < length; ++i)
        printw(" ");
    printw("%s", name.c_str());
    for (long unsigned int i = 0; i < sec_lenght + 1; ++i)
        printw(" ");
    for (long unsigned int i = 1; i < BOX_SIZE / 2; ++i) {
        if (i == 1 || !std::getline(ss, line, '\n')) {
            if (i != 1 && is_update) {
                attroff(COLOR_PAIR(color));
                return true;
            }
            line = "";
        }
        mvprintw(widht + i, height, " ");
        for (long unsigned int j = 0; j < line.length(); ++j)
            printw("%c", line[j]);
        for (long unsigned int j = line.length(); j < BOX_SIZE * 1.5; ++j)
            printw(" ");
    }
    attroff(COLOR_PAIR(color));
    return true;
}
