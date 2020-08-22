//
// Created by Misra, Shakti on 25/06/20.
//

#ifndef EDB_NONCOPYABLE_HPP
#define EDB_NONCOPYABLE_HPP

namespace salt {
    class NonCopyable {
    protected:
        constexpr NonCopyable() = default;

        ~NonCopyable() = default;

        NonCopyable(const NonCopyable &) = delete;

        NonCopyable &operator=(const NonCopyable &) = delete;
    };
}

#endif //EDB_NONCOPYABLE_HPP
