#include "../include/library.h"

#include <iostream>

namespace message_logger {
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

