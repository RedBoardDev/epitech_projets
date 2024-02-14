#include "Geters.hpp"

Geters::Geters()
{
    for (int i = 0; i < 15; ++i)
        this->_threadArray.push_back(this->_threadClass);
}

Geters::~Geters() {}

void Geters::s_kernel_version()
{
    struct utsname tmp;
    if (uname(&tmp))
        _kernelVersion = "";
    std::string result(tmp.release);
    _kernelVersion = result;
}

void Geters::s_sysname()
{
    struct utsname tmp;
    if (uname(&tmp))
        _sysName = "";
    std::string result(tmp.sysname);
    _sysName = result;
}

void Geters::s_memory_total()
{

    const char *meminfo_file = "/proc/meminfo";

    double factor = 1024 * 1024;
    std::ifstream ifs = std::ifstream{meminfo_file};

    std::string line, label;
	std::uint64_t value;
    while (std::getline(ifs, line)) {
        std::stringstream ss{line};
        ss >> label >> value;

        if (label == "MemTotal:") {
            _memoryTotal = std::to_string(value / factor);
            return;
        }
    }
    _memoryTotal = "";
}

void Geters::s_memory_available()
{

    const char *meminfo_file = "/proc/meminfo";

    double factor = 1024 * 1024;
    std::ifstream ifs = std::ifstream{meminfo_file};

    std::string line, label;
	std::uint64_t value;
    while (std::getline(ifs, line)) {
        std::stringstream ss{line};
        ss >> label >> value;

        if (label == "MemAvailable:") {
            _memoryAvailable = std::to_string( std::stof(_memoryTotal.c_str()) - (value / factor));
            return;
        }
    }
    _memoryAvailable = "";
}

void Geters::s_user()
{
    char hostname[HOST_NAME_MAX];
    if (gethostname(hostname, HOST_NAME_MAX))
        _user = "";
    _user = hostname;
}

void Geters::s_computer_name()
{
    char username[LOGIN_NAME_MAX];
    if (getlogin_r(username, LOGIN_NAME_MAX))
        _computerName = "";
    _computerName = username;
}

void Geters::s_current_date()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    _currentDate = buf;
}

void Geters::s_current_time()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);
    _currentTime = buf;
}

void Geters::s_cpu_process_running()
{
    struct sysinfo info;
	::sysinfo(&info);

    _cpuProcessRunning = std::to_string(info.procs);
}

void Geters::s_cpu_nbr_core()
{
    int i = 0;

    const char *meminfo_file = "/proc/cpuinfo";
    std::ifstream ifs = std::ifstream{meminfo_file};

    std::string line, label;
	std::uint64_t value;
    while (std::getline(ifs, line)) {
        std::stringstream ss{line};
        ss >> label >> value;

        if (label == "processor")
            ++i;
    }
    _cpuNbrCore = std::to_string(i);
}

void Geters::s_cpu_model_name()
{
    std::string line = this->readFile("/proc/cpuinfo", 5);
    line = line.substr(13);
    _cpumodelName = line;
}

void Geters::s_uptime_seconds()
{
    std::ifstream ifs = std::ifstream("/proc/uptime");
	double seconds;
	ifs >> seconds;
    _uptimeSeconds = std::to_string(seconds);
}

void Geters::s_load_average()
{
    std::string loadavg = this->readFile("/proc/loadavg", 1);
    loadavg = loadavg.substr(0, loadavg.find("/"));
    loadavg = loadavg.substr(0, loadavg.size()- 2);
    _loadAverage = (loadavg);
}

void Geters::s_network_ping()
{
    FILE *cmd=popen("ping -i 0.02 -c 2 google.com | grep mdev | cut -d '=' -f 2 | cut -d '/' -f 4 | cut -d ' ' -f 1", "r");
    char result[24]={0x0};
    std::string str;
    while (fgets(result, sizeof(result), cmd) !=NULL)
           str = result;
    pclose(cmd);
    _networkPing = (str);
}

void Geters::s_network_ssid()
{
    FILE *cmd=popen("nmcli -t -f active,ssid dev wifi | grep '^yes' | cut -d: -f2", "r");
    char result[24]={0x0};
    std::string str;
    while (fgets(result, sizeof(result), cmd) !=NULL)
           str = result;
    pclose(cmd);
    _networkSSID = (str);
}

void Geters::s_cpu_usage()
{
    std::string line = this->readFile("/proc/stat", 1);
    std::array<long long, 10> columns{};
    sscanf(line.c_str(), "%*s %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &columns[0], &columns[1], &columns[2], &columns[3], &columns[4], &columns[5], &columns[6], &columns[7], &columns[8], &columns[9]);

    static std::array<long long, 10> last_columns{};
    std::array<long long, 10> delta{};
    for (int i = 0; i < 10; i++) {
        delta[i] = columns[i] - last_columns[i];
    }
    last_columns = columns;
    long long used_delta = delta[0] + delta[1] + delta[2] + delta[5] + delta[6] + delta[7];
    double usage = 100.0 * used_delta / (used_delta + (delta[3] + delta[4]));
    _cpuUsage = std::to_string(usage);
}

void Geters::s_hostname()
{

    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;
    char max_host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        _hostName = "";
        return;
    }
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;
        if (ifa->ifa_addr->sa_family == AF_INET && !strcmp(ifa->ifa_name, this->getNetworkInterface().c_str())) {
            getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), max_host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            _hostName = max_host;
            return;
        }
    }
    freeifaddrs(ifaddr);
}

void Geters::s_cpu_temp()
{
    std::string line = this->readFile("/sys/class/thermal/thermal_zone0/temp", 1);
    _cpuTemp = std::to_string(stoi(line) / 1000);
}

void Geters::s_bandwidth()
{
    std::string data1;
    std::string data2;
    float rx1, tx1, rx2, tx2, rx_diff, tx_diff;
    float waiting_time = 1;
    std::ifstream sfile("/proc/net/dev");

    std::string interf = this->getNetworkInterface();
    while (std::getline(sfile, data1)) {
        if (data1.find(interf.c_str()) < 10) {
            break;
        }
    }
    sscanf(data1.c_str(), "%*s %f %*d %*d %*d %*d %*d %*d %*d %f", &rx1, &tx1);
    sleep(waiting_time);
    sfile.clear();
    sfile.seekg(0, std::ios::beg);
    while (std::getline(sfile, data2)) {
        if (data2.find(interf.c_str()) < 10) {
            break;
        }
    }
    sscanf(data2.c_str(), "%*s %f %*d %*d %*d %*d %*d %*d %*d %f", &rx2, &tx2);
    rx_diff = rx2 - rx1;
    tx_diff = tx2 - tx1;
    float rx_rate = rx_diff / waiting_time;
    float tx_rate = tx_diff / waiting_time;
    _bandwidth = std::to_string(rx_rate / 8000) + " Kb/s | " + std::to_string(tx_rate / 8000) + " Kb/s";
}
