//
// Created by Misra, Shakti on 27/06/20.
//

#pragma once
#ifndef EDB_OPTIONS_HPP
#define EDB_OPTIONS_HPP

#include <map>
#include <string>
#include <constants/Consts.hpp>

namespace salt {
    using namespace std;

    class Options {
    private:
        map<string, string> _options;

    public:
        Options() = default;

        Options(Options const &other) {
            _options.clear();
            addOptions(other._options);
        }

        Options const &operator=(Options const &other) {
            addOptions(other._options);
            return *this;
        }

        void putValue(string const &key, string const &value, const bool updateOnlyIfNotExists = false) {
            if (false == updateOnlyIfNotExists) {
                _options.emplace(key, value);
            } else {
                _options.try_emplace(key, value);
            }
        }

        string const &getValue(string const &key, string const &defaultValue = Consts::EMPTY) {
            const auto it = _options.find(key);
            return _options.end() != it ? it->second : defaultValue;
        }

        bool removeValue(string const &key) {
            const auto elementsRemoved = _options.erase(key);
            return elementsRemoved > 0;
        }

        void addOptions(map<string, string> const &options) {
            for (auto const &o : options) {
                _options.emplace(o);
            }
        }

        bool hasValue(string const &key) {
            const auto it = _options.find(key);
            return _options.end() == it ? false : true;
        }

        void reset() {
            _options.clear();
        }

        bool empty() const {
            return _options.empty();
        }
    };
}
#endif //EDB_OPTIONS_HPP
