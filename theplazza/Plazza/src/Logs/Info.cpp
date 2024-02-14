#include "Info.hpp"

Info::Info(const std::string &w_msg) : log_file(Log("logs/" + Info::Log::format_timestamp(std::chrono::system_clock::now(), "%Y-%m-%d") + ".log"))
{
    this->log_file.write_error(Log::INFO, w_msg);
    this->msg = "[INFO] " + w_msg;
    std::cout << this->msg << std::endl;
}

const char* Info::what() const noexcept
{
    return this->msg.c_str();
}


Info::~Info()
{
}
