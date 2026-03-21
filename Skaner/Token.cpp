//
// Created by szymon on 21.03.2026.
//
#include "Token.h"
std::string Token::escape_string(const std::string &str) {
    std::string out;
    for (const char c: str) {
        switch (c) {
            case '\n': out += "\\n";
                break;
            case '\t': out += "\\t";
                break;
            case '\r': out += "\\r";
                break;
            case '\\': out += "\\\\";
                break;
            case '\"': out += "\\\"";
                break;
            default: out += c;
                break;
        }
    }
    return out;
}

std::string Token::to_string() const {
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
        case TokenType::NumberIntegerDecimal: res += "NumberInteger";
            break;
        case TokenType::Identifier: res += "Identifier";
            break;
        case TokenType::LeftParen: res += "LeftParen";
            break;
        case TokenType::RightParen: res += "RightParen";
            break;
        case TokenType::Whitespace: res += "Whitespace";
            break;
        case TokenType::Empty: res += "Empty";
            break;
        case TokenType::EndOfFile: res += "EOF";
            break;
        case TokenType::Error: res += "Error";
            break;
        default: res += "Unknown";
            break;
    }

    res += " ('" + escape_string(value_) + "')";

    return res;
}