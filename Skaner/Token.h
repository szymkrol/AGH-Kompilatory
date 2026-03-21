//
// Created by Szymon Król on 12.03.2026.
//

#ifndef AGH_KOMPILATORY_TOKEN_H
#define AGH_KOMPILATORY_TOKEN_H

#include <string>

#include "FrozenPosition.h"

enum class TokenType {
    SignPlus,
    SignMinus,
    SignStar,
    SignSlash,
    NumberInteger,
    Identifier,
    LeftParen,
    RightParen,
    Whitespace,
    Empty,
    EndOfFile,
    Error
};

class Token {
private:
    const TokenType type_;
    const std::string value_;
    const FrozenPosition pos_;

    static std::string escape_string(const std::string &str);

public:
    Token() = delete;

    Token(const TokenType type, const std::string &value, const Position &pos) : type_(type), value_(value), pos_(pos) {
    }

    [[nodiscard]] std::string to_string() const;

    [[nodiscard]] TokenType get_type() const { return type_; }

    friend std::ostream &operator<<(std::ostream &str, const Token &t) {
        str << t.to_string();
        return str;
    }
};

#endif //AGH_KOMPILATORY_TOKEN_H
