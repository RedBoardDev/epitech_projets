#include "Error.hpp"

Error::Error(const std::string &w_msg) : log_file(Log("logs/" + Error::Log::format_timestamp(std::chrono::system_clock::now(), "%Y-%m-%d") + ".log"))
{
    this->log_file.write_error(Log::ERROR, w_msg);
    this->msg = "[ERROR] " + w_msg;
}

const char* Error::what() const noexcept
{
    return this->msg.c_str();
}


Error::~Error()
{
}
