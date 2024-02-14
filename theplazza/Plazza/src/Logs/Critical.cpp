#include <chrono>
#include "Critical.hpp"
#include "Log.hpp"

Critical::Critical(const std::string &w_msg) : log_file(Log("logs/" + Critical::Log::format_timestamp(std::chrono::system_clock::now(), "%Y-%m-%d") + ".log"))
{
    this->log_file.write_error(Log::CRITICAL, w_msg);
    this->msg = "[CRITICAL] " + w_msg;
}

const char* Critical::what() const noexcept
{
    return this->msg.c_str();
}


Critical::~Critical()
{
}
