//
// Created by Szymon Król on 12.03.2026.
//

#ifndef AGH_KOMPILATORY_TOKEN_H
#define AGH_KOMPILATORY_TOKEN_H

#include <string>

enum class TokenType {
    SignPlus,
    SignMinus,
    SignStar,
    SignSlash,
    NumberInteger,
    LeftParen,
    RightParen
};

class Token {
    const TokenType type;
    const std::string value;
    Token() = delete;
    Token(const TokenType type_, const std::string& value_) : type(type_), value(value_) {}
};


#endif //AGH_KOMPILATORY_TOKEN_H
