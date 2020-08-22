//
// Created by Misra, Shakti on 29/06/20.
//
#pragma once
#ifndef EDB_FILESYSTEMUTILITIES_HPP
#define EDB_FILESYSTEMUTILITIES_HPP

#include <filesystem>
#include <fstream>
#include <sstream>
//#include <fast_io_device.h>
#include "models/Status.hpp"

namespace salt {
    class FileSystemUtilities {
    public:
        static Status readFileToString(filesystem::path const& path, string& content) {
            namespace fs = filesystem;
            Status status;
            if(fs::exists(path) && fs::is_regular_file(path)) {
                const ifstream file(path);
                if(file.good()) {
                    auto ss = ostringstream{};
                    ss << file.rdbuf();
                    content = ss.str();
                    status.setMessage(Consts::SUCCESS);
                    status.setSuccess(true);
                }
            }
            return status;
        }
    };
}
#endif //EDB_FILESYSTEMUTILITIES_HPP
