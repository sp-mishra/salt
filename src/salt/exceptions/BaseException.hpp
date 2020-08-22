//
// Created by Misra, Shakti on 24/06/20.
//
#pragma once
#ifndef EDB_BASEEXCEPTION_HPP
#define EDB_BASEEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>
#include <fmt/format.h>

namespace salt {
    using namespace std;

    class BaseException : public std::exception {
    private:
        string _msg;

    public:
        template<typename... Args>
        BaseException(const char *format, Args... args) {
            fmt::format(format, forward<Args>(args)...);
        }

        virtual const char *what() const throw() {
            return _msg.c_str();
        }
    };
}

#endif //EDB_BASEEXCEPTION_HPP
