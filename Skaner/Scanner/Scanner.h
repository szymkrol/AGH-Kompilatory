//
// Created by Szymon Król on 12.03.2026.
//

#ifndef AGH_KOMPILATORY_SCANNER_H
#define AGH_KOMPILATORY_SCANNER_H
#include <iosfwd>
#include <istream>

class Token;
struct Position {
    Position() : line_(), pos_() {}
    Position(const std::size_t& line, const std::size_t& pos) : line_(line), pos_(pos) {}
    Position(const Position& other) : line_(other.line_), pos_(other.pos_) {}
    std::size_t get_line() const {return line_;}
    std::size_t get_pos() const {return pos_;}
    std::size_t increment_line() {
        pos_ = 0;
        return ++line_;
    }
    std::size_t increment_pos() {return ++pos_;}
private:
    std::size_t line_;
    std::size_t pos_;
};


class Scanner {
private:
    std::istream& str_;
    char get_non_whitespace();
    char peek() const;
    char get();
    Position position_;
    static bool can_be_identifier_body(const char& c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9');
    }
    std::string read_whitespace();
    std::string read_range(const char begin, const char end);
    std::string read_float_after_decimal();
    std::string read_until(const char c);
public:
    explicit Scanner(std::istream& str) : str_(str) {}
    Token scan();

};


#endif //AGH_KOMPILATORY_SCANNER_H