//
// Created by Misra, Shakti on 24/06/20.
//
#pragma once
#ifndef EDB_PARSEREXCEPTION_HPP
#define EDB_PARSEREXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>
#include <fmt/format.h>
#include "BaseException.hpp"

namespace salt {
    class ParseException : public BaseException {
    public:
        template<typename... Args>
        ParseException(const char *format, Args &&... args) : BaseException(format, forward<Args>(args)...) {
        }
    };
}

#endif //EDB_PARSEREXCEPTION_HPP
