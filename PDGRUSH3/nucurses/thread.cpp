#include "monitor_nucurses.hpp"
#include <exception>
#include <ratio>
#include <unistd.h>

void t_memory_available(Monitor &monitor)
{
    while (monitor._t_running) {
        monitor.s_memory_available();
        monitor.s_current_date();
        monitor.s_current_time();
        monitor.s_cpu_process_running();
        monitor.s_load_average();
        monitor.s_network_ping();
        monitor.s_cpu_temp();
        monitor.s_cpu_usage();
        monitor.s_uptime_seconds();
        monitor.s_network_ssid();
        sleep(1);
    }
}

void t_bandwith(Monitor &monitor)
{
    while (monitor._t_running)
        monitor.s_bandwidth();
}