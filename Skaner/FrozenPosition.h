//
// Created by Szymon Król on 15.03.2026.
//

#ifndef AGH_KOMPILATORY_FROZENPOSITION_H
#define AGH_KOMPILATORY_FROZENPOSITION_H
#include <cstddef>

#include "Scanner/Scanner.h"


class FrozenPosition {
    std::size_t line_;
    std::size_t pos_;
public:
    explicit FrozenPosition(const Position& pos) : line_(pos.get_line()), pos_(pos.get_pos()) {}
    FrozenPosition() : line_(), pos_() {}
    FrozenPosition(const std::size_t& line, const std::size_t& pos) : line_(line), pos_(pos) {}
    std::size_t get_line() const {return line_;}
    std::size_t get_pos() const {return pos_;}
};


#endif //AGH_KOMPILATORY_FROZENPOSITION_H