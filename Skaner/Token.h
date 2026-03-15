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
    Empty,
    Error
};

class Token {
private:
    const TokenType type_;
    const std::string value_;
    const FrozenPosition pos_;

public:
    Token() = delete;

    Token(const TokenType type, const std::string &value, const Position &pos) : type_(type), value_(value), pos_(pos) {
    }

    std::string to_string() const {
        std::string res = "[";

        res += "Line " + std::to_string(pos_.get_line()) + ":" + std::to_string(pos_.get_pos());
        res += "] ";

        switch (type_) {
            case TokenType::SignPlus: res += "SignPlus";
                break;
            case TokenType::SignMinus: res += "SignMinus";
                break;
            case TokenType::SignStar: res += "SignStar";
                break;
            case TokenType::SignSlash: res += "SignSlash";
                break;
            case TokenType::NumberInteger: res += "NumberInteger";
                break;
            case TokenType::Identifier: res += "Identifier";
                break;
            case TokenType::LeftParen: res += "LeftParen";
                break;
            case TokenType::RightParen: res += "RightParen";
                break;
            case TokenType::Empty: res += "Empty";
                break;
            case TokenType::Error: res += "Error";
                break;
            default: res += "Unknown";
                break;
        }

        res += " ('" + value_ + "')";

        return res;
    }

    TokenType get_type() const {return type_;}

    friend std::ostream& operator<<(std::ostream& str, const Token& t) {
        str << t.to_string();
        return str;
    }
};

#endif //AGH_KOMPILATORY_TOKEN_H
