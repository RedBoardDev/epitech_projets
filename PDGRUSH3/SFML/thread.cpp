#include "sectionStatic.hpp"
#include <exception>
#include <ratio>
#include <unistd.h>

void t_memory_available(sectionStatic &section)
{
    t_bandwith(section);
    while (section._t_running) {
        section.get.s_memory_available();
        section.get.s_current_date();
        section.get.s_current_time();
        section.get.s_cpu_process_running();
        section.get.s_load_average();
        section.get.s_network_ping();
        section.get.s_cpu_temp();
        section.get.s_cpu_usage();
        section.get.s_uptime_seconds();
        sleep(1);
    }
}

void t_bandwith(sectionStatic &section)
{
    while (section._t_running)
        section.get.s_bandwidth();
}