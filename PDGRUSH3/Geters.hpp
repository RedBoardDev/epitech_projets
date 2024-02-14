#pragma once

#include <sys/utsname.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <sstream>
#include <sys/sysinfo.h>
#include <vector>
#include "UtilsGeters.hpp"
#include "ThreadUsage.hpp"
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <cstring>
#include <netdb.h>

class Geters: virtual public UtilsGeters, public ThreadUsage {
    public :
        Geters();
        ~Geters();
        std::string g_kernel_version() const { return (_kernelVersion); };
        std::string g_sysname() const { return (_sysName); };
        std::string g_user() const { return (_user); };
        std::string g_computer_name() const { return (_computerName); };
        std::string g_memory_available() const { return (_memoryAvailable); };
        std::string g_memory_total() const { return (_memoryTotal); };
        std::string g_current_date() const { return (_currentDate); };
        std::string g_current_time() const { return (_currentTime); };
        std::string g_cpu_process_running() const { return (_cpuProcessRunning); };
        std::string g_cpu_nbr_core() const { return (_cpuNbrCore); };
        std::string g_cpu_model_name() const { return (_cpumodelName); };
        std::string g_uptime_seconds() const { return (_uptimeSeconds); };
        std::string g_load_average() const { return (_loadAverage); };
        std::string g_network_ping() const { return (_networkPing); };
        std::string g_network_ssid() const { return (_networkSSID); };
        std::string g_cpu_usage() const { return (_cpuUsage); };
        std::string g_hostname() const { return (_hostName); };
        std::string g_cpu_temp() const { return (_cpuTemp); };
        std::string g_bandwidth() const { return (_bandwidth); };

        void s_kernel_version();
        void s_sysname();
        void s_user();
        void s_computer_name();
        void s_memory_available();
        void s_memory_total();
        void s_current_date();
        void s_current_time();
        void s_cpu_process_running();
        void s_cpu_nbr_core();
        void s_cpu_model_name();
        void s_uptime_seconds();
        void s_load_average();
        void s_network_ping();
        void s_network_ssid();
        void s_cpu_usage();
        void s_hostname();
        void s_cpu_temp();
        void s_bandwidth();
        ThreadUsage _threadClass;
        std::vector<ThreadUsage> _threadArray;

    private:
        std::string _kernelVersion;
        std::string _sysName;
        std::string _user;
        std::string _computerName;
        std::string _memoryAvailable;
        std::string _memoryTotal;
        std::string _currentDate;
        std::string _currentTime;
        std::string _cpuProcessRunning;
        std::string _cpuNbrCore;
        std::string _cpumodelName;
        std::string _uptimeSeconds;
        std::string _loadAverage;
        std::string _networkPing;
        std::string _networkSSID;
        std::string _cpuUsage;
        std::string _hostName;
        std::string _cpuTemp;
        std::string _bandwidth;
};
