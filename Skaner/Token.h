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
    NumberIntegerDecimal,
    NumberIntegerOctal,
    NumberIntegerHex,
    NumberIntegerBinary,
    NumberFloat,
    LiteralCharacter,
    LiteralString,
    LiteralBool,
    LiteralPtr,
    Identifier,
    LeftParen,
    RightParen,
    LeftBracket,
    RightBracket,
    LeftBrace,
    RightBrace,
    Comma,
    Semicolon,
    Colon,
    DoubleColon,
    Dot,
    Ellipsis,
    Whitespace,
    Empty,
    EndOfFile,
    Error,
    LogicalAnd,
    Ampersand,
    ShiftLeft,
    LessThan,
    ShiftRight,
    MoreThan,
    LessEqual,
    MoreEqual,
    KeywordIf,
    KeywordElse,
    KeywordWhile,
    KeywordReturn,
    KeywordFor,
    KeywordBreak,
    KeywordContinue,
    KeywordSwitch,
    KeywordCase,
    TypeVoid,
    TypeBoolean,
    TypeInt,
    TypeFloat,
    TypeString,
    TypeChar,
    Equal,
    Assign,
    NotEqual,
    Exclamation,
    LogicalOr,
    Pipe,
    Comment,
    CommentBlock
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
    [[nodiscard]] std::string get_value() const { return value_; }

    friend std::ostream &operator<<(std::ostream &str, const Token &t) {
        str << t.to_string();
        return str;
    }
};

#endif //AGH_KOMPILATORY_TOKEN_H
