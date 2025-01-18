#include "../include/library.h"

#include <iostream>

namespace message_logger {
    const std::vector<std::string> FileLogger::levels = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR",
            "CRITICAL"
    };

    FileLogger::FileLogger(std::string file_name, MessageLevel default_level) :
            file_name(std::move(file_name)),
            default_level(default_level) {

    }

    void FileLogger::setDefaultLevel(MessageLevel level) {
        default_level = level;
    }

    FileLogger::MessageLevel FileLogger::getDefaultLevel() const noexcept {
        return default_level;
    }
}

