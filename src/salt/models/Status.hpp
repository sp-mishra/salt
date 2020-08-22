//
// Created by Misra, Shakti on 28/06/20.
//
#pragma once
#ifndef EDB_STATUS_HPP
#define EDB_STATUS_HPP

#include <string>
#include <fmt/format.h>
#include "constants/Consts.hpp"

namespace salt {
    using namespace std;

    class Status {
    private:
        bool _isSuccess{false};
        string _message{Consts::FAILURE};

    public:
        Status() = default;

        Status(const bool isSuccess, string const &&message) : _isSuccess(isSuccess), _message(message) {}

        virtual ~Status() = default;

        [[nodiscard]] bool ok() const {
            return isSuccess();
        }

        [[nodiscard]] bool isSuccess() const {
            return _isSuccess;
        }

        void setSuccess(const bool isSuccess) {
            _isSuccess = isSuccess;
        }

        [[nodiscard]] string const &getMessage() const {
            return _message;
        }

        void setMessage(string const &message) {
            _message = message;
        }

        template<typename... Args>
        void setMessage(string const& format, Args... args) {
            _message = fmt::format(format, forward<Args>(args)...);
        }
    };
}
#endif //EDB_STATUS_HPP
