#include "monitor_nucurses.hpp"
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <thread>

void loop_ncurses(void)
{
    int pressed = 0;
    Monitor monitor;
    monitor.s_memory_total();
    std::thread memory_available(t_memory_available, std::ref(monitor));
    std::thread bandwidth(t_bandwith, std::ref(monitor));
    monitor.s_kernel_version();
    monitor.s_sysname();
    monitor.s_user();
    monitor.s_computer_name();
    monitor.s_cpu_nbr_core();
    monitor.s_cpu_model_name();
    monitor.s_hostname();
    while (pressed != 'q') {
        monitor.update_modules();
        monitor.choose_module(pressed);
        monitor.update_chart();
        pressed = getch();
    }
    monitor._t_running = false;
    memory_available.join();
    bandwidth.join();
}

void main_ncurses(void)
{
    srand(time(NULL));
    initscr();
    start_color();
    noecho();
    timeout(500);
    init_color(COLOR_RED, 900, 372, 272);
    init_color(2, 544, 704, 296);
    init_color(3, 780, 272, 488);
    curs_set(0);
    for (int i = 0; i < 50; ++i)
        init_pair(i, !i ? COLOR_WHITE : COLOR_BLACK, i);
    loop_ncurses();
    endwin();
}