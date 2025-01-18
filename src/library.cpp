#include "../include/library.h"

#include <iostream>

namespace message_logger {
    FileLogger::FileLogger(const std::string &file_name,
                           message_logger::FileLogger::MessageLevel default_level) :
            file_name(file_name),
            default_level(default_level) {}

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

