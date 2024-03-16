// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <iostream>

/**
 * A wrapper around output logging.
 *
 * @code
 * Log << "test\n";
 * @endcode
 */
class Logger {
    /** The output stream to log to. */
    std::ostream& out;

public:
    bool is_enabled = true;

    /** The global logger instance. */
    static Logger& main() {
        static Logger instance(std::cerr);
        return instance;
    }

    /** Constructs a new Logger that logs to `out`. */
    Logger(std::ostream& out): out(out) {}

    /** Logs `val`. */
    template<typename T>
    Logger& operator<<(T val) {
        if (is_enabled) {
#ifndef RELEASE_BUILD
            out << val;
#endif
        }
        return *this;
    }
};

// See Logger::main
#define Log Logger::main()
