#include <fstream>
#include <iostream>

#include "Token.h"
#include "Scanner/Scanner.h"
//
// Created by Szymon Król on 12.03.2026.
//
int main() {
    std::ifstream input_file("../ex.txt");
    Scanner s = Scanner (input_file);
    while (true) {
        Token t = s.scan();
        std::cout << t << '\n';
        if (t.get_type() == TokenType::EndOfFile) {
            break;
        }
    }
    input_file.close();
    return 0;
}