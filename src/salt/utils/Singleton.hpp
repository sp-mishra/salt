//
// Created by Misra, Shakti on 25/06/20.
//

#ifndef EDB_SINGLETON_HPP
#define EDB_SINGLETON_HPP

#include "NonCopyable.hpp"

namespace salt {
    /////////////////////////////////////////////////
    /// @class Singleton
    /// @brief Helper class to create a singleton.
    /// @details Example usage:
    ///          struct MakeMeSingleton : public ::blib::Singleton<MakeMeSingleton>
    ///          {};
    /////////////////////////////////////////////////
    template<class T>
    class Singleton : public NonCopyable {
    public:
        static T &i() {
            static T _me;
            return _me;
        }
    };
}

#endif //EDB_SINGLETON_HPP
