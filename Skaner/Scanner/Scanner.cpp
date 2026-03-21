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
    char c = str_.peek();
    return str_.peek() != std::char_traits<char>::eof() ? str_.peek() : '\0';
}

char Scanner::get() {
    const char c = str_.get();
    if (c == '\n') {
        position_.increment_line();
    } else {
        position_.increment_pos();
    }
    return c != std::char_traits<char>::eof() ? c : '\0';
}

Token Scanner::scan() {
    const auto starting_pos  = Position(position_);
    const char c = get();
    if (c == '\0') {
        return Token(TokenType::EndOfFile, "", starting_pos);
    }
    if (c == '+') {
        return Token(TokenType::SignPlus, "+", starting_pos);
    }
    if (c == '-') {
        return Token(TokenType::SignMinus, "-", starting_pos);
    }
    if (c == '*') {
        return Token(TokenType::SignStar, "*", starting_pos);
    }
    if (c == '\\') {
        return Token(TokenType::SignSlash, "/", starting_pos);
    }
    if (c == '(') {
        return Token(TokenType::LeftParen, "(", starting_pos);
    }
    if (c == ')') {
        return Token(TokenType::RightParen, ")", starting_pos);
    }
    if (isspace(c)) {
        std::string res;
        res += c;
        while (isspace(peek())) {
            res += get();
        }
        return Token(TokenType::Whitespace, res, starting_pos);
    }
    if (c >= '0' && c <= '9') {
        std::string res;
        res += c;
        while (!isspace(peek()) && peek() != '\0' && peek() >= '0' && peek() <= '9') {
            res += get();
        }
        return Token(TokenType::NumberInteger, res, starting_pos);
    }
    if (can_be_identifier_body(c) && !(c >= '0' && c <= '9')) {
        std::string res;
        res += c;
        while (!isspace(peek()) && peek() != '\0') {
            if (can_be_identifier_body(peek())) {
                res += get();
            } else {
                break;
            }

        }
        return Token(TokenType::Identifier, res, starting_pos);
    }
    return Token(TokenType::Error, "", starting_pos);
}

