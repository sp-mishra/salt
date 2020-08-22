//
// Created by Misra, Shakti on 24/06/20.
//
#include <exception>
#include <string>
#include <utility>
#include <fmt/format.h>
#include "BaseException.hpp"

#pragma once
#ifndef EDB_STORAGEEXCEPTION_HPP
#define EDB_STORAGEEXCEPTION_HPP
namespace salt {
    class StorageException : public BaseException {
    public:
        template<typename... Args>
        StorageException(const char *format, Args... args) : BaseException(format, args) {
        }
    }
}

#endif //EDB_STORAGEEXCEPTION_HPP
