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

    void FileLogger::logMessage(FileLogger::MessageLevel level, const std::string &message) {
        if (level < default_level) return;
        std::ofstream fout(file_name, std::ios::app | std::ios::out);
        if (!fout.is_open()) {
            std::ostringstream os;
            os << "File " << file_name << " was not open";
            throw std::runtime_error(os.str());
        }
        auto now = std::time(nullptr);
        auto tm = *std::localtime(&now);
        fout << levels[static_cast<int>(level)];
        fout << "[" << std::put_time(&tm, "%d.%m.%Y %H:%M:%S") << "]: ";
        fout << message << '\n';
        fout.close();
    }
}

