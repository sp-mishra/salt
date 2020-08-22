//
// Created by Misra, Shakti on 28/06/20.
//
#pragma once
#ifndef EDB_CONSTS_HPP
#define EDB_CONSTS_HPP

#include <string>

namespace salt {
    using namespace std;
    struct Consts {
        inline static string const EXISTS = "EXISTS";
        inline static string const SUCCESS = "SUCCESS";
        inline static string const FAILURE = "FAILURE";
    };
}
#endif //EDB_CONSTS_HPP
