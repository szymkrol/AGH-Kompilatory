//
// Created by Szymon Król on 12.03.2026.
//

#include "../Scanner/Scanner.h"

#include <istream>

#include "../Token.h"

char Scanner::get_non_whitespace() {
    while (true) {
        const char c = str_.get();
        if (c == std::char_traits<char>::eof()) {
            return '\0';
        }
        if (c == '\n') {
            position_.increment_line();
        } else if (isspace(c)) {
            position_.increment_pos();
        } else {
            return c;
        }
    }
}

char Scanner::peek() const {
    if (str_.peek() == std::char_traits<char>::eof()) {
        return '\0';
    }
    return str_.peek();
}


Token Scanner::scan() {
    const char c = get_non_whitespace();
    if (c == '\0') {
        return Token(TokenType::Empty, "", position_);
    }
    if (c == '+') {
        return Token(TokenType::SignPlus, "+", position_);
    }
    if (c == '-') {
        return Token(TokenType::SignMinus, "-", position_);
    }
    if (c == '*') {
        return Token(TokenType::SignStar, "*", position_);
    }
    if (c == '\\') {
        return Token(TokenType::SignSlash, "/", position_);
    }
    if (c == '(') {
        return Token(TokenType::LeftParen, "(", position_);
    }
    if (c == ')') {
        return Token(TokenType::RightParen, ")", position_);
    }
    if (c >= '0' && c <= '9') {
        auto starting_pos  = Position(position_);
        std::string res;
        res += c;
        while (!isspace(peek()) && peek() != '\0' && peek() >= '0' && peek() <= '9') {
            res += get_non_whitespace();
        }
        return Token(TokenType::NumberInteger, res, starting_pos);
    }
    if (can_be_identifier_body(c) && !(c >= '0' && c <= '9')) {
        auto starting_pos  = Position(position_);
        std::string res;
        res += c;
        while (!isspace(peek()) && peek() != '\0') {
            if (can_be_identifier_body(peek())) {
                res += get_non_whitespace();
            } else {
                break;
            }

        }
        return Token(TokenType::Identifier, res, starting_pos);
    }
    return Token(TokenType::Error, "", position_);
}

