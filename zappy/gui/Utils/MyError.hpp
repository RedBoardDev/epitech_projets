#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <ctime>

namespace ZappyGui {
    /**
     * @brief Log a message to a file
     *
     * @param message Message to log
     * @param type Type of the log (default: "LOG")
     */
    void log(const std::string &message, const std::string &type = "LOG");

    /**
     * @brief Custom error class that logs error to a file
     *
     */
    class MyError: public std::exception {
        public:
            /**
             * @brief Construct a new MyError object
             *
             * @param message Message to log
             * @param logToFile Log to file or not (default: true)
             * @param errorType Type of the error (default: "ERROR")
             */
            MyError(const std::string &className, const std::string &message, bool logToFile = true, const std::string &errorType = "ERROR");
            virtual const char *what() const noexcept override;

        protected:
            std::string _msg;
    };
}
    