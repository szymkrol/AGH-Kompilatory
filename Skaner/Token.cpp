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
        case TokenType::LogicalAnd: res += "LogicalAnd";
            break;
        case TokenType::Ampersand: res += "Ampersand";
            break;
        case TokenType::LiteralBool: res += "LiteralBool";
            break;
        case TokenType::LiteralPtr: res += "LiteralPtr";
            break;
        case TokenType::KeywordIf: res += "KeywordIf";
            break;
        case TokenType::KeywordElse: res += "KeywordElse";
            break;
        case TokenType::KeywordWhile: res += "KeywordWhile";
            break;
        case TokenType::KeywordReturn: res += "KeywordReturn";
            break;
        case TokenType::KeywordFor: res += "KeywordFor";
            break;
        case TokenType::KeywordBreak: res += "KeywordBreak";
            break;
        case TokenType::KeywordContinue: res += "KeywordContinue";
            break;
        case TokenType::KeywordSwitch: res += "KeywordSwitch";
            break;
        case TokenType::KeywordCase: res += "KeywordCase";
            break;
        case TokenType::TypeVoid: res += "TypeVoid";
            break;
        case TokenType::TypeInt: res += "TypeInt";
            break;
        case TokenType::TypeFloat: res += "TypeFloat";
            break;
        case TokenType::TypeBoolean: res += "TypeBoolean";
            break;
        case TokenType::TypeString: res += "TypeString";
            break;
        case TokenType::TypeChar: res += "TypeChar";
            break;
        case TokenType::ShiftLeft: res += "ShiftLeft";
            break;
        case TokenType::LessEqual: res += "LessEqual";
            break;
        case TokenType::LessThan: res += "LessThan";
            break;
        case TokenType::ShiftRight: res += "ShiftRight";
            break;
        case TokenType::MoreEqual: res += "MoreEqual";
            break;
        case TokenType::MoreThan: res += "MoreThan";
            break;
        case TokenType::Equal: res += "Equal";
            break;
        case TokenType::Assign: res += "Assign";
            break;
        case TokenType::NotEqual: res += "NotEqual";
            break;
        case TokenType::Exclamation: res += "Exclamation";
            break;
        case TokenType::LogicalOr: res += "LogicalOr";
            break;
        case TokenType::Pipe: res += "Pipe";
            break;
        case TokenType::Comment: res += "Comment";
            break;
        case TokenType::CommentBlock: res += "CommentBlock";
            break;
        default: res += "Unknown";
            break;
    }

    res += " ('" + escape_string(value_) + "')";

    return res;
}