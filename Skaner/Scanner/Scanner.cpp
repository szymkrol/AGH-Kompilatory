//
// Created by Szymon Król on 12.03.2026.
//

#include "../Scanner/Scanner.h"

#include <istream>
#include <ranges>

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

std::string Scanner::read_whitespace() {
    std::string res;
    while (peek() != '\0' && isspace(peek())) {
        res += get();
    }
    return res;
}

std::string Scanner::read_range(const char begin, const char end) {
    std::string res;
    while (peek() != '\0' && peek() >= begin && peek() <= end) {
        res += get();
    }
    return res;
}

std::string Scanner::read_float_after_decimal() {
    std::string res = read_range('0', '9');
    if (peek() == 'e' || peek() == 'E') {
        res += get();
        if (peek() == '-' || peek() == '+') {
            res += get();
        } else {
            res += '+';
        }
        res += read_range('0', '9');
    }
    if (peek() == 'f' || peek() == 'F') {
        res += get();
    }
    return res;
}

std::string Scanner::read_until(const char c) {
    std::string res;
    while (peek() != c) {
        res += get();
    }
    return res;
}

Token Scanner::scan() {
    /*
     * TODO:
     * Add more operators (eg. &, <<, <=, ...)
     * Add comments
     * Add keywords
     * Do all the colouring
     */
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
    if (c == '[') {
        return Token(TokenType::LeftBracket, "[", starting_pos);
    }
    if (c == ']') {
        return Token(TokenType::RightBracket, "]", starting_pos);
    }
    if (c == '{') {
        return Token(TokenType::LeftBrace, "{", starting_pos);
    }
    if (c == '}') {
        return Token(TokenType::RightBrace, "}", starting_pos);
    }
    if (c == ',') {
        return Token(TokenType::Comma, ",", starting_pos);
    }
    if (c == ';') {
        return Token(TokenType::Semicolon, ";", starting_pos);
    }
    if (c == ':') {
        if (peek() == ':') {
            get();
            return Token(TokenType::DoubleColon, "::", starting_pos);
        }
        return Token(TokenType::Colon, ":", starting_pos);
    }
    if (c == '.') {
        if (peek() == '.') {
            get();
            if (peek() == '.') {
                get();
                return Token(TokenType::Ellipsis, "...", starting_pos);
            } else {
                return Token(TokenType::Error, "..", starting_pos);
            }
        } else {
            return Token(TokenType::Dot, ".", starting_pos);
        }
    }

    // Read whitespaces
    if (isspace(c)) {
        return Token(TokenType::Whitespace, c + read_whitespace(), starting_pos);
    }

    // Read numbers
    if (c >= '0' && c <= '9') {
        std::string res;
        res += c;
        if (c == '0') {
            switch (peek()) {
                case 'x':
                case 'X':
                    // Hexadecimal
                    res += get();
                    while (peek() != '\0' && ((peek() >= '0' && peek() <= '9') || (peek() >= 'a' && peek() <= 'f') || (peek() >= 'A' && peek() <= 'F'))) {
                        res += get();
                    }
                    return Token(TokenType::NumberIntegerHex, res, starting_pos);
                    break;
                case 'b':
                case 'B':
                    // Binary
                    res += get();
                    res += read_range('0', '1');
                    return Token(TokenType::NumberIntegerDecimal, res, starting_pos);
                    break;
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                    // Octal
                    res += get();
                    res += read_range('0', '7');
                    return Token(TokenType::NumberIntegerOctal, res, starting_pos);
                    break;
                case '.':
                    // Float
                    res += get();
                    res += read_float_after_decimal();
                    return Token(TokenType::NumberFloat, res, starting_pos);
                    break;
            }
        } else {
            // Decimal or float
            res += read_range('0', '9');
            if (peek() == '.') {
                // Float
                res += get();
                res += read_float_after_decimal();
                return Token(TokenType::NumberFloat, res, starting_pos);
            } else {
                // Decimal
                return Token(TokenType::NumberIntegerDecimal, res, starting_pos);
            }
        }
    }

    // Char and string literals
    if (c == '\'') {
        return Token(TokenType::LiteralCharacter, c + read_until('\'') + get(), starting_pos);
    }
    if (c == '"') {
        return Token(TokenType::LiteralString, c + read_until('"') + get(), starting_pos);
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

